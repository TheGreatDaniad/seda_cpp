#ifndef COMPOSE_H
#define COMPOSE_H

#include <iostream>

typedef std::vector<float> TimeFunction;
std::vector<float> generateSineWave(float sampleRate, float frequency, float duration);
void saveToWav(std::vector<float> samples, int sampleRate, std::string name);
std::vector<float> applyTimeFunction(std::vector<float> input, const std::vector<float> &timeFunction);

typedef struct SoundHarmonic
{
    float freq;
    TimeFunction timeFunction;
};

class SoundComposition
{
public:
    std::vector<SoundHarmonic> harmonics;
    float sampleRate;
    std::vector<float> compose(float duration);
};

#endif
