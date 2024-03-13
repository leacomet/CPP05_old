/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:31 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:15 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
	
public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);

	std::string const	get_target() const;

	void	beSigned(Bureaucrat &src);
	bool	execute(Bureaucrat const & executor) const;


private:

    std::string		_target;

};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif
