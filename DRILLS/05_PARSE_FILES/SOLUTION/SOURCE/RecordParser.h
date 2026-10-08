#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "Record.h"

std::vector<Record> parse_text_file(const std::string& path);
std::vector<Record> parse_csv_file(const std::string& path);
std::vector<Record> parse_json_file(const std::string& path);
bool compare_records(const std::vector<Record>& first, const std::vector<Record>& second);
void write_records(std::ostream& output, const std::string& file_name, const std::vector<Record>& records);
