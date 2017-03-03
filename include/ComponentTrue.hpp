//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_COMPONENTTRUE_HPP
#define NANOTEKSPICE_COMPONENTTRUE_HPP

#include "ComponentInput.hpp"

namespace nts
{
  class ComponentTrue : public nts::ComponentInput
  {
   public:

    ComponentTrue(std::string const &name = "", size_t pin_in = 0);
    virtual ~ComponentTrue();

    virtual void setValue(Tristate value);
  };
};

#endif //NANOTEKSPICE_COMPONENTTRUE_HPP
