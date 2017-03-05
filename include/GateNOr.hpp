//
// Created by puilla_e on 01/03/17.
//

#ifndef NANOTEKSPICE_SUBNOR_HPP
#define NANOTEKSPICE_SUBNOR_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateNOr : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateNOr(size_t pin_in_one = 0,
	  size_t pin_in_two = 1,
	  size_t pin_out = 2);
    virtual ~GateNOr();
  };
};

#endif //NANOTEKSPICE_SUBNOR_HPP
