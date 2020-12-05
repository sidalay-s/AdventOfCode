#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* 
- Determine how many passports need to be verified
- Store the passport credentials in a vector of strings
- Identify which key values are being stored
- Determine if key ids (byr iyr eyr hgt hcl ecl pid *cid) are present *(cid is optional)*
- Count the number of valid passports
- Use forloop with if (.at(i) == :) and then start reading from 3 values before to get the key
*/


void GetCredentials(std::vector <std::string>&, std::ifstream&);
int PassportScanner(const std::vector <std::string>&);

int main()
{
    std::ifstream BatchFile {"credentials.txt"};
    std::vector <std::string> Credentials;

    GetCredentials(Credentials, BatchFile);
    std::cout << "\nNumber of valid passports: " << PassportScanner(Credentials) << std::endl;
    BatchFile.close();
}

void GetCredentials(std::vector <std::string>& Cred, std::ifstream& File)
{
    std::string Passports{};  // Stores the filtered KEY IDs and gets stored in the vector 'Cred'
    std::string LineParser; // Grabs file line to filter KEY IDs
    int IDsize{3};

    // Use this loop to store the appropriate credentials & count #of passports
    while (std::getline(File, LineParser))
    { 
        for (auto i = 0; i < LineParser.size(); ++i)
        {
            if (LineParser.at(i) == ':')
            {
                for (auto c = (i - IDsize); c < i; ++c)
                {
                    Passports += LineParser.at(c);
                }
                Passports += " ";
            }
        }
        if (LineParser == "" || File.eof())
        {
            Cred.push_back(Passports);
            Passports.clear();
        }
    }   
}

int PassportScanner(const std::vector <std::string>& Cred)
{
    int ValidCounter{0};
    int NumOfIds{0};
    int IsValid{7};
    int Reset{0};

    std::vector <std::string> KeyNames
        {{"byr"},
         {"iyr"},
         {"eyr"},
         {"hgt"},
         {"hcl"},
         {"ecl"},
         {"pid"}};

    for (auto i = 0; i < Cred.size(); ++i)
    {
        NumOfIds = Reset;
        for (auto c = 0; c < KeyNames.size(); ++c)
        {
            if (Cred.at(i).find(KeyNames.at(c)) != std::string::npos)
            {
                ++NumOfIds;
            }
            if (NumOfIds == IsValid)
            {
                ++ValidCounter;
                NumOfIds = Reset;
            }
        }
    }
    return ValidCounter;
}