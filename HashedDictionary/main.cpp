// main.cpp : Defines the entry point for the console application.

/************************************************************
*                                                          *
*  Author:        Rodel Aragon                             *
*  Course:        CS322 Data Structure and Algorithms II   *
*  Assignment:    Module 5, Written Assignment             *
*  Program:       Hashed Dictionary        		           *
*  Description:   Creates a Hashed Dictionary using        *
*				  seperate chaining                        *
*  Input:         User input strings                       *
*  Output:        Displays search key and item             *
*                 associated with search key.              *
*  Created:       11/26/2017                               *
*                                                          *
***********************************************************/


#include "stdafx.h"
#include "HashedDictionaryInterface.h"
#include "HashedDictionary.h"

/**
	Displays the menu.
*/
void displayMenu();

/**
	Ask the user for a menu choice.
	@return The user's menu choice.
*/
int askForMenuChoice();

/**
	Prompts the user to add an item to the dictionary.
	@param dictionaryPtr A pointer to the dictionary.
	@param searchKeys The vector containing the search keys.
*/
void addItem(HashedDictionaryInterface<std::string, std::string>* dictionaryPtr,
	std::vector<std::string>& searchKeys);

/**
	Prompts the user for an item to retrieve from the dictionary.
	@param dictionaryPtr A pointer to the dictionary.
	@param searchKeys The vector containing the search keys.
*/
void retrieveItem(HashedDictionaryInterface<std::string, std::string>* dictionaryPtr,
	std::vector<std::string>& searchKeys);

/**
	Prints the search keys that have values inside the dictionary.
	@param searchKeys The vector containing the search keys.
*/
void printSearchKeys(std::vector<std::string>& searchKeys);

int main()
{
	displayMenu();
	int userChoice = askForMenuChoice();
	std::cin >> userChoice;

    return 0;
}

void displayMenu()
{
	std::cout << "\n\n     Welcome to the HashedDictionary!\n\n";
	std::cout << "         ,..........   ..........,\n"
		<< "     ,..,'          '.'          ',..,\n"
		<< "    ,' ,'            :            ', ',\n"
		<< "   ,' ,'             :             ', ',\n"
		<< "  ,' ,'              :              ', ',\n"
		<< " ,' ,'............., : ,.............', ',\n"
		<< ",'  '............   '.'   ............'  ',\n"
		<< " '''''''''''''''''';''';''''''''''''''''''\n"
		<< "                    '''\n"
		<< "(Ascii Art from www.asciiart.eu/books/books)\n\n";

	std::cout << "Main menu:\n"
		<< "1 - Add item to the dictionary.\n"
		<< "2 - Retrieve an item from the dictionary.\n"
		<< "3 - Remove an item from the dict24ionary.\n"
		<< "4 - Terminate the program.\n\n";
}

int askForMenuChoice()
{
	bool isValidChoice = false;
	int userMenuChoice = 0;
	do
	{
		std::cout << "Enter a menu choice: ";
		std::string userChoiceText;
		std::getline(std::cin, userChoiceText);

		try
		{
			userMenuChoice = std::stoi(userChoiceText);
			isValidChoice = true;
		}
		catch (...)
		{
			std::cout << "Invalid menu option.\n\n";
			continue;
		}
		if (userMenuChoice > 4 || userMenuChoice < 0)
		{
			std::cout << "Menu option must be within the range of 1-4.\n\n";
			isValidChoice = false;
		}
	} while (!isValidChoice);

	return userMenuChoice;
}
