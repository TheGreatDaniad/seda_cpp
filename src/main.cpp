#include <iostream>
#include "./compose/compose.h"
int main()
{

    TimeFunction tv = {0.0, 0.5, 1.0, 0.6, 0};
    SoundComposition sc;
    sc.sampleRate = 44100;

    SoundHarmonic h1 = {440.0f, tv};
    SoundHarmonic h2 = {880.0f, tv};
    SoundHarmonic h3 = {330.0f, tv};

    sc.harmonics.push_back(h1);
    sc.harmonics.push_back(h2);
    sc.harmonics.push_back(h3);
    
    auto wave = sc.compose(10);

    saveToWav(wave, 44100, "output.wav");
}