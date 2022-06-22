#include "fft.h"


Complex FFT::getFFT(int k, int* data , int N){
    Complex fft(0,0), multiplier(0,0);
    int odd[N/2], even[N/2];

    multiplier.polar(1,-k*2*PI/N);

    if (N == 3)
    {
        N = 2;
    }

    if (N == 2)
    {
        fft.setReal( data[0] + data[1]*multiplier.real());
        fft.setImag(data[1]*multiplier.imag());


        return fft;
    }

    for (int i = 0; i < N/2; i++)
    {
        odd[i]   = data[2*i + 1];
        even[i]  = data[2*i];
    }
    
    
    return ( getFFT( k, even, N/2 ) + ( getFFT( k, odd, N/2 ) *  multiplier ) ) ;

    

}

Complex FFT::getFFT(int k){

    getFFT(k, data , N);

}

float FFT::getAmplitude(int k){

    return getFFT(k, data , N).modulus()/N;

}

float FFT::getPhase(int k){

    return getFFT(k, data , N).phase();

}

void FFT::getPeaks(int* peaks, int no_of_peaks){
    float amplitude[N/2],temp;
    int   top_values[N/2],temp_int;


    for (int i = 0; i < N/2; i++)
    {
        amplitude[i] = getAmplitude(i);
        top_values[i] = i;
    }
    
     for (int i = 0; i < N/2 - 1; i++){
        for (int j = 0; j < N/2 - i - 1; j++)
            if (amplitude[j] < amplitude[j + 1]){

                temp = amplitude[j];
                amplitude[j] = amplitude[j + 1];
                amplitude[j+ 1] = temp;

                temp_int   = top_values[j];
                top_values[j] = top_values[j + 1];
                top_values[j+ 1] = temp_int;
                
            }


     }

     for (int i = 0; i < N/2 && i < no_of_peaks; i++)
     {
        peaks[i] = top_values[i];
     }
     
     

        
    



}