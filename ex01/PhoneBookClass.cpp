/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:15:35 by fpedroso          #+#    #+#             */
/*   Updated: 2026/05/02 19:45:50 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::run()
{
	cmd::ECommand command;

	setBackground(TXT_BG_BLACK);
	displayWelcome();
	do
	{
		command = promptForCommand();
		switch (command)
		{
		case cmd::ADD:
			addContact();
			break;
		case cmd::SEARCH:
			searchContacts();
			break;
		default:
			break;
		}
	} while (command != cmd::EXIT && std::cin.good());
}

void PhoneBook::displayWelcome()
{
	std::cout << "WELCOME!!!" << std::endl;
	sleep(1);
	std::cout << CLEAR_SCREEN;
}

void PhoneBook::displayCommandList()
{
	std::cout << "ADD" << std::endl;
	usleep(30000);
	std::cout << "SEARCH" << std::endl;
	usleep(30000);
	std::cout << "EXIT" << std::endl
			  << std::endl;
	usleep(30000);
	std::cout << "Please type command: ";
}

cmd::ECommand PhoneBook::promptForCommand()
{
	std::string cmdStr;

	displayCommandList();
	if (!std::getline(std::cin, cmdStr))
		return (cmd::INVALID);

	if (cmdStr.compare("ADD") == 0)
		return (cmd::ADD);
	else if (cmdStr.compare("SEARCH") == 0)
		return (cmd::SEARCH);
	else if (cmdStr.compare("EXIT") == 0)
		return (cmd::EXIT);
	else
		return (cmd::INVALID);
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string newField;

	if (oldestIdx == MaxContacts)
		oldestIdx = 0;
	std::cout << CLEAR_SCREEN;
	newContact.setFirstName(promptForField("first name"));
	newContact.setLastName(promptForField("last name"));
	newContact.setNickName(promptForField("nick name"));
	newContact.setPhoneNum(promptForField("phone number"));
	newContact.setDarkestSecret(promptForField("darkest secret"));

	if (!std::cin.good())
		return;

	if (contactsAdded == MaxContacts)
	{
		contacts[oldestIdx] = newContact;
		oldestIdx++;
		std::cout << "Oldest contact replaced successfully!" << std::endl;
		return;
	}

	contacts[contactsAdded] = newContact;
	contactsAdded++;
	std::cout << CLEAR_SCREEN;
	std::cout << "Contact created successfully!" << std::endl;
	sleep(1);
	std::cout << CLEAR_SCREEN;
}

std::string PhoneBook::promptForField(const std::string &fieldName)
{
	std::string inputField;

	do
	{
		std::cout << fieldName << ": ";

		if (!std::getline(std::cin, inputField))
			break ;

	} while (inputField.empty());
	return (inputField);
}

void PhoneBook::searchContacts()
{
	std::string input;
	size_t contactIdx;
	bool valid = false;

	if (contactsAdded == 0)
	{
		std::cout << CLEAR_SCREEN;
		std::cout << "NO CONTACTS YET!!!" << std::endl;
		sleep(1);
		std::cout << CLEAR_SCREEN;
		return;
	}

	do
	{
		displayContactList();
		std::cout << "Enter contact index: ";

		if (!std::getline(std::cin, input))
			return ;

		std::stringstream ss(input);
		if ((ss >> contactIdx) && ss.eof() && contactIdx < contactsAdded)
		{
			valid = true;
		}
		else
		{
			std::cout << CLEAR_SCREEN;
			std::cout << "INVALID INPUT!!!" << std::endl;
			sleep(2);
			std::cout << CLEAR_SCREEN;
		}
	} while (!valid);
	std::cout << CLEAR_SCREEN;
	contacts[contactIdx].displayItself();
	std::cout << std::endl;
}

void PhoneBook::displayContactList()
{
	std::cout << CLEAR_SCREEN;

	std::cout << std::right << std::setfill(' ')
			  << std::setw(ColumnWidth) << "INDEX"		<< '|'
			  << std::setw(ColumnWidth) << "FIRST NAME"	<< '|'
			  << std::setw(ColumnWidth) << "LAST NAME"	<< '|'
			  << std::setw(ColumnWidth) << "NICK NAME"
			  << "\n" << std::endl;

	for (ushort i = 0; i < contactsAdded; i++)
	{
		std::cout << std::right << std::setw(ColumnWidth) << i << '|';
		displayFormattedField(contacts[i].getFirstName());
		std::cout << '|';
		displayFormattedField(contacts[i].getLastName());
		std::cout << '|';
		displayFormattedField(contacts[i].getNickName());
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return;
}

void PhoneBook::displayFormattedField(const std::string &str) const
{
	if (str.length() > ColumnWidth)
	{
		std::cout << std::setw(ColumnWidth) << str.substr(0, ColumnWidth - 1) + ".";
	}
	else
	{
		std::cout << std::setw(ColumnWidth) << str;
	}
}

PhoneBook::~PhoneBook()
{
	std::cout << CLEAR_SCREEN; // clear the alternate buffer
	std::cout << "GOODBYE!!!" << std::endl;
	sleep(1);
	std::cout << "\033[?1049l"; // exits alternate buffer (and destroys it)
}

void PhoneBook::setBackground(const std::string &bgColor)
{
	std::cout << "\033[?1049h"; // enters the alternate buffer
	std::cout << bgColor;
	for (int i = 0; i < 50; ++i)
	{
		std::cout << std::string(200, ' ') << "\n";
	}
	std::cout << "\033[H"; // moves cursor back to left upper corner
	std::cout.flush();
	std::cout << TXT_BOLD << TXT_GREEN;
}

/* ************************************************************************** */
