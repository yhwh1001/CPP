#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int main(int, char**) 
{
	separator("INTs");
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand(); 
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> copy(tmp);
    }
	//if this passes, deep copy works great! 
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete [] mirror;

	separator("Strings");
	Array<std::string>	alphabet(26);
	std::string*		strMirror = new std::string[26];
	for (int m = 0; m < 26; m++){
		alphabet[m] = (char)('a' + m);
		strMirror[m] = std::string(1, 'a' + m);
	}
	{
		Array<std::string> tmp = alphabet;
		Array<std::string> copy(tmp);
	}
	for (int m = 0; m < 26; m++) {
		if (alphabet[m] != strMirror[m])
			std::cout << "Values don't match... " << alphabet[m] << " unequal to " << strMirror[m] << std::endl;
		std::cout << "Matching values of " << alphabet[m] << " and " << strMirror[m] << std::endl;
	}
	try {
		alphabet[-3] = "Hello";
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		alphabet[23] = "Occult...";
		alphabet[26] = "WORLD";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << alphabet[23] << std::endl;
    return 0;
}