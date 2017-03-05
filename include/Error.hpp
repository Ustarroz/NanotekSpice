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
  virtual ~Error() throw() {};
  virtual Error operator=(const Error &other);
  virtual const char * what() const throw() {
    return (message.c_str());
  };
  std::string getMessage() const;
  int         getIderror() const;
};

#endif //NANOTEKSPICE_ERROR_H
