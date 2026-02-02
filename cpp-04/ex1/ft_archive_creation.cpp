#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::string fileName = "new_discovery.txt";
    std::cout << "=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n" << std::endl;
    std::cout << "Initializing new storage unit: " << fileName << std::endl;
    int i = 1;
    std::ofstream file;
    std::string line;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    std::vector<std::string> data = {
        "New quantum algorithm discovered",
        "Efficiency increased by 347%",
        "Archived by Data Archivist trainee"};

    try
    {
      file.open(fileName, std::ios::out);
      std::cout << "RECOVERED DATA:" << std::endl;
      try
      {
        std::cout << "Storage unit created successfully...\n" << std::endl;
        std::cout << "Inscribing preservation data..." << std::endl;

        for (auto& str: data)
        {
            file << "[ENTRY " << i << "] " << str << std::endl;
            std::cout << "[ENTRY " << i++ << "] " << str << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Data inscription complete. Storage unit sealed." << std::endl;
        std::cout << "Archive '" << fileName << "' ready for long-term preservation" << std::endl;
      }
      catch (const std::ios_base::failure &e)
      {
        std::cout << std::endl;
        std::cout << "Data recovery complete. Storage unit disconnected." << std::endl;
      }
      file.close();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << "Error: storage vault not found" << std::endl;
        return 1;
    }

    return 0;
}
