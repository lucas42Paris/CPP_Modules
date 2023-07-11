/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:14 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/10 13:29:46 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <scalar_to_convert>\n"
			"Valid scalars : int, float, double or char" << std::endl;
        return (1);
    }

    try
    {
        Convert scalarConversion(argv[1]);
        std::cout << scalarConversion << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << RED "Input could'nt be converted: " << e.what() << RESET << std::endl;
    }

    return (0);
}
