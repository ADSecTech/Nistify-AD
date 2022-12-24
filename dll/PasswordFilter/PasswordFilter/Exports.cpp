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
	return TRUE;
}
