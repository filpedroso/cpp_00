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

#include <cctype>
#include <iostream>
#include <string>

class Megaphone
{
  public:
    Megaphone() {}
    ~Megaphone() {}

	void output()
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}

	void output(std::string voice)
	{
		for (std::string::iterator it = voice.begin(),
            end = voice.end(); it != end; ++it)
        {
            *it =std::toupper(static_cast<unsigned char>(*it));
        }
        std::cout << voice;
	}
};

int	main(int argc, char **argv)
{
		Megaphone megaphone;

	if (argc == 1)
	{
		megaphone.output();
	}
	else
	{
		for (int i = 1; i < argc; i++) {
			megaphone.output(argv[i]);
		}
	}
	std::cout << std::endl;
}
