/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:56:16 by minabe            #+#    #+#             */
/*   Updated: 2023/08/11 23:00:08 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	str;

	std::cin >> str;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str << std::endl;
	return (0);
}
