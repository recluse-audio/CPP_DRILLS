#include "RecordWriter.h"

#include <fstream>

std::vector<Record> build_sample_records()
{
    std::vector<Record> records;
    Record alice{"alice", 3};
    Record bob{"bob", 5};
    Record carol{"carol", 8};
    records.push_back(alice);
    records.push_back(bob);
    records.push_back(carol);
    return records;
}

void write_text_file(const std::vector<Record>& records, const std::string& path)
{
    std::ofstream output(path);
    for (const Record& record : records)
    {
        output << record.name << ' ' << record.number << '\n';
    }
}

void write_csv_file(const std::vector<Record>& records, const std::string& path)
{
    std::ofstream output(path);
    output << "name,number\n";
    for (const Record& record : records)
    {
        output << record.name << ',' << record.number << '\n';
    }
}

void write_json_file(const std::vector<Record>& records, const std::string& path)
{
    std::ofstream output(path);
    output << "[\n";
    for (std::size_t index = 0; index < records.size(); index++)
    {
        const Record& record = records[index];
        output << "    {\n";
        output << "        \"name\": \"" << record.name << "\",\n";
        output << "        \"number\": " << record.number << "\n";
        output << "    }";
        if (index + 1 < records.size())
        {
            output << ",";
        }
        output << "\n";
    }
    output << "]";
}
