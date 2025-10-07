/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:35:25 by crios             #+#    #+#             */
/*   Updated: 2025/04/11 19:54:10 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	void setFirstName(const std::string &fn);
	void setLastName(const std::string &ln);
	void setNickname(const std::string &nn);
	void setPhoneNumber(const std::string &pn);
	void setDarkestSecret(const std::string &ds);

	// getters 还不清楚
	std::string getFirstName() const
	{
		return (firstName);
	}
	std::string getLastName() const
	{
		return (lastName);
	}
	std::string getNickname() const
	{
		return (nickname);
	}
	std::string getPhoneNumber() const
	{
		return (phoneNumber);
	}
	std::string getDarkestSecret() const
	{
		return (darkestSecret);
	}
};

class PhoneBook
{
  private:
	Contact contacts[8];
	int contactCount;

  public:
	PhoneBook();
	void addContacts();
	void displayContacts() const;
	//	void displayContacts() const;
};

#endif