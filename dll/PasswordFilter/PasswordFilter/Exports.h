// Export.h - Contains the exports for the PSAM routines
#pragma once

#include "custom_headers.h"

/*
#ifdef PSAM_EXPORTS
#define PSAM_API __declspec(dllexport)
#else
#define PSAM_API __declspec(dllimport)
#endif
*/

extern "C" __declspec(dllexport) BOOLEAN __stdcall InitializeChangeNotify();

extern "C" __declspec(dllexport) int __stdcall PasswordChangeNotify(
	PUNICODE_STRING * UserName,
	ULONG RelativeId,
	PUNICODE_STRING * NewPassword);

extern "C" __declspec(dllexport) BOOLEAN __stdcall PasswordFilter(
	PUNICODE_STRING AccountName,
	PUNICODE_STRING FullName,
	PUNICODE_STRING Password,
	BOOLEAN SetOperation);