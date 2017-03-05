//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_GATEXOR_HPP
#define NANOTEKSPICE_GATEXOR_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateXor : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateXor(size_t pin_in_one = 0,
	   size_t pin_in_two = 1,
	   size_t pin_out = 2);
    virtual ~GateXor();
  };
};

#endif //NANOTEKSPICE_GATEXOR_HPP
