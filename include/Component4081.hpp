//
// Created by puilla_e on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT4081_HPP
#define NANOTEKSPICE_COMPONENT4081_HPP

#include "AComponent.hpp"

namespace nts
{
  class Component4081 : public nts::AComponent
  {
    Component4081();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
  };
}

#endif //NANOTEKSPICE_COMPONENT4081_HPP
