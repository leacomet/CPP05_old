/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:31 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:15 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class	Form
{
	
public:

	Form();
	Form(std::string name, int const sign_grade, int const exec_grade);
	Form(Form const &src);
	~Form();
	Form	&operator=(Form const &src);

	std::string const	&get_name() const;
	bool				get_signature() const;
	int					get_sign_grade() const;
	int					get_exec_grade() const;
	bool				set_signature();

	void	beSigned(Bureaucrat &src);

private:

	std::string const	_name;
	bool				_signature;
	int const			_sign_grade;
	int const			_exec_grade;

};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
