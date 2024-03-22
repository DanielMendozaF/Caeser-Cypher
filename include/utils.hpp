#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <fstream>
#include <iostream>

std::string algorithm(const std::string &line, int shift);
void decrypt_file(const std::string &iFile, const std::string &oFile);

#endif