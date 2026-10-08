#pragma once

#include <string>
#include <vector>

std::vector<double> calculate_sine_table(int table_size);
void write_table_csv(const std::vector<double>& table, const std::string& csv_path);

// PlayWavetable.cpp constructs one from .csv that write_table_csv() wrote
// WavetableCallback::audioDeviceIOCallbackWithContext() calls read_next_samples() once per audio block
class Wavetable
{
public:
    explicit Wavetable(const std::string& csv_path);

    std::vector<double> read_next_samples(double frequency, double sample_rate, int sample_count);
    const std::vector<double>& get_samples() const;

private:
    std::vector<double> samples;
    double phase;
};
