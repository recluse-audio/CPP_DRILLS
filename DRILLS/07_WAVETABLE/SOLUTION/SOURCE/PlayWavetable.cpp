#include <iostream>
#include <string>
#include <vector>

#include <juce_audio_devices/juce_audio_devices.h>

#include "Wavetable.h"
#include "WavetableCallback.h"

int main()
{
    juce::ScopedJuceInitialiser_GUI juce_initialiser;

    std::string csv_path = "BUILD/sine_table.csv";
    std::vector<double> table = calculate_sine_table(512);
    write_table_csv(table, csv_path);
    Wavetable wavetable(csv_path);

    juce::AudioDeviceManager device_manager;
    juce::String error = device_manager.initialiseWithDefaultDevices(0, 2);
    if (error.isNotEmpty())
    {
        std::cerr << "error: " << error << '\n';
        return 1;
    }

    WavetableCallback callback(wavetable);
    device_manager.addAudioCallback(&callback);
    juce::Thread::sleep(2000);
    device_manager.removeAudioCallback(&callback);
    return 0;
}
