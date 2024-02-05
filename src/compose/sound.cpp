#include <iostream>
#include <algorithm>

#include "./compose.h"

std::vector<float> SoundComposition::compose(float duration)
{
    std::vector<float> sound;
    for (int i = 0; i < harmonics.size(); i++)
    {
        std::cout << i;
        auto wav = generateSineWave(sampleRate, harmonics[i].freq, duration);
        wav = applyTimeFunction(wav, harmonics[i].timeFunction);
        if (i == 0)
        {
            sound = wav;
            continue;
        }
        for (int j = 0; j < sound.size(); j++)
        {
            sound[j] += wav[j];
        }
        auto maxIdx = std::max_element(sound.begin(), sound.end());
        auto max = *maxIdx;
        if (max > 1)
        {
            for (int j = 0; j < sound.size(); j++)
            {
                sound[j] /= max;
            }
        }
    }
    std::cout << sound.size();
    return sound;
}