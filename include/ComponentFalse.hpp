//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_COMPONENTFALSE_HPP
#define NANOTEKSPICE_COMPONENTFALSE_HPP

#include "ComponentInput.hpp"

namespace nts
{
  class ComponentFalse : public nts::ComponentInput
  {
   public:

    ComponentFalse(std::string const &name = "", size_t pin_in = 0);
    virtual ~ComponentFalse();

    virtual void setValue(Tristate value);
  };
};

#endif //NANOTEKSPICE_COMPONENTFALSE_HPP
