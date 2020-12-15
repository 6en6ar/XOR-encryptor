// Encryptor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>


std::string XOR(std::string text,char key [])
{
	std::string output = text;

	for (size_t i = 0; i < text.length(); i++)
	{
		output[i] = text[i] ^ key[i % ((text.length() + i) / sizeof(int))];
	}
	return output;
}
std::string ROT(std::string text, bool enc)
{
	std::string output = text;
	if (enc)
	{
		for (size_t i = 0; i < text.length(); i++)
		{
			output[i] = text[i] - 13;
		}
		return output;
	}
	else
	{
		for (size_t i = 0; i < text.length(); i++)
		{
			output[i] = text[i] + 13;
		}
		return output;
	}
}
int main()
{
	std::string text ;
	char  key [18] = "\x73 \x63 \x68 \x69 \x63 \x6b \x73 \x61 \x6c";
	std::cout << "Enter a word to encrypt: -->"<< std::flush;
	std::getline(std::cin, text);
	std::string xorenc = XOR(text, key);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "XOR Encrypted --->" + xorenc << std::endl;
	std::cout << "XOR Decrypted --->" + XOR(xorenc,key) << std::endl;
	bool enc = true;
	std::string rot13enc = ROT(text, enc);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "ROT13 Encrypted --->" + rot13enc << std::endl;
	enc = false;
	std::cout << "ROT13 Decrypted --->" + ROT(rot13enc, enc) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

}

