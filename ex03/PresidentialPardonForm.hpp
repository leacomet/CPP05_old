/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:31 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:15 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	
public:

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);

	std::string const	get_target() const;

	void	beSigned(Bureaucrat &src);
	bool	execute(Bureaucrat const & executor) const;


private:

    std::string		_target;

};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
