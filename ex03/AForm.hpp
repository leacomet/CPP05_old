/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:31 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:15 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class	AForm
{
	
public:

	AForm();
	AForm(std::string name, int const sign_grade, int const exec_grade);
	AForm(AForm const &src);
	virtual ~AForm();
	AForm	&operator=(AForm const &src);

	std::string const	&get_name() const;
	bool				get_signature() const;
	int					get_sign_grade() const;
	int					get_exec_grade() const;
	void				set_signature(bool i);

	virtual void	beSigned(Bureaucrat &src) = 0;
	virtual bool	execute(Bureaucrat const & executor) const = 0;

private:

	std::string const	_name;
	bool				_signature;
	int const			_sign_grade;
	int const			_exec_grade;

};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
