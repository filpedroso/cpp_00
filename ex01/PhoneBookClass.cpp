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
    std::cout << "PLEASE TYPE COMMAND:" << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "ADD" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "SEARCH" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "EXIT" << std::endl;
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

    if (oldestIdx == MAX_CONTACTS) oldestIdx = 0;

    newContact.setFirstName(promptForField("first name"));
    newContact.setLastName(promptForField("last name"));
    newContact.setNickName(promptForField("nick name"));
    newContact.setPhoneNum(promptForField("phone number"));
    newContact.setDarkestSecret(promptForField("darkest secret"));

    if (contactsAdded == MAX_CONTACTS) {
        contacts[oldestIdx] = newContact;
        oldestIdx++;
        std::cout << "Oldest contact replaced successfully!" << std::endl;
        return ;
    }

    contacts[contactsAdded] = newContact;
    contactsAdded++;
    std::cout << "Contact created successfully!" << std::endl;
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
    u_short contactIdx;

    do
    {
        displayContactList();
        contactIdx = getContactIdx();

    } while (contactIdx >= MAX_CONTACTS);
}
