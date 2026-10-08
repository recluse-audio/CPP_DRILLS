#pragma once

#include <juce_audio_devices/juce_audio_devices.h>

#include "Wavetable.h"

// PlayWavetable.cpp passes its address to juce::AudioDeviceManager::addAudioCallback()
// audio device thread calls audioDeviceIOCallbackWithContext() once per block
class WavetableCallback final : public juce::AudioIODeviceCallback
{
public:
    explicit WavetableCallback(Wavetable& wavetable_to_read);

    void audioDeviceAboutToStart(juce::AudioIODevice* device) override;
    void audioDeviceIOCallbackWithContext(const float* const* input_channel_data,
                                          int input_channel_count,
                                          float* const* output_channel_data,
                                          int output_channel_count,
                                          int sample_count,
                                          const juce::AudioIODeviceCallbackContext& context) override;
    void audioDeviceStopped() override;

private:
    Wavetable& wavetable;
    double sample_rate;
};
