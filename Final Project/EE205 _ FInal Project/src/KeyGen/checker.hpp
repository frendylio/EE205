#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//This was made by Isaac Lee with help from Blaine Furman

// IMPORTANT!!!
// Once key2.txt is created, the key will be permanent until you delete the key2.txt file. Leave the keys.txt file alone. 
class checker {
private:
	bool active;
public:
	
		//Purpose: Create text files 
		void isCorrect(std::string key)
		{
			//taking file as input stream
			std::ifstream key_file("keys.txt");
			std::ifstream key2_file("keys2.txt");
			// Declare myfile, string x and y
			std::ofstream myfile;
			std::string first, second;
			bool key_true = false;

			// This if statement sees if there are two text files so that no more unique keys are made and that the user can just use that one key.
			if (repeat("keys.txt", "keys2.txt") != 1) {
			// Check if textfile is there
			active = fexists("keys.txt");
			// open myfile and creates txt files
			myfile.open("keys.txt");
			myfile << key;
			myfile.close();
			getline(key_file, second);

			// if there is a text file
			if (active == true)
			{
				// prompt user for key
				std::cout << "Enter your key now\n" << std::endl;
				std::cin >> first;
				//check if the key is correct
				if (first != second) {
					while (key_true == false)
					{
						// Error, have user enter in key again until it is true
						std::cout << "Key is not correct. Please Enter Again" << std::endl;
						std::cout << "\nEnter your key now\n" << std::endl;
						std::cin >> first;
						// If it becomes correct, then it outputs key is correct and creates a new text file
						if (first == second) {
							key_true = true;
							cout << "Key is correct" << endl;
												// Running Menu
					system("Menu.exe");
					std::cout << "The Menu Run" << std::endl; 
							myfile.open("keys2.txt");
							myfile << second;
							myfile.close();
						}
					}
				}
				// If it becomes correct, then it outputs key is correct and creates a new text file
				else if (first == second)
				{
					cout << "Key is correct" << endl;
					key_true = true;
					myfile.open("keys2.txt");

					// Running Menu
					system("Menu.exe");
					std::cout << "The Menu Run" << std::endl; 

					myfile << second;
					myfile.close();

				}
			}

			else {
				//makes a new text file (writes file)
				myfile << key;
				myfile.close();
			}
		}
		}
		// This Compares the two text files and sends back a bool
		bool repeat(const char* filename, const char* filename1) 
		{
		std::ifstream key_file(filename);
		std::ifstream key2_file(filename1);
		std::string x, y;
		getline(key_file, x);
		getline(key2_file, y);

		if (x == y && x != "" && y != "") 
		{ 
								// Running Menu
					system("Menu.exe");
					std::cout << "The Menu Run" << std::endl; 
					return true;
		}
		else return false;
		}
		// This sees if there is a txt file.
	bool fexists(const char* filename)
	{
		std::ifstream myfile(filename);

		if (myfile.get() == NULL)
		{ return false; }
		else return true;
	};


};
