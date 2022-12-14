// PasswordFilterTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Exports.h"

int main()
{   
    std::cout << "[-] Executing DLL test suite." << std::endl;

    // Exported test function from the DLL. 
    Test();

    std::cout << std::endl << "[-] Testing exported functions." << std::endl;

    if (InitializeChangeNotify() == TRUE)
        std::cout << "[*] InitializeChangeNotify is working as expected." << std::endl;
    else
        std::cout << "[!] InitializeChangeNotify is not working." << std::endl;
    
    if (PasswordChangeNotify(0, 0, 0) == 0)
        std::cout << "[*] PasswordChangeNotify is working as expected." << std::endl;
    else
        std::cout << "[!] PasswordChangeNotify is not working." << std::endl;

    // TODO: Currently, the exported PasswordFilter function returns True.
    //       It needs to run through the check process and return an intelligent value. 
    if (PasswordFilter(0, 0, 0, 0) == TRUE)
        std::cout << "[*] PasswordFilter is imported as expected." << std::endl;
    else
        std::cout << "[!] PasswordFilter is not working." << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
