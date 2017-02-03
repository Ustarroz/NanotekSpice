//
// Created by puilla_e on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT4001_HPP
#define NANOTEKSPICE_COMPONENT4001_HPP

#include "AComponent.hpp"

namespace nts
{
  class Component4001 : public nts::AComponent
  {
    Component4001();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
  };
}

#endif //NANOTEKSPICE_COMPONENT4001_HPP
