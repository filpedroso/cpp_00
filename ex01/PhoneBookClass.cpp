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

void PhoneBook::setBackground(const std::string& bgColor) {
    std::cout << bgColor;

    for (int i = 0; i < 50; ++i) { std::cout << std::string(200, ' ') << "\n"; }
    std::cout << "\033[H";
    std::cout.flush();
    std::cout << TXT_BOLD << TXT_GREEN;
}

void    PhoneBook::run() {
    cmd::ECommand  command;

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
    std::cout << "Please type command: ";
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
    system("clear");
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

void PhoneBook::searchContacts() {
    std::string input;
    size_t      contactIdx;
    bool        valid = false;

    do {
        displayContactList();
        std::cout <<"Enter contact index: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if ((ss >> contactIdx) && ss.eof() && contactIdx < contactsAdded) {
            valid = true;
        } else {
            system("clear");
            std::cout << "INVALID INPUT!!!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("clear");
        }
    } while (!valid);
    system("clear");
    contacts[contactIdx].displayItself();
    std::cout << std::endl;
}

void    PhoneBook::displayContactList() {
    std::system("clear");

    std::cout << std::right << std::setw(ColumnWidth) << std::setfill(' ');
    std::cout   << "INDEX"      << '|'
                << "FIRST NAME" << '|'
                << "LAST NAME"  << '|'
                << "NICK NAME"  << '|'
                << std::endl << std::endl;
    for (ushort i = 0; i < contactsAdded; i++) {
        std::cout << std::right << std::setw(ColumnWidth) << std::setfill(' ');
        std::cout << i << '|';
        displayFormattedField(contacts[i].getFirstName());    std::cout << '|';
        displayFormattedField(contacts[i].getLastName());     std::cout << '|';
        displayFormattedField(contacts[i].getNickName());
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return ;
}

void    PhoneBook::displayFormattedField(const std::string& str) const {
    if (str.length() > ColumnWidth) {
        std::cout << str.substr(0, ColumnWidth - 1) + ".";
    }
    else { std::cout << str; }
}

/* ************************************************************************** */
