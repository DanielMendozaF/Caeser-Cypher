#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{   
    // Open cipher text file to read and plain text file to write to
    ifstream inputFile("cipher.txt");
    ofstream outputFile("plaintext.txt");

    if (inputFile.is_open())
    {
        string line;

        //reads each line of cipher text file
        while(getline(inputFile, line))
        {   
            // for loop to attempt 1-25 shift keys
            for(int key = 1; key < 26; key++)
            {   
                // variable to modify original line only
                string original = line;

                // for loop to iterate through line
                for(int i = 0; i < original.length(); i++)
                {
                    char& c = original[i];
                    // condition to check if char is uppercase
                    if (c >= 'A' && c <= 'Z')
                    {   
                        // decryption algorithm that shifts char value to the LEFT 
                        int val = c - 'A';
                        val = (val - key + 26) % 26;
                        c = 'A' + val;
                    }
                    // condition to check if char is lowercase
                    else if ( c >= 'a' && c <= 'z')
                    {
                        // decryption algorithm that shifts char value to the LEFT
                        int val = c - 'a';
                        val = (val - key + 26) % 26;
                        c = 'a' + val;      
                    }
                }
                // outputs modified line with current shift to output file
                outputFile << "Shift is: " << key << endl << original << endl;
            }
        }
        // close files 
        inputFile.close();
        outputFile.close();
    }

    // condition if there is an issue with opening the inputFile
    else
    {
        cout << "Error opening file" << endl;
    }

    return 0;
}