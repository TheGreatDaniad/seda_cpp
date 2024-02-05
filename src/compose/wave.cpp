#include <iostream>
#include <math.h>
#include <wav.h>
#include <algorithm>
#include "./compose.h"

std::vector<float> generateSineWave(float sampleRate, float frequency, float duration)
{
    std::vector<float> result;
    int totalSamples = static_cast<int>(sampleRate * duration);
    for (int i = 0; i < totalSamples; i++)
    {
        float time = static_cast<float>(i) / sampleRate;
        float value = std::sin(2.0f * M_PI * frequency * time);
        result.push_back(value / 2);
    }
    return result;
}

std::vector<float> applyTimeFunction(std::vector<float> input, const std::vector<float> &timeFunction)
{
    std::vector<float> output;
    auto tfLen = timeFunction.size();
    auto inputLen = input.size();
    output.reserve(inputLen);

    for (size_t i = 0; i < inputLen; ++i)
    {
        double proportion = static_cast<double>(i) / (inputLen - 1);
        double tfPosition = proportion * (tfLen - 1);
        size_t indexLower = static_cast<size_t>(tfPosition);
        size_t indexUpper = std::min(static_cast<size_t>(indexLower + 1), tfLen - 1);
        double fraction = tfPosition - indexLower;
        double tfValue = timeFunction[indexLower] * (1 - fraction) + timeFunction[indexUpper] * fraction;
        output.push_back(input[i] * tfValue);
    }

    return output;
}
