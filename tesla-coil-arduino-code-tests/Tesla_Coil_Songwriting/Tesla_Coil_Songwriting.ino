#include "pitches.h"
#include "arduinoFFT.h"
arduinoFFT FFT = arduinoFFT();

const uint16_t samples = 64;
const double signalFrequency = 1000;
const double samplingFrequency = 5000;
const uint8_t amplitude = 100;
/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
double vReal[samples];
double vImag[samples];

#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03


void setup()
{
}

void loop() {
  int frequency = fft();
  tone(2, frequency);
}

int fft() {
   
    /*SAMPLING*/
    for(int i=0; i<samples; i++)
    {
        int microseconds = micros();    //Overflows after around 70 minutes!
     
        vReal[i] = analogRead(0);
        vImag[i] = 0;
     
        while(micros() < (microseconds + sampling_period_us)){
        }
    }
 
    /*FFT*/
    FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, samples, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, samples);
    double peak = FFT.MajorPeak(vReal, samples, samplingFrequency);
 
    /*PRINT RESULTS*/
    return (peak);     //Print out what frequency is the most dominant.
 

}
