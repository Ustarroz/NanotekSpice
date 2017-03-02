//
// Created by robin ustarroz on 01/03/2017.
//

#ifndef NANOTEKSPICE_ERROR_H
#define NANOTEKSPICE_ERROR_H

#include <string>

    class Error : public std::exception
    {
    private:

        std::string message;
        int         iderror;

    public:
        Error(std::string message, int iderror);
        Error(const Error &other);
        virtual ~Error() {};
        virtual Error operator=(const Error &other);
        std::string getMessage() const;
        int         getIderror() const;
    };

#endif //NANOTEKSPICE_ERROR_H
