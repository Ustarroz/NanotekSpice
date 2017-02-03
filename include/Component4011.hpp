//
// Created by puilla_e on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT4011_HPP
#define NANOTEKSPICE_COMPONENT4011_HPP

#include "AComponent.hpp"

namespace nts
{
  class Component4011 : public nts::AComponent
  {
    Component4011();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
  };
}

#endif //NANOTEKSPICE_COMPONENT4011_HPP
