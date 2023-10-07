/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/10/07 18:26:22 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		line;
	std::string		replace;

	if (argc == 4)
	{
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		replace = filename + ".replace";
		std::ifstream	inputFile(filename);
		if (!inputFile)
		{
			std::cerr << "Error: " << filename << " could not be opened." << std::endl;
			return (EXIT_FAILURE);
		}
		std::ofstream	outputFile(replace);
		if (!outputFile)
		{
			std::cerr << "Error: " << replace << " could not be opened." << std::endl;
			return (EXIT_FAILURE);
		}
		while (std::getline(inputFile, line))
		{
			// while (line.find(s1) != std::string::npos)
				/* replace */
			outputFile << line << std::endl;
		}
		inputFile.close();
		outputFile.close();
	}
	return (0);
}
