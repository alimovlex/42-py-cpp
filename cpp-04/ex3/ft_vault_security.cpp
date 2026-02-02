#include <iostream>
#include <fstream>
#include <vector>

int read_file(const std::string &fileName)
{
    std::fstream file;
    std::string line;
    int i = 1;
    file.exceptions(std::ifstream::badbit);

    try
    {
      file.open(fileName);
      try
      {
        while (std::getline(file, line))
          std::cout << line << std::endl;
      }
      catch (const std::ios_base::failure &e)
      {
        std::cout << e.what() << std::endl;
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

int write_file(std::string filename, std::vector<std::string>& array)
{
    std::ofstream file;
    std::string line;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    try
    {
      file.open(filename, std::ios::out);
      try
      {
          for(auto& str: array)
            file << str << std::endl;
      }
      catch (const std::ios_base::failure &e)
      {
        std::cout << e.what() << std::endl;
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

int main()
{
    const std::string extraction_filename = "classified_data.txt";
    const std::string preservation_filename = "security_protocols.txt";
    std::vector<std::string> array = {"[CLASSIFIED] Quantum encryption keys recovered",
        "[CLASSIFIED] Archive integrity: 100%"};
    std::cout << "=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===\n" << std::endl;
    std::cout << "Initiating secure vault access..." << std::endl;
    std::cout << "Vault connection established with failsafe protocols\n" << std::endl;
    write_file(extraction_filename, array);
    std::cout << "SECURE EXTRACTION:" << std::endl;
    read_file(extraction_filename);
    std::cout << std::endl;
    array.clear();
    array.push_back("[CLASSIFIED] New security protocols archived");
    std::cout << "SECURE PRESERVATION:" << std::endl;
    write_file(preservation_filename, array);
    read_file(preservation_filename);
    std::cout << "Vault automatically sealed upon completion\n" << std::endl;
    std::cout << "All vault operations completed with maximum security." << std::endl;
    return 0;
}
