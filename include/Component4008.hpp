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
    AComponent *createFullAdder(size_t pin_a, size_t pin_b, size_t pin_c, size_t res, size_t carry_out,
				   AComponent *prev, size_t prev_carry);
   public:
    Component4008(std::string const &name = "");
  };
}

#endif //NANOTEKSPICE_COMPONENT4008_HPP
