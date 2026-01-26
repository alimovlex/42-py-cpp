#include <iostream>

int main(int argc, char** argv)
{
    int i = 0;
    std::cout << "=== Command Quest ===" << std::endl;
    if (argc < 2)
    {
        std::cout << "No arguments provided!" << std::endl;
        std::cout << "Program name: " << *argv << std::endl;
    }
    else
    {
     std::cout << "Program name: " << *argv << std::endl;
     std::cout << "Arguments received: " << argc - 1 << std::endl;
     while(*++argv && i++ < argc)
         std::cout << "Argument " << i << ": " << *argv << std::endl;
    }
    std::cout << "Total arguments: " << argc << std::endl;
     return 0;
}
