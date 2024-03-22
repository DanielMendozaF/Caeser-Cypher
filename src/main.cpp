#include "../include/utils.hpp"

int main()
{   
    // call function to decrypt cipher text file and output to plain text file
    decrypt_file("cipher.txt", "plaintext.txt");
    return 0;
}