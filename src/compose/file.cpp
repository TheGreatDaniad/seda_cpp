
#include <iostream>
#include <wav.h>

void saveToWav(std::vector<float> samples, int sampleRate, std::string name)
{

    AudioFile<float> a;
    a.setNumChannels(1);
    a.setNumSamplesPerChannel(44100);
    a.samples[0] = samples;
    a.save(name, AudioFileFormat::Wave);
}