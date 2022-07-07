/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <iostream>
#include <exception>

namespace AbstractVM {
    class Exception : public std::exception {
        public:
            Exception (std::string const &msg) throw();
            virtual ~Exception() throw();
            Exception(const Exception &other) = default;
            Exception &operator=(const Exception &other) = default;

            virtual const char* what() const throw();

        protected:
        private:
            std::string	_str;
    };
}

#endif /* !EXCEPTION_HPP_ */