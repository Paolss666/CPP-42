/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:30:07 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 17:47:52 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str = str.substr(0, startPos) + to + str.substr(startPos + from.length());
        startPos += to.length();
    }
}

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    
    std::ifstream FileOut;

    if (ac != 4)
    {
        std::cerr << " Bad numbers of arguments " << std::endl;
        return 1;
    }

    FileOut.open(av[1]);
    if (!FileOut.is_open())
    {
        std::cerr << "File don't found" << std::endl;
        return 1;
    }

    
    s1 = av[2];
    if (s1.empty())
    {
        while (s1.empty())
        {
            std::cout << "inser the sentence to replace: ";
            if (!(getline(std::cin, s1)))
                return 1;
            else if (!s1.empty())
                break;
        }
    }

    std::string content((std::istreambuf_iterator<char>(FileOut)), std::istreambuf_iterator<char>());

    // std::cout << "content found ==> " << content << "pos " << pos << std::endl;
    s2 = av[3];
    if (s2.empty())
    {
        while (s2.empty())
        {
            std::cout << "inser the sentence to replace: ";
            if (!(getline(std::cin, s2)))
                return 1;
            else if (!s2.empty())
                break;
        }
    }

    replaceAll(content, s1, s2);
    
    std::string fileReplace = FileOut + ".replace";

    std::ofstream FileReplace(fileReplace);
    
    if (!FileReplace.is_open()){
        std::cerr << "I can't open this file" << std::endl;
    }

    FileReplace << content;
    FileReplace.close();
    FileOut.close();    
    return 0;
}