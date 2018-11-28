#include "pch.h"
#include "myString.h"
#include <iostream>






int myStringFind_first(std::string input)
{

	int string_length = input.length();

	//std::cout << string_length << std::endl;

	//not necessary in this function
	std::vector<char> line(string_length);

	for (int i = 0; i < string_length; i++)
	{
		line[i] = input[i];

	}


	for (int i = 0; i < string_length; i++)
	{

		if (line[i] == '"')
		{
			return i;
		}
	}

	return -1;
}

int myStringFind_last(std::string input)
{

	int string_length = input.length();

	//std::cout << string_length << std::endl;

	//not necessary in this function
	std::vector<char> line(string_length);

	//для теста сделать запись последнего символа в строке в первый символ вектора (добавить int y = 0; и бомбить line[y]; i++;)
	for (int i = string_length - 1; i >= 0; i--)
	{
		line[i] = input[i];

	}

	for (int i = string_length - 1; i >= 0; i--)
	{

		if (line[i] == '"')
		{
			return i;
		}
	}

	return -1;
}

std::string myReplace_symbols(std::string input, int start, int end, std::string replacement)
{
	//thisg"123"esymbols


	//create vector with default string


	if (input == "" || start < 0 || start >= (input.length() - 1) || (start + end) >= (input.length() - 1) || replacement == "")
	{
		return "ERROR";
	}

	std::string working = input;

	std::vector<char> line(replacement.length());

	for (int i = 0; i < line.size(); i++)
	{
		line[i] = replacement[i];

		std::cout << line[i];
	}

	std::cout << std::endl;


	//create vector with symbols before first entering point

	std::vector<char> first_part(start + 1);

	for (int i = 0; i < start + 1; i++)
	{
		first_part[i] = working[i];

		std::cout << first_part[i];
	}

	std::cout << std::endl;


	//create vector with symbols after second entering point

	int enter = working.length() - (start + 1) - end;

	std::vector<char> second_part(enter);

	for (int i = 0; i < enter; i++)
	{
		second_part[i] = working[i + ((start + 1) + end)];

		std::cout << second_part[i];
	}

	//create final vecor with new symbols in it
	int final_length = first_part.size() + line.size() + second_part.size();

	std::cout << std::endl << final_length << std::endl;

	std::vector<char> final_string(final_length, 'o');

	//add first part to final vector
	for (int i = 0; i < first_part.size(); i++)
	{
		final_string[i] = first_part[i];
	}

	//add replacement to final vector
	for (int i = 0; i < line.size(); i++)
	{
		final_string[i + first_part.size()] = line[i];
	}

	//add second part to final vector
	for (int i = 0; i < second_part.size(); i++)
	{
		final_string[i + first_part.size() + line.size()] = second_part[i];
	}


	//final test
	for (int i = 0; i < final_string.size(); i++)
	{
		std::cout << final_string[i];
	}

	std::cout << std::endl;



	return std::string(final_string.begin(), final_string.end());
}

