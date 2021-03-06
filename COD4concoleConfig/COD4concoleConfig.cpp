// COD4concoleConfig.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "COD4concoleConfig.h"
#include "myString.h"


using namespace std;

std::string getPath(string path_fileName)
{

	//Read line
	string line;

	//PATH to config file
	string localPATH;

	//Open file PATH.txt
	ifstream rmyFile(path_fileName);

	string list_lines[2];


	//Read file PATH.txt
	if (rmyFile.is_open())
	{	
		int index = 0;

		while (getline(rmyFile, line))
		{
			if (index <= 1) {
				list_lines[index] = line;
				
				index++;
			}
		}

		localPATH = list_lines[1];
		cout << "getPath() -> read " << localPATH << endl;

		rmyFile.close();
	}
	else {
		//open file to write if exist or create new one
		ofstream myFile(path_fileName);

		//if file open write
		if (myFile.is_open())
		{
	

			//cout << "Enter path to config file. Example: F:\\\Cplus\\\COD4concoleConfig\\\COD4concoleConfig" << endl;
			// E:\\CallOFDuty\\Call of Duty Black Ops 4\\players\\config.ini
			cout << "Enter path to config file. Example: C:" << "\\"  << "Call of Duty Black Ops 4" <<  "\\" << "players" <<
				"\\" << "000000001c0a6ac8" << "\\" << "config.ini" << endl;


			//Get user input with file path until its correct
			bool loop = true;

			while (loop)
			{
				getline(cin, localPATH);

				ifstream testFile(localPATH);

				if (testFile.is_open())
				{
					loop = false;
					testFile.close();
				}

			}

			
			//write help to file
			myFile << "Change path to config file in the next line.\n";

			if (localPATH == "")
			{
				myFile << "C:\\Call of Duty Black Ops 4\\players\\000000001c0a6ac8\\config.ini";
			}
			else {
				//write path to file
				myFile << localPATH;
			}

			
			myFile.close();
		}
		else {
			cout << "getPath() \n";
		}


	}



	//Test if we can open file or not. Loop input from user to be sure path is correct
	ifstream testPath(localPATH);

	if (testPath.is_open())
	{
		testPath.close();
		return localPATH;
		
	}
	else {
		bool loop = true;

		//Loop user input until file is open
		while (loop)
		{
			cout << "Enter path to config file. Example: C:" << "\\" << "Call of Duty Black Ops 4" << "\\" << "players" <<
				"\\" << "000000001c0a6ac8" << "\\" << "config.ini" << endl;

			getline(cin, localPATH);

			ifstream testFile(localPATH);

			if (testFile.is_open())
			{
				loop = false;
				testFile.close();

				//Override path in PATH.txt
				ofstream rewritePath(path_fileName);

				if (rewritePath.is_open())
				{
					rewritePath << "Change path to config file in the next line.\n";
					rewritePath << localPATH;
					rewritePath.close();

				} else { cout << "getPath() -> check part" << endl; }

			}

		}

		return localPATH;
	}

	return localPATH;

}

int getConfigSize(std::string path_fileName)
{


	//Read line
	string line;

	//Open file PATH.txt
	ifstream rmyFile(path_fileName);


	int index_lines = 0;

	//Read file PATH.txt
	if (rmyFile.is_open())
	{
		while (getline(rmyFile, line))
		{
			//cout << line << '\n';
			index_lines++;
		}

		rmyFile.close();
	}
	else {
		cout << "HAHAHHAHA";
	}

	return index_lines;

}



int main()
{
	//File with config path
	string path_file = "PATH.txt";

	//Get config location
	configPATH = getPath(path_file);

	//Get config size
	int index_lines = getConfigSize(configPATH);

	cout << index_lines << endl;

	//Create collection with given size
	vector<string> vec_lines(index_lines);

	ifstream rmyFile_2(configPATH);

	string line;

	//Read file PATH.txt
	if (rmyFile_2.is_open())
	{
		int index = 0;

		while (getline(rmyFile_2, line))
		{
			//cout << line << '\n';
			vec_lines[index] = line;
			index++;
		}

		rmyFile_2.close();
	}
	else {
		cout << "Wrong Path to config file";
		//configPATH = getPath(path_file);
	}


	for (int i = 0; i < index_lines; i++)
	{
		if (vec_lines[i].find("spot_shadow_texture_size") != -1)
		{
			//string str = "512";

			//vec_lines[i].replace(vec_lines[i].find(str), str.length(), "128");

			int firstS;
			int secondS;

			firstS = myStringFind_first(vec_lines[i]);
			secondS = myStringFind_last(vec_lines[i]);

			vec_lines[i] = myReplace_symbols(vec_lines[i], firstS, secondS - firstS - 1, "128");

		}
		else if (vec_lines[i].find("omni_shadow_texture_size") != -1)
		{
			//string str = "256";

			//vec_lines[i].replace(vec_lines[i].find(str), str.length(), "128");

			int firstS;
			int secondS;

			firstS = myStringFind_first(vec_lines[i]);
			secondS = myStringFind_last(vec_lines[i]);

			vec_lines[i] = myReplace_symbols(vec_lines[i], firstS, secondS - firstS - 1, "128");
		}
		else {  }
	}


	for (int i = 0; i < index_lines; i++)
	{
		cout << vec_lines[i] << endl;
	}


	//open file to write if exist or create new one
	ofstream myFile(configPATH);

	//if file open write
	if (myFile.is_open())
	{

		for (int i = 0; i < index_lines; i++)
		{

			myFile << vec_lines[i] << endl;

		}


		myFile.close();
	}
	else {
		cout << "No file";
	}

	return 0;

}

