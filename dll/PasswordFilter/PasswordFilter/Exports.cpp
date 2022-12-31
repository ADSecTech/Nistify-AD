#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "Exports.h"

#include "custom_headers.h"

extern "C" __declspec(dllexport) BOOLEAN __stdcall InitializeChangeNotify()
{
	return TRUE;
}

extern "C" __declspec(dllexport) int __stdcall PasswordChangeNotify(
	PUNICODE_STRING * UserName,
	ULONG RelativeId,
	PUNICODE_STRING * NewPassword) 
{
	return 0;
}

extern "C" __declspec(dllexport) BOOLEAN __stdcall PasswordFilter(
	PUNICODE_STRING AccountName,
	PUNICODE_STRING FullName,
	PUNICODE_STRING Password,
	BOOLEAN SetOperation) 
{
	// Read in config
	Config conf;
	readConfig(&conf);

	// Convert password to hash
	string hash;
	getHash(&Password, &hash); // TODO: Convert PUNICODE_STRING to string

	// Create API call
	// See tests() if you want to understand why
	string hash_prefix = hash.substr(0, 5);
	string resource(conf.resource_location.begin(), conf.resource_location.end());
	resource += hash_prefix;

	// Access API
	// See tests() if you want to understand the conversion
	string output;
	wstring conversion = wstring(resource.begin(), resource.end());
	LPCWSTR end_conversion = conversion.c_str();
	accessApi(conf.api_server.c_str(), end_conversion, &output);

	return checkPassword(&Password, hash, &output); // TODO: Convert PUNICODE_STRING to string
}

extern "C" __declspec(dllexport) void __stdcall Test()
{
	tests();
}
