//
// Created by Kurt Burdick on 12/4/19.
//

#include <iostream>
#include "UserInterface.h"

int main() {

    std::cout << "\n#################################" << std::endl;
    std::cout << "### Welcome to the Virtual DJ ###" << std::endl;
    std::cout << "#################################\n" << std::endl;
    std::cout << "### Authors: ###\n" << "- Kurt Burdick\n" << "- Wyatt Vigilante\n" << "- Robert Melikyan\n" << std::endl;

    std::cout << "enter 'help' for a list of the available commands\n" << std::endl;

    std::string inputString = "";

    while(inputString != "quit"){

        std::cout << "\nPlease enter a command key: \n";
        getline (std::cin, inputString);

        if(inputString == "help"){
            help();
        }


        if(inputString == "quit"){
            quit();
        }


    }

    return 0;

}
