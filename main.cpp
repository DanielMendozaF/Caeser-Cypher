#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function for decryption algorithm given a string line and shift value
string algorithm(const string& line, int shift)
{
    string original = line;
    // for loop to iterate through line characters
    for(int i = 0; i < original.length(); i++)
    {
        char& c = original[i];
        // condition if character value is uppercase 
        if (c >= 'A' && c <= 'Z')
        {
            // algorithm used to shift character value by shift value to the LEFT
            int val = c - 'A';
            val = (val - shift + 26) % 26;
            c = 'A' + val;
        }
        // condition if character value is lowercase
        else if (c >= 'a' && c <= 'z')
        {
            // algorithm used to shift character value by shift value to the LEFT
            int val = c - 'a';
            val = (val - shift + 26) % 26;
            c = 'a' + val;
        }
    }
    return original;
}

// function to decrypt input file and output the plain text to an output file 
void decryptFile(const string& iFile, const string& oFile)
{
    ifstream inputFile(iFile);
    ofstream outputFile(oFile);

    if (inputFile.is_open())
    {
        string line;
        // while loop to read each line of the input file 
        while(getline(inputFile, line))
        {
            // for loop to implement shift values 1-25 into the decryption algorithm function
            for (int shift = 1; shift < 26; shift++)
            {
                string original = algorithm(line, shift);

                // output each shift iteration with shift value and modified string
                outputFile << "Shift is: " << shift << endl << original << endl;
            }
        }
        // close files
        inputFile.close();
        outputFile.close();
    }
    // condition if file does not open
    else
    {
        cout << "Error opening file" << endl;
        return;
    }
}

int main()
{   
    // call function to decrypt cipher text file and output to plain text file
    decryptFile("cipher.txt", "plaintext.txt");
    return 0;
}