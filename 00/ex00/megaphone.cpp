/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:56:16 by minabe            #+#    #+#             */
/*   Updated: 2023/08/16 15:52:53 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc == 1)
	{
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << str << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
		str += argv[i];
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str << std::endl;
	return (0);
}
