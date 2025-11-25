/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:29:17 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/04 15:03:00 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else 
	{
		for (int m = 1; m < argc; m++)
		{
			std::string arg = argv[m];
			for (size_t j = 0; j < arg.length(); j++)
				std::cout << static_cast<char>(std::toupper((arg[j])));
		}
		std::cout << std::endl;
	}
}
