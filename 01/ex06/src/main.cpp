/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:46:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Level	getLogLevel(const std::string &level);

int	main(int argc, char **argv)
{
	Harl	harl;
	Level	level;

	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (EXIT_FAILURE);
	}
	level = getLogLevel(argv[1]);
	switch (level)
	{
		case DEBUG:
			harl.complain("DEBUG");
		case INFO:
			harl.complain("INFO");
		case WARNING:
			harl.complain("WARNING");
		case ERROR:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "Invalid log level." << std::endl;
			break;
	}
	return (0);
}

Level	getLogLevel(const std::string &level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	else
		return (INVALID);
}
