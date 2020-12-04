#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

// int main()
// {
//     std::ifstream Password {"password.txt"};        // open input txt file
//     std::string Line;                               // grab the password from txt file
//     char GarbageLine;                               // filters uncessary txt line info
//     char GarbageLine2;                              // filters uncessary txt line info
//     char Letter;                                    // stores the letter needed in the password  
//     int MinRequired{};                              // stores min required amount of letter
//     int MaxRequired{};                              // stores max required amount of letter
//     int LetterCounter{};                            // counts letter reoccurence
//     int Answer{};                                   // increments when a password passes

//     try
//     {
//         if (!Password) {
//             throw ("Error: Could not open file."); 
//         }
//         while (Password >> MinRequired >> GarbageLine >> MaxRequired >> Letter >> GarbageLine2 >> Line) {
//             for (auto c = 0; c < Line.size(); ++c) {
//                 if (Line[c] == Letter) {
//                     ++LetterCounter;
//                 }
//             }
//             if (LetterCounter >= MinRequired && LetterCounter <= MaxRequired) {
//                 ++Answer;
//                 LetterCounter = 0;
//             }
//             else {
//                 LetterCounter = 0;
//             }
//         }
//         std::cout << "The number of valid passwords are: " << Answer << std::endl;
//     }

//     catch(const std::exception& error)
//     {
//         std::cerr << error.what() << '\n';
//     }

//     Password.close();
//     return 0;
    
// }

// int main()                                          // 2nd half of the problem source code
// {
//     time_t start, end;
//     time(&start);

//     std::ifstream Password {"password.txt"};        // open input txt file
//     std::string Line;                               // grab the password from txt file
//     char GarbageLine;                               // filters uncessary txt line info
//     char GarbageLine2;                              // filters uncessary txt line info
//     char Letter;                                    // stores the letter needed in the password  
//     int Index1{};                                   // stores min required amount of letter
//     int Index2{};                                   // stores max required amount of letter
//     int Answer{};                                   // increments when a password passes

//     try
//     {
//         if (!Password) {
//             throw ("Error: Could not open file."); 
//         }
//         while (Password >> Index1 >> GarbageLine >> Index2 >> Letter >> GarbageLine2 >> Line) {
            
//             if (Letter == Line.at(Index1-1) && Letter != Line.at(Index2-1)) {
//                 ++Answer;
//             }
//             else if (Letter == Line.at(Index2-1) && Letter != Line.at(Index1-1)) {
//                 ++Answer;
//             }
//         }
//         std::cout << "\nThe number of valid passwords are: " << Answer << std::endl;
//     }
    
//     catch(const std::exception& error)
//     {
//         std::cerr << error.what() << '\n';
//     }

//     Password.close();
//     time(&end);
//     double time_taken = double(end - start);
//     std::cout << "\nTime taken by program is: " << std::fixed << time_taken << std::setprecision(10);
//     std::cout << " sec " << std::endl;
//     std::cin.get();
//     return 0;
    
// }

int main()                                          // 2nd half of the problem source code
{
    std::ifstream Password {"password.txt"};        // open input txt file
    std::string Line;                               // grab the password from txt file
    char GarbageLine;                               // filters uncessary txt line info
    char GarbageLine2;                              // filters uncessary txt line info
    char Letter;                                    // stores the letter needed in the password  
    int Index1{};                                   // stores min required amount of letter
    int Index2{};                                   // stores max required amount of letter
    int Answer{};                                   // increments when a password passes


    while (Password >> Index1 >> GarbageLine >> Index2 >> Letter >> GarbageLine2 >> Line) {
        
        if (Letter == Line.at(Index1-1) && Letter != Line.at(Index2-1)) {
            ++Answer;
        }
        else if (Letter == Line.at(Index2-1) && Letter != Line.at(Index1-1)) {
            ++Answer;
        }
    }
    std::cout << "\nThe number of valid passwords are: " << Answer << std::endl;
    Password.close();

    std::cin.get();
    return 0;
    
}