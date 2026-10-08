#include "Wavetable.h"

#include <cmath>
#include <fstream>
#include <iomanip>

std::vector<double> calculate_sine_table(int table_size)
{
    const double pi = 3.14159265358979323846;
    std::vector<double> table;
    for (int index = 0; index < table_size; index++)
    {
        double angle = 2.0 * pi * index / table_size;
        double sample = std::sin(angle);
        table.push_back(sample);
    }
    return table;
}

void write_table_csv(const std::vector<double>& table, const std::string& csv_path)
{
    std::ofstream output(csv_path);
    output << std::setprecision(17);
    output << "index,sample\n";
    for (std::size_t index = 0; index < table.size(); index++)
    {
        output << index << ',' << table[index] << '\n';
    }
}

Wavetable::Wavetable(const std::string& csv_path)
{
    phase = 0.0;

    std::ifstream input(csv_path);
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        std::size_t comma = line.find(',');
        if (comma == std::string::npos)
        {
            continue;
        }
        std::string sample_text = line.substr(comma + 1);
        double sample = std::stod(sample_text);
        samples.push_back(sample);
    }
}

std::vector<double> Wavetable::read_next_samples(double frequency, double sample_rate, int sample_count)
{
    std::vector<double> block;
    double table_size = static_cast<double>(samples.size());
    double increment = frequency * table_size / sample_rate;

    for (int count = 0; count < sample_count; count++)
    {
        std::size_t lower_index = static_cast<std::size_t>(phase);
        std::size_t upper_index = (lower_index + 1) % samples.size();
        double fraction = phase - static_cast<double>(lower_index);

        double lower_sample = samples[lower_index];
        double upper_sample = samples[upper_index];
        double sample = lower_sample + (upper_sample - lower_sample) * fraction;
        block.push_back(sample);

        phase = phase + increment;
        if (phase >= table_size)
        {
            phase = phase - table_size;
        }
    }
    return block;
}

const std::vector<double>& Wavetable::get_samples() const
{
    return samples;
}
