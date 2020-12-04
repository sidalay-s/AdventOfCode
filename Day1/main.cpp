#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream Expenses {"Expenses.txt"};    // txt file containing the expense numbers
    std::vector <int> AllExpenses;              // container to collect & store each expense number
    int NumLine{};                              // grabs the number from txt file to push into vector
    int Product{};                              // stores the value of the three numbers that multiply to 2020
    int Sum{2020};                              // stores the Sum that our three expenses need to add up to

    try
    {
        if (!Expenses)
        {
            throw ("File could not be found.");
        }
        while (Expenses >> NumLine)
        {
            AllExpenses.push_back(NumLine);
        }
        for (auto &i:AllExpenses)       // Loop through vectors to get 1st,2nd,3rd 
        {                               // values to find sum(2020) and product
            for (auto &c:AllExpenses)   
            {
                for (auto &z:AllExpenses)
                {
                    if (i + c + z == Sum)
                    {
                        Product = i * c * z;

                        std::cout << i << " + " << c << " + " 
                                    << z << " = " << Sum << std::endl;
                        std::cout << i << " * " << c << " * " 
                                    << z << " = " << Product << std::endl;
                    }
                }
            }
        }
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Expenses.close();
    std::cin.get();
    
    return 0;
}