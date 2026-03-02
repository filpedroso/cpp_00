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

void    Contact::displayItself() {
    std::cout << "NAME: " << this->firstName << "\n";
    std::cout << "LAST: " << this->lastName << "\n";
    std::cout << "NICK: " << this->nickName << "\n";
    std::cout << "PHONE: " << this->phoneNum << "\n";
    std::cout << "SECRET: " << this->darkestSecret << "\n";
}
