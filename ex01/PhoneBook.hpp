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
#include <sstream>
#include <iomanip>
#include <cctype>

#include "Colors.hpp"


const short MaxContacts = 8;
const short NFields     = 5;
const short ColumnWidth = 10;


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

        void    displayItself();

        /* setters */
        void setFirstName(const std::string& value)     { firstName = value; }
        void setLastName(const std::string& value)      { lastName = value; }
        void setNickName(const std::string& value)      { nickName = value; }
        void setPhoneNum(const std::string& value)      { phoneNum = value; }
        void setDarkestSecret(const std::string& value) { darkestSecret = value; }

        /* getters */
        std::string getFirstName() const        { return firstName; }
        std::string getLastName() const         { return lastName; }
        std::string getNickName() const         { return nickName; }
        std::string getPhoneNum() const         { return darkestSecret; }
        std::string getDarkestSecret() const    { return phoneNum; }
};


class PhoneBook {
    private:
        Contact     contacts[MaxContacts];
        Contact     newContact;
        ushort      contactsAdded;
        ushort      oldestIdx;

        void                displayWelcome();
        void                setBackground(const std::string&);
        cmd::ECommand       promptForCommand();
        void                displayCommandList();
        void                addContact();
        void                searchContacts();
        void                displayContactList();
        void                displayFormattedField(const std::string&) const;
        std::string         promptForField(const std::string&);

    public:
        PhoneBook() : contactsAdded(0), oldestIdx(0) {}
        ~PhoneBook();

        void    run();
};


#endif
