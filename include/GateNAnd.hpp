//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_GATENAND_HPP
#define NANOTEKSPICE_GATENAND_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateNAnd : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateNAnd(size_t pin_in_one = 0,
	   size_t pin_in_two = 1,
	   size_t pin_out = 2);
    virtual ~GateNAnd();
  };
};

#endif //NANOTEKSPICE_GATENAND_HPP
