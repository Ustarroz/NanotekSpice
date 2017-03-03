//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_COMPONENTINPUT_HPP
#define NANOTEKSPICE_COMPONENTINPUT_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class ComponentInput : public nts::ASubComponent
  {
    virtual Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    ComponentInput(std::string const &name = "", size_t pin_out = 0, Tristate value = UNDEFINED);
    virtual ~ComponentInput();

    virtual void setValue(Tristate value);
  };
};

#endif //NANOTEKSPICE_COMPONENTINPUT_HPP
