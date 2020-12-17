#include <iostream>
#include <fstream>
#include <string>
#include <exception>

void SetF(char&, int&);
void MoveShip(char&, int&,const int&, int&, int&);

int main() {
    std::ifstream Input {"input.txt"};
    std::string Coordinate;             // current coordinate pulled from input
    int Direction{90};                  // direction ship is facing
    int xAxis{0};                       // +east, -west
    int yAxis{0};                       // +north, -south

    while (std::getline(Input, Coordinate)) 
    {
        char Instruction{Coordinate.front()};
        Coordinate.erase(Coordinate.begin());
        const int Value{std::stoi(Coordinate)};

        if (Instruction == 'F') 
        {
            SetF(Instruction, Direction);
        }
        MoveShip(Instruction, Direction, Value, xAxis, yAxis);
    }
}

void SetF (char& Instruction, int& Direction)
{
    switch (Direction) 
    {
        case 0:
            Instruction = 'N';
            break;
        case 90:
            Instruction = 'E';
            break;
        case 180:
            Instruction = 'S';
            break;
        case 270:
            Instruction = 'W';
            break;
    }
}

void MoveShip (char& Instruction, int& Direction,const int& Value, int& xAxis, int& yAxis)
{
    switch (Instruction)
    {
        case 'L':
            Direction -= Value;
            if (Direction < 0) {
                Direction += 360;
            }
            break;
        case 'R':
            Direction += Value;
            if (Direction >= 360) { // will never be 360 will instead be 0
                Direction -= 360;
            }
            break;
        case 'N':
            yAxis += Value;
            break;
        case 'E':
            xAxis += Value;
            break;
        case 'S':
            yAxis -= Value;
            break;
        case 'W':
            xAxis -= Value;
            break;
        default:
            throw std::runtime_error("Unknown instruction received");
    }
    std::cout << "Your direction is: " << Direction << "\nand xAxis is: " 
              << xAxis << "\nand yAxis is: " << yAxis << "\n"
              << "The Manhattan value is: " << std::abs(xAxis) + std::abs(yAxis) << std::flush;
}