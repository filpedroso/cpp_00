/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:15:35 by fpedroso          #+#    #+#             */
/*   Updated: 2025/10/14 17:15:35 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::~PhoneBook() {
    std::cout << "GOODBYE!!!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
}

void    PhoneBook::run() {
    cmd::ECommand  command;

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

    } while (command != cmd::EXIT);
}

void    PhoneBook::displayWelcome() {
    std::cout << "WELCOME!!!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
}

void    PhoneBook::displayCommandList() {
    std::cout << "ADD" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "SEARCH" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "EXIT" << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "please type command:" << std::endl;
}

cmd::ECommand   PhoneBook::promptForCommand() {
    std::string     cmdStr;

    displayCommandList();
    std::getline(std::cin, cmdStr);

    if      (cmdStr.compare("ADD") == 0)    return (cmd::ADD);
    else if (cmdStr.compare("SEARCH") == 0) return (cmd::SEARCH);
    else if (cmdStr.compare("EXIT") == 0)   return (cmd::EXIT);
    else                                    return (cmd::INVALID);
}

void    PhoneBook::addContact() {
    Contact     newContact;
    std::string newField;

    if (oldestIdx == MaxContacts) oldestIdx = 0;

    newContact.setFirstName(promptForField("first name"));
    newContact.setLastName(promptForField("last name"));
    newContact.setNickName(promptForField("nick name"));
    newContact.setPhoneNum(promptForField("phone number"));
    newContact.setDarkestSecret(promptForField("darkest secret"));

    if (contactsAdded == MaxContacts) {
        contacts[oldestIdx] = newContact;
        oldestIdx++;
        std::cout << "Oldest contact replaced successfully!" << std::endl;
        return ;
    }

    contacts[contactsAdded] = newContact;
    contactsAdded++;
    system("clear");
    std::cout << "Contact created successfully!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
}

std::string PhoneBook::promptForField(const std::string& fieldName) {
    std::string inputField;

    do
    {
        std::cout << fieldName << ": ";
        std::getline(std::cin, inputField);
    } while (inputField.empty());
    return (inputField);
}


void    PhoneBook::searchContacts() {
    char    c;
    u_short contactIdx = 0;

    do
    {
        displayContactList();
        std::cout << "TYPE CONTACT INDEX" << std::endl;
        std::cin.get(c);
        if ((c >= '0') && (c < '0') + contactsAdded) {
            contactIdx = c - '0';
            break;
        }
        std::cout << "INVALID INPUT" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    } while (contactIdx >= contactsAdded);
    contacts[contactIdx].displayItself();
}


void    PhoneBook::displayContactList() {
    std::system("clear");

    for (ushort i = 0; i < contactsAdded; i++) {
        std::cout << "INDEX: " << i << std::endl;
        displayFormattedField(contacts[i].getFirstName());    std::cout << '|';
        displayFormattedField(contacts[i].getLastName());     std::cout << '|';
        displayFormattedField(contacts[i].getNickName());     std::cout << '|';
        displayFormattedField(contacts[i].getPhoneNum());     std::cout << '|';
        displayFormattedField(contacts[i].getDarkestSecret());
        std::cout << std::endl;
    }
    return ;
}

void    PhoneBook::displayFormattedField(const std::string& str) const {

    std::cout << std::right << std::setw(ColumnWidth) << std::setfill(' ');

    if (str.length() > ColumnWidth) {
        std::cout << str.substr(0, ColumnWidth - 1) + ".";
    }
    else { std::cout << str; }
}

/* ************************************************************************** */
