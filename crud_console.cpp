#include <iostream>
#include <unistd.h>
#include "helpers.cpp"

/*          todo for CRUD file I/O
    X create a file with specified name.
    X read a specified line.
    - update a specified line to new content.
    X delete file with specified name.         */

void menu()
{
    std::cout << std::endl<<std::endl<<"MUNKE_CRUD_CONSOLE" << std::endl;
    std::cout << "Enter 0 to CREATE" << std::endl;
    std::cout << "Enter 1 to READ" << std::endl;
    std::cout << "Enter 2 to UPDATE" << std::endl;
    std::cout << "Enter 3 to DELETE" << std::endl<<std::endl<<std::endl;
}

int main()
{   
    std::string filename;
    int line;
    
    int cont = 1;
    int option = 0;
    while (cont)
    {
        menu();
        std::cin >> option;
        switch (option)
        {
            case 0:
                std::cout << "Enter a filename: ";
                std::cin >> filename;
                create_file(filename);
                break;
            case 1:
                std::cout << "Enter a filename: ";
                std::cin >> filename;
                std::cout << "Enter a line number: ";
                std::cin >> line;
                read_line(line, filename);
                break;
            case 3:
                std::cout << "Enter a filename: ";
                std::cin >> filename;
                delete_file(filename);
                break;
        }

        std::cout << std::endl << "To exit, enter 0 and 1 to continue: ";
        std::cin >> cont;
    }
}