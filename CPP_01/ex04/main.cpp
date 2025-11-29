/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:36 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/28 19:01:07 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>
#include <fstream> 

int	main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Incorrect parameters\nPlease enter 4 params: ./sed <file> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cerr << "No empty file and strings, please..." << std::endl;
		return 1;
	}
	// Open file
	std::fstream input_file(filename);
	if (!input_file.is_open())
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return 1;
	}
	// Read from file
	std::string file;
	std::string line;
	while (std::getline(input_file, line)) 
	{
		file += line;
		file += "\n";
	}
	input_file.close();
	// Search and Replace
	size_t pos = 0;
	size_t end_pos = 0;
	std::string replace;
	if ((end_pos = file.find(s1, pos)) != std::string::npos)
	{
		while (end_pos != std::string::npos)
		{
			replace += file.substr(pos, end_pos - pos);
			replace += s2;
			pos = end_pos + s1.length();
			end_pos = file.find(s1, pos);
		}
		replace += file.substr(pos);
	}
	else
	{
		std::cout << "No occurence of " << s1 << " found...\n Better try next time" << std::endl;
		return 0;
	}
	// Output file
	std::string out_filename = filename + ".replace";
	std::ofstream out_file(out_filename.c_str());
	if (!out_file.is_open()) 
	{
		std::cerr << "Error: Could not create output file\n";
		return 1;
	}
	out_file << replace;
	out_file.close();
	return 0;
}
