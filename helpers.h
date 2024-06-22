#pragma once
#include <string>

// checks if a string is considered a valid filename
bool valid_input(const std::string& input);

// creates a file in the directory of the program
void create_file(const std::string& name);

// read a specified line of a file in the directory of the program
void read_line(const int line, const std::string& file);

// update a line of a file to specified string in the directy of the program
void update_line(const int line, const std::string& file, const std::string& text);

// delete a file in the same directory as the program
void delete_file(const std::string& file);