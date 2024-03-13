/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:31 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:15 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <cstdlib>

class	RobotomyRequestForm : public AForm
{
	
public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);

	std::string const	get_target() const;

	void	beSigned(Bureaucrat &src);
	bool	execute(Bureaucrat const & executor) const;


private:

    std::string		_target;

};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif
