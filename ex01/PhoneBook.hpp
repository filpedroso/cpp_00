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

const	short MaxContacts = 8;


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
        Contact() {}
        ~Contact() {}

        void setFirstName(const std::string& value)     { firstName = value; }
        void setLastName(const std::string& value)      { lastName = value; }
        void setNickName(const std::string& value)      { nickName = value; }
        void setPhoneNum(const std::string& value)      { phoneNum = value; }
        void setDarkestSecret(const std::string& value) { darkestSecret = value; }
};

class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        Contact newContact;
        int     contactsAdded;
        int     oldestIdx;

        void                displayWelcome();
        cmd::ECommand       promptForCommand();
        void                displayCommandList();
        void                addContact();
        void                searchContacts();
        void                displayList();
        void                promptForContact();
        Contact             getContact(int  idx);
        std::string         promptForField(const std::string&);

    public:
        PhoneBook() : contactsAdded(0), oldestIdx(0) {}
        ~PhoneBook() {}

        void    run();
};

#endif
