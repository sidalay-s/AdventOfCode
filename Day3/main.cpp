#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream trees{"trees.txt"};
    std::vector <std::string> TreesContainer;
    std::string FirstLine;
    std::string Line;
    int SpaceCounter{3};
    int WidthCounter{};
    int TreesCounter{};
    int TreesCounter2{};
    int TreesCounter3{};
    int TreesCounter4{};
    int TreesCounter5{};
    unsigned long long TreeTotal{1};
    int FreeCounter{};

    try 
    {
        if (!trees) 
        {
            throw ("File could not be found.");
        }
    }
    catch(const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }
    
    std::getline(trees, FirstLine);
    WidthCounter = FirstLine.size();

    while(std::getline(trees, Line)) 
    {
        TreesContainer.push_back(Line);
    }

    for (auto i = 0; i < TreesContainer.size(); ++i)
    {
        if (SpaceCounter >= WidthCounter)
        {
            SpaceCounter -= WidthCounter;
        }
        if (TreesContainer.at(i).at(SpaceCounter) == '.') 
        {
            ++FreeCounter;
            SpaceCounter += 3;
        }
        else if (TreesContainer.at(i).at(SpaceCounter) == '#')
        {
            ++TreesCounter;
            SpaceCounter += 3;
        }
    }

    std::cout << "\nThe number of free space you will encounter is: " << FreeCounter << "\n\n";
    std::cout << "The number of trees you will encounter is: " << TreesCounter << std::endl;

    SpaceCounter = 1;

    for (auto i = 0; i < TreesContainer.size(); ++i)
    {
        if (SpaceCounter >= WidthCounter)
        {
            SpaceCounter -= WidthCounter;
        }
        if (TreesContainer.at(i).at(SpaceCounter) == '.') 
        {
            ++FreeCounter;
            SpaceCounter += 1;
        }
        else if (TreesContainer.at(i).at(SpaceCounter) == '#')
        {
            ++TreesCounter2;
            SpaceCounter += 1;
        }
    }
    std::cout << "The number of trees you will encounter is: " << TreesCounter2 << std::endl;

    SpaceCounter = 5;

    for (auto i = 0; i < TreesContainer.size(); ++i)
    {
        if (SpaceCounter >= WidthCounter)
        {
            SpaceCounter -= WidthCounter;
        }
        if (TreesContainer.at(i).at(SpaceCounter) == '.') 
        {
            ++FreeCounter;
            SpaceCounter += 5;
        }
        else if (TreesContainer.at(i).at(SpaceCounter) == '#')
        {
            ++TreesCounter3;
            SpaceCounter += 5;
        }
    }
    std::cout << "The number of trees you will encounter is: " << TreesCounter3 << std::endl;

    SpaceCounter = 7;

    for (auto i = 0; i < TreesContainer.size(); ++i)
    {
        if (SpaceCounter >= WidthCounter)
        {
            SpaceCounter -= WidthCounter;
        }
        if (TreesContainer.at(i).at(SpaceCounter) == '.') 
        {
            ++FreeCounter;
            SpaceCounter += 7;
        }
        else if (TreesContainer.at(i).at(SpaceCounter) == '#')
        {
            ++TreesCounter4;
            SpaceCounter += 7;
        }
    }
    std::cout << "The number of trees you will encounter is: " << TreesCounter4 << std::endl;

    SpaceCounter = 1;

    for (auto i = 1; i < TreesContainer.size(); ++i)
    {
        if (SpaceCounter >= WidthCounter)
        {
            SpaceCounter -= WidthCounter;
        }
        if (TreesContainer.at(i).at(SpaceCounter) == '.') 
        {
            ++FreeCounter;
            SpaceCounter += 1;
            ++i;
        }
        else if (TreesContainer.at(i).at(SpaceCounter) == '#')
        {
            ++TreesCounter5;
            SpaceCounter += 1;
            ++i;
        }
    }
    std::cout << "The number of trees you will encounter is: " << TreesCounter5 << std::endl;

    TreeTotal *= TreesCounter; 
    TreeTotal *= TreesCounter2;
    TreeTotal *= TreesCounter3;
    TreeTotal *= TreesCounter4;
    TreeTotal *= TreesCounter5;

    std::cout << "\nTree counters multiplied = " << TreeTotal << std::endl;
    trees.close();
    
    return 0;
}