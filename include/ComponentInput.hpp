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

    ComponentInput(std::string const &name = "");
    virtual ~ComponentInput();

    virtual void setValue(Tristate value);
    virtual nts::Tristate Compute(size_t pin_num_this);
    bool CheckValue() const;
  };
};

#endif //NANOTEKSPICE_COMPONENTINPUT_HPP
