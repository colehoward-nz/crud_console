#include "helpers.h"
#include <algorithm> // std::all_of (checks if characters from x,y satisfy z)
#include <iostream>
#include <fstream>   // file stream for read/write from/to files
#include <cctype>    // std::isalnum (is alphanumeric)
#include <cstdio>    // std::remove
#include <vector>



bool valid_input(const std::string& input)
{
    return std::all_of(input.begin(), input.end(), 
    [](const char c)
    {
      return std::isalnum(c) || c == '.' || c == '_';  
    });
}


void create_file(const std::string& name)
{
    if (!valid_input(name))
    {
        std::cout << "MUNKE_CRUD_CONSOLE illinformed name" << std::endl;
        return;
    }
    
    std::ifstream file (name);
    if (file)
    {    
        std::cout << "MUNKE_CRUD_CONSOLE file already exists" << std::endl;
        file.close();
        return;
    }

    std::ofstream new_file (name);
    std::cout << "MUNKE_CRUD_CONSOLE file created" << std::endl;
    file.close();
    return;
}


void read_line(const int line, const std::string& file)
{
    if (!valid_input(file))
    {
        std::cout << "MUNKE_CRUD_CONSOLE illinformed name" << std::endl;
        return;
    }
        
    std::ifstream checkf (file);
    if(checkf)
    {
        int count = 0;
        std::string current_line;
        while (std::getline(checkf, current_line))
        {
            count++;
            if (count == line)
            {
                std::cout << "MUNKE_CRUD_CONSOLE found line" << std::endl << current_line << std::endl;
                checkf.close();
                return;
            }
        }
        std::cout << "MUNKE_CRUD_CONSOLE ran out of lines" << std::endl;
        checkf.close();
        return;
    }
    std::cout << "MUNKE_CRUD_CONSOLE file not found" << std::endl;
}


void update_line(int line, const std::string& file, const std::string& text)
{
    if (!valid_input(file))
    {
        std::cout << "MUNKE_CRUD_CONSOLE illinformed name" << std::endl;
        return;
    }

    std::ifstream checkf (file);
    if (!checkf)
    {
        std::cout << "MUNKE_CRUD_CONSOLE file not found" << std::endl;
        return;
    }

    // don't kill me - gotta be a better way then just coping the entire file lol
    std::vector<std::string> lines;
    std::string temp;
    while (std::getline(checkf, temp))
    {
        lines.push_back(temp);
    }

    checkf.close();

    if (line <= 0 || line > lines.size())
    {
        std::cout << "MUNKE_CRUD_CONSOLE ran out of lines";
        checkf.close();
        return;
    }

    lines[line-1] = text;

    std::ofstream outputf (file);
    if (!outputf)
    {
        std::cout << "MUNKE_CRUD_CONSOLE file not found";
        outputf.close();
        return;
    }

    for (const auto& line : lines)
    {
        outputf << line << std::endl;
    }

    std::cout << "MUNKE_CRUD_CONSOLE replaced line";
    outputf.close();
    return;
}


void delete_file(const std::string& file)
{
    if (!valid_input(file))
    {
        std::cout << "MUNKE_CRUD_CONSOLE illinformed name" << std::endl;
        return;
    }

    std::ifstream checkf (file);
    if (!checkf)
    {
        std::cout << "MUNKE_CRUD_CONSOLE file not found" << std::endl;
        return;
    }

    if (!std::remove(file.c_str()))
    {
        std::cout << "MUNKE_CRUD_CONSOLE file deleted" << std::endl;
        checkf.close();
        return;
    }

    std::cout << "MUNKE_CRUD_CONSOLE could not delete file" << std::endl;
    checkf.close();
}