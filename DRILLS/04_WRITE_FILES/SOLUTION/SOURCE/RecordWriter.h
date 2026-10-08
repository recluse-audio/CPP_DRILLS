#pragma once

#include <string>
#include <vector>

#include "Record.h"

std::vector<Record> build_sample_records();
void write_text_file(const std::vector<Record>& records, const std::string& path);
void write_csv_file(const std::vector<Record>& records, const std::string& path);
void write_json_file(const std::vector<Record>& records, const std::string& path);
