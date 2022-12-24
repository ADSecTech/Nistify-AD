#include "pch.h"

// nistify_testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "custom_headers.h"

void tests()
{
    // Testing the HIBP API access
    cout << "[-] Can we access the HIBP API?\n";
    string output;
    accessApi(L"api.pwnedpasswords.com", L"/range/5BAA6", &output);
    if (output.size() > 0)
        cout << "[*] Yes!\n";
    else
        cout << "[!] No!\n";

    // Testing registry read
    cout << "[-] Can we read the configuration from the registry?\nComputer\\HKEY_LOCAL_MACHINE\\SOFTWARE\\NISTifyAD\n";
    Config conf;
    readConfig(&conf);
    if (conf.api_server.size() > 0)
    {
        cout << "[*] Yes!\n";
        cout << "[*] Values:\n";
        wcout << "[*] Server: " << conf.api_server.c_str() << endl;
        wcout << "[*] Resource: " << conf.resource_location.c_str() << endl;
    }
    else
        cout << "[!]No!\n";

    // Testing the API access as provided by the registry
    cout << "[-] Can we access the API specified in the registry?\n";
    conf.resource_location += L"5BAA6";
    output = "";
    accessApi(conf.api_server.c_str(), conf.resource_location.c_str(), &output);
    if (output.size() > 0)
        cout << "[*] Yes!\n";
    else
        cout << "[!] No!\n";

    // Testing the crytography functions
    cout << "[-] Testing the sha1 hashing function." << endl;
    string proposed_password = "password";
    cout << "[*] The proposed password: " << proposed_password << endl;
    string hash;
    getHash(&proposed_password, &hash);
    cout << "[*] The resultant hash: " << hash << endl;

    // Testing full connection process
    cout << "[-] Testing full initialization and password check using 'password' " << endl;
    readConfig(&conf);
    string hash_prefix = hash.substr(0, 5);
    // ! need to figure out how to get (string)hash_prefix and (wstring)conf.resource_location
    // together as a LPCWSTR or wstring. 
    string resource(conf.resource_location.begin(), conf.resource_location.end());
    resource += hash_prefix;

    output = "";
    // Still coming up with an invalid response from the server
    // the whole LPCWSTR conversion thing just generates emojies and chinese characters
    // there is somthing wrong with the casting. 
    // Proposed fix: https://stackoverflow.com/questions/27220/how-to-convert-stdstring-to-lpcwstr-in-c-unicode
    wstring conversion = wstring(resource.begin(), resource.end());
    LPCWSTR end_conversion = conversion.c_str();
    // End
    accessApi(conf.api_server.c_str(), end_conversion, &output);
    if (checkPassword(&proposed_password, hash, &output))
        cout << "[!] No! Password was not rejected" << endl;
    else
        cout << "[*] Password was rejected as expected" << endl;

    cout << "[*] Any 'No' entries denoted with the exclamation point '!' may be issues that require investigation." << endl;
}