/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:37:50 by crios             #+#    #+#             */
/*   Updated: 2025/04/15 11:51:12 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

void Contact::setFirstName(const std::string &fn)
{
	firstName = fn;
}

PhoneBook::PhoneBook()
{
	contactCount = 0;
}
void Contact::setLastName(const std::string &ln)
{
	lastName = ln;
}
void Contact::setNickname(const std::string &nn)
{
	nickname = nn;
}
void Contact::setPhoneNumber(const std::string &pn)
{
	phoneNumber = pn;
}
void Contact::setDarkestSecret(const std::string &ds)
{
	darkestSecret = ds;
}

std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::displayContacts() const
{
	std::string input;

	std::cout << "\n📋 Contact List (" << contactCount << "/8)\n";
	std::cout << std::setw(45) << std::setfill('-') << "" << std::setfill(' ') << "\n";
	std::cout << "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "FirstName"
				<< "|" << std::setw(10) << "LastName"
				<< "|" << std::setw(10) << "Nickname"
				<< "|\n";
	std::cout << std::setw(45) << std::setfill('-') << "" << std::setfill(' ') << "\n";

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|" << std::setw(10) << i
			+ 1 << "|" << formatField(contacts[i].getFirstName()) << "|" << formatField(contacts[i].getLastName()) << "|" << formatField(contacts[i].getNickname()) << "|\n";
	}

	while (true)
	{
		std::cout << "Enter the index of the contact to view details (or 0 to cancel): ";

		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << "\nEOF detected. Exiting...\n";
				break ;
			}
			std::cin.clear();
			continue ;
		}
		if (input == "0")
			return ;

		bool valid = true;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!std::isdigit(input[i]))
			{
				valid = false;
				break ;
			}
		}

		if (!valid)
		{
			std::cout << "Invalid input. Please enter a number between 1 and " << contactCount << ".\n";
			continue ;
		}

		int index = std::atoi(input.c_str());

		if (index >= 1 && index <= contactCount)
		{
			const Contact &c = contacts[index - 1];
			std::cout << "\n📇 Contact Details:\n";
			std::cout << "First Name    : " << c.getFirstName() << "\n";
			std::cout << "Last Name     : " << c.getLastName() << "\n";
			std::cout << "Nickname      : " << c.getNickname() << "\n";
			std::cout << "Phone Number  : " << c.getPhoneNumber() << "\n";
			std::cout << "Darkest Secret: " << c.getDarkestSecret() << "\n";
			break ;
		}
		else
		{
			std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << ".\n";
		}
	}
}

void PhoneBook::addContacts()
{
	Contact	newContact;

	std::string input;
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	newContact.setFirstName(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	newContact.setNickname(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);
	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = newContact;
	}
}

int	main(void)
{
	PhoneBook	phonebook;

	std::string input;
	while (true)
	{
		std::cout << "Phonebook: ";
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << "\nEOF detected. Exiting...\n";
				break ;
			}
			std::cin.clear();
			continue ;
		}
		if (input.empty())
		{
			std::cout << "Please enter a command.\n";
			continue ;
		}
		if (input == "ADD")
			phonebook.addContacts();
		else if (input == "SEARCH")
			phonebook.displayContacts();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
