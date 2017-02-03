//
// Created by puilla_e on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT4071_HPP
#define NANOTEKSPICE_COMPONENT4071_HPP

#include "AComponent.hpp"

namespace nts
{
  class Component4071 : public nts::AComponent
  {
    Component4071();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
  };
}

#endif //NANOTEKSPICE_COMPONENT4071_HPP
