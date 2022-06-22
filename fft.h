#ifndef FFT_H
#define FFT_H
#include "complex.h"
class FFT
{
private:
    float fs;
    int N;
    int* data;
    Complex getFFT(int k, int* data , int N);

public:
    FFT(int* data,int N, int fs): data(data), N(N), fs(fs){};
    ~FFT() = default;
    Complex getFFT(int k);
    float getAmplitude(int k);
    float getPhase(int k);
    void getPeaks(int* peaks, int no_of_peaks);
};


#endif