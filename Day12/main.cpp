#include <iostream>
#include <fstream>
#include <string>
#include <exception>

// void SetF(char&, int&);
// void MoveShip(char&, int&,const int&, int&, int&);

// int main() {
//     std::ifstream Input {"input.txt"};
//     std::string Coordinate;             // current coordinate pulled from input
//     int Direction{90};                  // direction ship is facing
//     int xAxis{0};                       // +east, -west
//     int yAxis{0};                       // +north, -south

//     while (std::getline(Input, Coordinate)) 
//     {
//         char Instruction{Coordinate.front()};
//         Coordinate.erase(Coordinate.begin());
//         const int Value{std::stoi(Coordinate)};

//         if (Instruction == 'F') 
//         {
//             SetF(Instruction, Direction);
//         }
//         MoveShip(Instruction, Direction, Value, xAxis, yAxis);
//     }
// }

// void SetF (char& Instruction, int& Direction)
// {
//     switch (Direction) 
//     {
//         case 0:
//             Instruction = 'N';
//             break;
//         case 90:
//             Instruction = 'E';
//             break;
//         case 180:
//             Instruction = 'S';
//             break;
//         case 270:
//             Instruction = 'W';
//             break;
//     }
// }

// void MoveShip (char& Instruction, int& Direction,const int& Value, int& xAxis, int& yAxis)
// {
//     switch (Instruction)
//     {
//         case 'L':
//             Direction -= Value;
//             if (Direction < 0) {
//                 Direction += 360;
//             }
//             break;
//         case 'R':
//             Direction += Value;
//             if (Direction >= 360) { // will never be 360 will instead be 0
//                 Direction -= 360;
//             }
//             break;
//         case 'N':
//             yAxis += Value;
//             break;
//         case 'E':
//             xAxis += Value;
//             break;
//         case 'S':
//             yAxis -= Value;
//             break;
//         case 'W':
//             xAxis -= Value;
//             break;
//         default:
//             throw std::runtime_error("Unknown instruction received");
//     }
//     std::cout << "Your direction is: " << Direction << "\nand xAxis is: " 
//               << xAxis << "\nand yAxis is: " << yAxis << "\n"
//               << "The Manhattan value is: " << std::abs(xAxis) + std::abs(yAxis) << "\n" << std::flush;
// }

// =========================================== Part 2 =========================================== 

void MoveShip(char&,const int&,int&, int&, int&, int&);

int main() {
    std::ifstream Input {"input.txt"};
    std::string Coordinate;             // current coordinate pulled from input
    int Direction{90};                  // direction ship is facing
    int xAxis{0};                       // +east, -west
    int yAxis{0};                       // +north, -south
    int WPxAxis{10};
    int WPyAxis{1};

    while (std::getline(Input, Coordinate)) 
    {
        char Instruction{Coordinate.front()};
        Coordinate.erase(Coordinate.begin());
        const int Value{std::stoi(Coordinate)};

        MoveShip(Instruction, Value, xAxis, yAxis, WPxAxis, WPyAxis);
    }
    std::cout << "Your direction is: " << Direction << "\nand xAxis is: " 
              << xAxis << "\nand yAxis is: " << yAxis << "\n"
              << "The Manhattan value is: " << std::abs(xAxis) + std::abs(yAxis) << "\n" << std::flush;
}

void MoveShip (char& Instruction,const int& Value, int& xAxis, int& yAxis, int& WPxAxis, int& WPyAxis)
{
    switch (Instruction)
    {
        case 'L':
            if (Value == 90) {
                std::swap(WPxAxis, WPyAxis);
                WPxAxis = -WPxAxis;
            }
            else if (Value == 180) {
                WPxAxis = -WPxAxis;
                WPyAxis = -WPyAxis;
            }
            else if (Value == 270) {
                std::swap(WPxAxis, WPyAxis);
                WPyAxis = -WPyAxis;
            }
            break;
        case 'R':
            if (Value == 90) {
                std::swap(WPxAxis, WPyAxis);
                WPyAxis = -WPyAxis;
            }
            else if (Value == 180) {
                WPxAxis = -WPxAxis;
                WPyAxis = -WPyAxis;
            }
            else if (Value == 270) {
                std::swap(WPxAxis, WPyAxis);
                WPxAxis = -WPxAxis;
            }
            break;
        case 'F':
            xAxis += (WPxAxis * Value);
            yAxis += (WPyAxis * Value);
            break;
        case 'N':
            WPyAxis += Value;
            break;
        case 'E':
            WPxAxis += Value;
            break;
        case 'S':
            WPyAxis -= Value;
            break;
        case 'W':
            WPxAxis -= Value;
            break;
        default:
            throw std::runtime_error("Unknown instruction received");
    }
}