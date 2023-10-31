/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/10/15 16:41:54 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static void	replace_file_content(std::string s1, std::string s2, std::ifstream &inputFile, std::ofstream &outputFile);

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		replace;

	if (argc != 4)
		std::cerr << "Error: Invalid number of arguments." << std::endl;
	else
	{
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		replace = filename + ".replace";
		std::ifstream	inputFile(filename);
		std::ofstream	outputFile(replace);
		if (!inputFile || !outputFile)
		{
			std::cerr << "Error: " << replace << " could not be opened." << std::endl;
			return (EXIT_FAILURE);
		}
		replace_file_content(s1, s2, inputFile, outputFile);
		inputFile.close();
		outputFile.close();
	}
	return (0);
}

static void	replace_file_content(std::string s1, std::string s2, std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string	line;
	size_t		pos;

	while (std::getline(inputFile, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
			pos = line.find(s1, pos);
		}
		outputFile << line << std::endl;
	}
}
