//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_GATENXOR_HPP
#define NANOTEKSPICE_GATENXOR_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateNXor : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateNXor(size_t pin_in_one = 0,
	   size_t pin_in_two = 1,
	   size_t pin_out = 2);
    virtual ~GateNXor();
  };
};

#endif //NANOTEKSPICE_GATENXOR_HPP
