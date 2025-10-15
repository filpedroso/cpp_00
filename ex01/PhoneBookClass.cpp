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

PhoneBook::PhoneBook() : contactsAdded(0)
{}

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

cmd::ECommand   PhoneBook::promptForCommand() {
    std::string     cmdStr;

    displayCommandList();
    std::getline(std::cin, cmdStr);

    if      (cmdStr.compare("ADD") == 0)    return (cmd::ADD);
    else if (cmdStr.compare("SEARCH") == 0) return (cmd::SEARCH);
    else if (cmdStr.compare("EXIT") == 0)   return (cmd::EXIT);
    else                                    return (cmd::INVALID);
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
