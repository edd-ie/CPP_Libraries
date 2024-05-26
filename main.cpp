#include <iostream>
#include <bitset>
#include <iomanip>
#include <fstream>
#include "CurrentTime.h"
#include "LinkedList.h"


int main()
{
    currentTime();

    int input[5] = {2,35,7,4,3};

    std::ofstream file("output.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    for(int i : input)
    {
        file << i <<std::endl;
    }

    file.close();

    LinkedList list;

    try{list.remove();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    list.add(3);
    try{list.remove();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try{list.removeFirst();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    list.add(15);
    list.add(6);
    list.add(1);

    try{list.removeFirst();}
    catch (std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    list.add(62);
    list.add(5);
    list.add(66);

    std::cout << "\nList:\n" << list.toString() << std::endl;


    return 0;
}
