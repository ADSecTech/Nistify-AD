#include "custom_headers.h"

#include "pch.h"

// Takes in the plain text and then places the hexedecimal representation in hashhex
void getHash(string plaintext, string *hashhex)
{
	unsigned char hash[20];
	char hexstring[41];

	sha1::calc(plaintext.c_str(), plaintext.length(), hash);
	sha1::toHexString(hash, hexstring);

	hashhex->assign(hexstring);
}