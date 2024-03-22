#include "../include/utils.hpp"

std::string algorithm(const std::string &line, int shift)
{
    std::string original = line;
    for (size_t i = 0; i < original.length(); i++)
    {
        char &c = original[i];
        if (c >= 'A' && c <= 'Z')
        {
            int val = c - 'A';
            val = (val - shift + 26) % 26;
            c = 'A' + val;
        }
        else if (c >= 'a' && c <= 'z')
        {
            int val = c - 'a';
            val = (val - shift + 26) % 26;
            c = 'a' + val;
        }
    }
    return original;
}

void decrypt_file(const std::string &iFile, const std::string &oFile)
{
    std::ifstream inputFile(iFile);
    std::ofstream outputFile(oFile);

    if (inputFile.is_open())
    {
        std::string line;
        while(getline(inputFile, line))
        {
            for(int shift = 1; shift < 26; shift++)
            {
                std::string original = algorithm(line, shift);
                outputFile << "Shift is: " << shift << std::endl << original << std::endl;
            }
        }
        inputFile.close();
        outputFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file\n";
    }
}