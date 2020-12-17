#include <iostream>
#include <fstream>
#include <string>
#include <exception>


int main() {
    std::ifstream Input {"input.txt"};
    // current coordinate pulled from input
    std::string Coordinate;   
    // direction ship is facing
    int Direction{90};
    // x axis
    int xAxis{0};
    // y axis
    int yAxis{0};

    while (std::getline(Input, Coordinate)) {
        char Instruction{Coordinate.front()};
        Coordinate.erase(Coordinate.begin());
        const int Value{std::stoi(Coordinate)};

        if (Instruction == 'F') 
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
    }
    std::cout << "Your direction is: " << Direction << "\nand xAxis is: " 
              << xAxis << "\nand yAxis is: " << yAxis << "\n"
              << "The Manhattan value is: " << std::abs(xAxis) + std::abs(yAxis) << std::flush;
}

