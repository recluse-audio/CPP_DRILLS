#include <iostream>
#include <string>
#include <vector>

#include "RecordParser.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: parse_files_build <dir>\n";
        return 1;
    }

    std::string directory = argv[1];
    std::string text_path = directory + "/records.txt";
    std::string csv_path = directory + "/records.csv";
    std::string json_path = directory + "/records.json";

    std::vector<Record> text_records = parse_text_file(text_path);
    std::vector<Record> csv_records = parse_csv_file(csv_path);
    std::vector<Record> json_records = parse_json_file(json_path);

    write_records(std::cout, "records.txt", text_records);
    write_records(std::cout, "records.csv", csv_records);
    write_records(std::cout, "records.json", json_records);

    bool csv_matches = compare_records(text_records, csv_records);
    bool json_matches = compare_records(text_records, json_records);
    if (!csv_matches || !json_matches)
    {
        std::cerr << "error: the three record lists differ\n";
        return 1;
    }
    return 0;
}
