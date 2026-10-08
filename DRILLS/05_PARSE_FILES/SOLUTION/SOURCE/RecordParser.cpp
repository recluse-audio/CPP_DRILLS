#include "RecordParser.h"

#include <fstream>
#include <sstream>

std::vector<Record> parse_text_file(const std::string& path)
{
    std::vector<Record> records;
    std::ifstream input(path);
    std::string name;
    int number = 0;
    while (input >> name >> number)
    {
        Record record{name, number};
        records.push_back(record);
    }
    return records;
}

std::vector<Record> parse_csv_file(const std::string& path)
{
    std::vector<Record> records;
    std::ifstream input(path);
    std::string line;

    std::getline(input, line);
    while (std::getline(input, line))
    {
        std::size_t comma = line.find(',');
        if (comma == std::string::npos)
        {
            continue;
        }
        std::string name = line.substr(0, comma);
        std::string number_text = line.substr(comma + 1);
        int number = std::stoi(number_text);
        Record record{name, number};
        records.push_back(record);
    }
    return records;
}

std::vector<Record> parse_json_file(const std::string& path)
{
    std::vector<Record> records;
    std::ifstream input(path);
    std::ostringstream buffer;
    buffer << input.rdbuf();
    std::string contents = buffer.str();

    std::size_t position = 0;
    while (true)
    {
        std::size_t name_key = contents.find("\"name\"", position);
        if (name_key == std::string::npos)
        {
            break;
        }
        std::size_t name_colon = contents.find(':', name_key);
        std::size_t open_quote = contents.find('"', name_colon);
        std::size_t close_quote = contents.find('"', open_quote + 1);
        std::string name = contents.substr(open_quote + 1, close_quote - open_quote - 1);

        std::size_t number_key = contents.find("\"number\"", close_quote);
        std::size_t number_colon = contents.find(':', number_key);
        std::string number_text = contents.substr(number_colon + 1);
        int number = std::stoi(number_text);

        Record record{name, number};
        records.push_back(record);
        position = number_colon;
    }
    return records;
}

bool compare_records(const std::vector<Record>& first, const std::vector<Record>& second)
{
    if (first.size() != second.size())
    {
        return false;
    }
    for (std::size_t index = 0; index < first.size(); index++)
    {
        if (first[index].name != second[index].name)
        {
            return false;
        }
        if (first[index].number != second[index].number)
        {
            return false;
        }
    }
    return true;
}

void write_records(std::ostream& output, const std::string& file_name, const std::vector<Record>& records)
{
    for (const Record& record : records)
    {
        output << file_name << ' ' << record.name << ' ' << record.number << '\n';
    }
}
