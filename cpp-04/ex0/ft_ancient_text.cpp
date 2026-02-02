#include <exception>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
  const std::string fileName = "ancient_fragment.txt";
  std::cout << "=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===\n" << std::endl;
  std::cout << "Accessing Storage Vault: " << fileName << std::endl;
  std::cout << "Connection established...\n" << std::endl;

  std::fstream file;
  std::string line;
  int i = 1;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    file.open(fileName);
    std::cout << "RECOVERED DATA:" << std::endl;
    try
    {
      while (std::getline(file, line))
      {
        std::cout << "[FRAGMENT " << i << "] " << line << std::endl;
        i++;
      }
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
