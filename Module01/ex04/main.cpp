/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:01:42 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:25:51 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <errno.h>

int	openStreams(std::ifstream *infileStream, std::ofstream *outfileStream, std::string infile, std::string outfile)
{
	infileStream->open(infile.c_str(), std::ifstream::in);

	if (!infileStream->good())
	{
		std::cerr << "Error: " << infile << ": " << strerror(errno) << std::endl;
		return (-1);
	}

	outfileStream->open(outfile.c_str(), std::ofstream::out | std::ofstream::trunc);

	if (!outfileStream->good())
	{
		infileStream->close();
		std::cerr << "Error: " << outfile << ": " << strerror(errno) << std::endl;
		return (-1);
	}
	return (0);
}

void	replace(std::string *buffer, const std::string s1, const std::string s2)
{
	size_t	pos = 0;

	if (s1.empty())
		return;
	
	while (pos != std::string::npos)
	{
		pos = buffer->find(s1.c_str(), 0, s1.length());

		if (pos == std::string::npos)
			break;

		buffer->erase(pos, s1.length());

		if (!s2.empty())
			buffer->insert(pos, s2);		
	}
}

int	copyContents(std::ifstream *infileStream, std::ofstream *outfileStream, 
				const std::string s1, const std::string s2)
{
	std::string	buffer;

	while (std::getline(*infileStream, buffer))
	{
		if (infileStream->fail())
			return (-1);

		replace(&buffer, s1, s2);
		*outfileStream << buffer;	

		if (!infileStream->eof())
			*outfileStream << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	infileStream;
	std::ofstream	outfileStream;
	std::string		infile, outfile, s1, s2;

	if (argc < 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	infile = argv[1];
	outfile = infile;

	outfile.append(".replace");

	s1 = argv[2];
	s2 = argv[3];

	if (openStreams(&infileStream, &outfileStream, infile, outfile) == -1)
		return (1);

	if (copyContents(&infileStream, &outfileStream, s1, s2) == -1)
	{
		infileStream.close();
		outfileStream.close();
		return (1);
	}
	infileStream.close();
	outfileStream.close();
	return (0);
}
