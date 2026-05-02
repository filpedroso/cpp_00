/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:02:14 by fpedroso          #+#    #+#             */
/*   Updated: 2026/05/02 16:25:30 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    Contact::displayItself()
{
    std::cout << "NAME: " << this->firstName << "\n";
    std::cout << "LAST: " << this->lastName << "\n";
    std::cout << "NICK: " << this->nickName << "\n";
    std::cout << "PHONE: " << this->phoneNum << "\n";
    std::cout << "SECRET: " << this->darkestSecret << "\n";
}
