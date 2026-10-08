#include <iostream>
#include <string>
#include <vector>

#include "RecordWriter.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: write_files_build <dir>\n";
        return 1;
    }

    std::string directory = argv[1];
    std::vector<Record> records = build_sample_records();

    std::string text_path = directory + "/records.txt";
    std::string csv_path = directory + "/records.csv";
    std::string json_path = directory + "/records.json";

    write_text_file(records, text_path);
    write_csv_file(records, csv_path);
    write_json_file(records, json_path);
    return 0;
}
