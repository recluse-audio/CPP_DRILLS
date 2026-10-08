#include "WavetableCallback.h"

#include <vector>

WavetableCallback::WavetableCallback(Wavetable& wavetable_to_read)
    : wavetable(wavetable_to_read)
{
    sample_rate = 48000.0;
}

void WavetableCallback::audioDeviceAboutToStart(juce::AudioIODevice* device)
{
    sample_rate = device->getCurrentSampleRate();
}

void WavetableCallback::audioDeviceIOCallbackWithContext(const float* const* input_channel_data,
                                                         int input_channel_count,
                                                         float* const* output_channel_data,
                                                         int output_channel_count,
                                                         int sample_count,
                                                         const juce::AudioIODeviceCallbackContext& context)
{
    juce::ignoreUnused(input_channel_data, input_channel_count, context);

    double frequency = 440.0;
    double gain = 0.2;
    std::vector<double> block = wavetable.read_next_samples(frequency, sample_rate, sample_count);

    for (int channel = 0; channel < output_channel_count; channel++)
    {
        float* output = output_channel_data[channel];
        if (output == nullptr)
        {
            continue;
        }
        for (int index = 0; index < sample_count; index++)
        {
            double sample = block[static_cast<std::size_t>(index)] * gain;
            output[index] = static_cast<float>(sample);
        }
    }
}

void WavetableCallback::audioDeviceStopped()
{
}
