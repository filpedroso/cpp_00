/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:19:51 by fpedroso          #+#    #+#             */
/*   Updated: 2025/10/12 23:19:51 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <cctype>

#define MAX_CONTACTS 8

namespace cmd {
    enum   ECommand
    {
        ADD,
        SEARCH,
        EXIT,
        INVALID
    };
}

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string darkestSecret;
        std::string phoneNum;

    public:
        Contact();
        Contact(
            std::string newFirstName,
            std::string newLastName,
            std::string newNickName,
            std::string newDarkestSecret,
            std::string newPhoneNum
            );
        ~Contact();
};

class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        Contact newContact;
        int     contactsAdded;

        void                displayWelcome();
        cmd::ECommand       promptForCommand();
        void                displayCommandList();
        void                addContact();
        void                searchContacts();
        void                displayList();
        void                promptForContact();
        Contact             getContact(int  idx);

    public:
        PhoneBook();
        ~PhoneBook();

        void    run();
};

#endif
