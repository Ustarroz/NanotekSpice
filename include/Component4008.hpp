//
// Created by puilla_e on 03/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT4008_HPP
#define NANOTEKSPICE_COMPONENT4008_HPP

#include "AComponent.hpp"

namespace nts
{
  class Component4008 : public nts::AComponent
  {
    Component4008();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
  };
}

#endif //NANOTEKSPICE_COMPONENT4008_HPP
