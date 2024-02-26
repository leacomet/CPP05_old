/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:55:06 by acomet            #+#    #+#             */
/*   Updated: 2024/02/26 22:31:05 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{

public:

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);
	Bureaucrat	&operator=(Bureaucrat const &src);

	std::string const	&getName(void) const;
	int					getGrade(void) const;

	void				increment(void);
	void				decrement(void);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what() const throw() {
			return ("Grade Too High Exception !"); }
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return ("Grade Too Low Exception !"); }
	};

private:

	std::string const	_name;
	int					_grade;

};

#endif
