//
// Created by puilla_e on 01/03/17.
//

#ifndef NANOTEKSPICE_SUBOR_HPP
#define NANOTEKSPICE_SUBOR_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateOr : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateOr(size_t pin_in_one = 0,
	  size_t pin_in_two = 1,
	  size_t pin_out = 2);
    virtual ~GateOr();
  };
};

#endif //NANOTEKSPICE_SUBOR_HPP
