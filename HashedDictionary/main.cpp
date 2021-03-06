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
*  Modified:      08/22/2018                               *
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
	Prompts the user to create an entry to add to the dictionary.
	@param dictionaryPtr The dictionary to add the entry.
*/
void performAddOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr);

/**
	Prompts the user for an item to retrieve from the dictionary.
	@param dictionaryPtr The dictionary to retrieve an entry from.
*/
void performRetrieveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr);

/**
	Prompts the user for an item to remove from the dictionary.
	@param dictionaryPtr The dictionary to remove an entry from.
*/
void performRemoveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr);

int main()
{
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr =
		new HashedDictionary<std::string, std::string>;

	bool continueProgram = true;
	do
	{
		displayMenu();
		int userChoice = askForMenuChoice();
		switch (userChoice)
		{
		case 1:
			performAddOperation(dictionaryPtr);
			break;
		case 2:
			performRetrieveOperation(dictionaryPtr);
			break;
		case 3:
			performRemoveOperation(dictionaryPtr);
			break;
		case 4:
			continueProgram = false;
			break;
		default:
			break;
		}
	} while (continueProgram);

	delete dictionaryPtr;
	dictionaryPtr = nullptr;
	std::cout << "\nTerminating program. Have a wonderful day!\n";

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
	int numOfMenuOptions = 4;
	do
	{
		std::cout << "Enter a menu choice: ";
		std::string userChoiceText;
		std::getline(std::cin, userChoiceText);
		try
		{
			userMenuChoice = std::stoi(userChoiceText);
		}
		catch (...)
		{
			std::cout << "Invalid menu option.\n\n";
			continue;
		}
		if (userMenuChoice > numOfMenuOptions || userMenuChoice <= 0)
		{
			std::cout << "Menu option must be within the range of 1-4.\n\n";
		}
		else
		{
			isValidChoice = true;
		}
	} while (!isValidChoice);

	return userMenuChoice;
}

void performAddOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr)
{
	std::string searchKey = "";
	std::cout << "\nCreate a search key or enter a period(.) " 
		<< "to return to the main menu: ";
	std::getline(std::cin, searchKey);
	while (searchKey[0] != '.')
	{
		std::string dataItem = "";
		std::cout << "Enter a data item to be associated with " 
			<< searchKey << ": ";
		std::getline(std::cin, dataItem);

		if (dictionaryPtr->isValidEntry(searchKey, dataItem))
		{
			bool IsAdded = dictionaryPtr->add(searchKey, dataItem);
			if (IsAdded)
			{
				std::cout << "\nData added to the dictionary.\n"
					<< searchKey << " : " << dataItem << std::endl << std::endl;
			}
			else
			{
				std::cout << "\nSearch key is already within the dictionary.\n\n";
			}
		}
		else
		{
			std::cout << "\nSearch key and data item cannot have "
				<< "leading spaces or be empty.\n\n";
		}

		std::cout << "Create a search key or enter a period(.) to return " << 
			"to the main menu: ";
		std::getline(std::cin, searchKey);
	}
}

void performRetrieveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr)
{
	std::string searchKey = "";
	std::cout << "\nEnter a search key to retrieve or enter "
		<< "a period(.) to return to the main menu: ";
	std::getline(std::cin, searchKey);

	while (searchKey[0] != '.')
	{
		if (dictionaryPtr->contains(searchKey))
		{
			std::cout << "\nData returned.\n"
				<< searchKey << " : " << dictionaryPtr->getItem(searchKey)
				<< std::endl << std::endl;
		}
		else
		{
			std::cout << "\nSearch key " << searchKey
				<< " is not within the dictionary.\n\n";
		}

		std::cout << "Enter a search key to retrieve or enter "
			<< "a period(.) to return to the main menu: ";
		std::getline(std::cin, searchKey);
	}
}

void performRemoveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr)
{
	std::string searchKey = "";
	std::cout << "\nEnter a search key to retrieve or enter "
		<< "a period(.) to return to the main menu: ";
	std::getline(std::cin, searchKey);

	while (searchKey[0] != '.')
	{
		bool isRemoved = dictionaryPtr->remove(searchKey);
		if (isRemoved)
		{
			std::cout << "\nSearch key " << searchKey 
				<< " has been removed from the dictionary.\n\n";
		}
		else
		{
			std::cout << "\nSearch key " << searchKey
				<< " is not within the dictionary.\n\n";
		}

		std::cout << "Enter a search key to retrieve or enter "
			<< "a period(.) to return to the main menu: ";
		std::getline(std::cin, searchKey);
	}
}
