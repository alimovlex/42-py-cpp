#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string lost_filename = "lost_archive.txt";
    std::string classified_filename = "classified_vault.txt";
    std::string standard_filename = "standard_archive.txt";
    std::cout << "=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===\n" << std::endl;
    std::fstream file;
    std::string line;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
      std::cout << "CRISIS ALERT: Attempting access to ''" << lost_filename << "...\n";
      file.open(lost_filename);
        while (std::getline(file, line))
          std::cout << line << std::endl;
        file.close();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cout << "RESPONSE: Archive not found in storage matrix" << std::endl;
    }

    std::cout << "STATUS: Crisis handled, system stable\n" << std::endl;
    line.clear();
    try
    {
        std::cout << "CRISIS ALERT: Attempting access to '" << classified_filename << "'...\n";
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file.open(classified_filename);
            while (std::getline(file, line))
                std::cout << line << std::endl;
        file.close();
    }
    catch (const std::ios_base::failure &)
    {
        std::cout << "RESPONSE: Security protocols deny access\n" << std::endl;
    }

    std::cout << "STATUS: Crisis handled, system stable\n" << std::endl;
    line.clear();
    try
    {
        std::cout << "ROUTINE ACCESS: Attempting access to '" << standard_filename << "'...\n";
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file.open(standard_filename);
            while (std::getline(file, line))
                std::cout << line << std::endl;
    }
    catch (const std::ios_base::failure &)
    {
        std::cout << "RESPONSE: Security protocols deny access\n" << std::endl;
    }

    std::cout << "SUCCESS: Archive recovered - " << std::endl;
    std::cout << "STATUS: Normal operations resumed\n" << std::endl;
    std::cout << "All crisis scenarios handled successfully. Archives secure." << std::endl;

    return 0;
}
