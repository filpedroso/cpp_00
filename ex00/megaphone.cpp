/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:01:25 by fpedroso          #+#    #+#             */
/*   Updated: 2025/09/28 12:01:25 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

class Megaphone {
    std::string amplified;

    public:
        Megaphone(const std::string voice) {
            amplified = voice;
            for (std::string::iterator it = amplified.begin(), end = amplified.end(); it != end; ++it) {
                *it = std::toupper(static_cast<unsigned char>(*it));
            }
        }
        Megaphone() : amplified("* LOUD AND UNBEARABLE FEEDBACK NOISE *") {}

        void    output() const {
            std::cout << amplified;
        }
};

int main(int argc, char **argv) {

    if (argc == 1) {
        Megaphone megaphone;
        megaphone.output();
    } else {
        for (int i = 1; i < argc; i++) {
            Megaphone megaphone(argv[i]);
            megaphone.output();
        }
    }
    std::cout << std::endl;
}
