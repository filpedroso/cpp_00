/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:02:14 by fpedroso          #+#    #+#             */
/*   Updated: 2025/10/14 16:59:35 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(
            std::string firstName,
            std::string lastName,
            std::string nickName,
            std::string darkestSecret,
            std::string phoneNum
            )
            : firstName(firstName),
            lastName(lastName),
            nickName(nickName),
            darkestSecret(darkestSecret),
            phoneNum(phoneNum)
{
    std::cout << "Contact created successfully!" << std::endl;
}

Contact::~Contact()
{
    std::cout << "Contact destroyed." << std::endl;
}
