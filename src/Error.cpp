//
// Created by robin ustarroz on 01/03/2017.
//

#include "Error.hpp"

Error::Error(std::string message, int iderror)
{
    this->iderror = iderror;
    this->message = message;
}

Error::Error(const Error &other)
{
    message = other.getMessage();
    iderror = other.getIderror();
}

Error Error::operator=(const Error &other)
{
    if (this != &other)
    {
        message = other.getMessage();
        iderror = other.getIderror();
    }
    return *this;
}

std::string Error::getMessage() const
{
    return message;
}

int Error::getIderror() const
{
    return iderror;
}