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

// ========== RESET ==========
# define C_RESET        "\033[0m"

// ========== TEXT ATTRIBUTES ==========
# define C_BOLD         "\033[1m"
# define C_DIM          "\033[2m"
# define C_UNDERLINE    "\033[4m"
# define C_BLINK        "\033[5m"
# define C_REVERSE      "\033[7m"
# define C_HIDDEN       "\033[8m"

// ========== FOREGROUND COLORS ==========
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_YELLOW       "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_WHITE        "\033[37m"

// ========== BRIGHT FOREGROUND ==========
# define C_BRIGHT_BLACK     "\033[90m"
# define C_BRIGHT_RED       "\033[91m"
# define C_BRIGHT_GREEN     "\033[92m"
# define C_BRIGHT_YELLOW    "\033[93m"
# define C_BRIGHT_BLUE      "\033[94m"
# define C_BRIGHT_MAGENTA   "\033[95m"
# define C_BRIGHT_CYAN      "\033[96m"
# define C_BRIGHT_WHITE     "\033[97m"

// ========== BACKGROUND COLORS ==========
# define BG_BLACK       "\033[40m"
# define BG_RED         "\033[41m"
# define BG_GREEN       "\033[42m"
# define BG_YELLOW      "\033[43m"
# define BG_BLUE        "\033[44m"
# define BG_MAGENTA     "\033[45m"
# define BG_CYAN        "\033[46m"
# define BG_WHITE       "\033[47m"

// ========== BRIGHT BACKGROUNDS ==========
# define BG_BRIGHT_BLACK    "\033[100m"
# define BG_BRIGHT_RED      "\033[101m"
# define BG_BRIGHT_GREEN    "\033[102m"
# define BG_BRIGHT_YELLOW   "\033[103m"
# define BG_BRIGHT_BLUE     "\033[104m"
# define BG_BRIGHT_MAGENTA  "\033[105m"
# define BG_BRIGHT_CYAN     "\033[106m"
# define BG_BRIGHT_WHITE    "\033[107m"

// ========== COMBOS (handy presets) ==========
# define C_ERROR        C_BOLD C_RED
# define C_WARNING      C_BOLD C_YELLOW
# define C_SUCCESS      C_BOLD C_GREEN
# define C_INFO         C_BOLD C_CYAN
# define C_TITLE        C_BOLD C_MAGENTA
# define C_PROMPT       C_BRIGHT_CYAN
# define C_INDEX        C_BRIGHT_YELLOW


const short MaxContacts = 8;
const short NFields     = 5;
const short OutOfRange  = MaxContacts + 1;
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
