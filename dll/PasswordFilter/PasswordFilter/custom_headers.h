#pragma once

// Windows includes
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector>
#include <NTSecAPI.h>
#include <stringapiset.h>

using std::string;
using std::wstring;
using std::cout;
using std::wcout;
using std::endl;

// Testing
void tests();

// Crypto
// Uses smallsha1 - https://code.google.com/archive/p/smallsha1/
#include "sha1.h"
void getHash(string *plaintext, string *hashhex);

// Networking
// WinHTTP is a default Windows header file and the 5.1 version does not require IE and is supported up to Windows 11 now. 
#include <Winhttp.h>
#pragma comment(lib, "winhttp.lib") // Tells VS to include the acutal files -shrug-

void accessApi(LPCWSTR api, LPCWSTR resource, string* results);


// Config Resources
// [!] PROJECT MUST HAVE LINKER PROPERTIES SET TO REQUIRE ADMIN TO ACCESS HKEY_LOCAL_MACHINE
// [!] PROJECT MUST BE TARGETED TO C++ 17 OR HIGHER FOR THIS LIB TO WORK.
#include "WinReg.hpp" 

const wstring REGISTRY_SUBKEY = L"SOFTWARE\\NISTifyAD";
const wstring REGISTRY_SERVER_KEY = L"server";
const wstring REGISTRY_RESOURCE_KEY = L"resource";

typedef struct Config {
	wstring api_server;
	wstring resource_location;
} Config;

void readConfig(Config* conf);

// Password Checking
#include <cctype>
bool checkPassword(string *proposed_password, string password_hash, string* api_results);
void toUpper(string* str);

