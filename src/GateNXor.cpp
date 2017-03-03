//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "GateNXor.hpp"

nts::GateNXor::GateNXor(size_t pin_in_one,
		    size_t pin_in_two,
		    size_t pin_out) : ASubComponent("GateNXor", pin_in_one, pin_in_two, pin_out)
{
}

nts::GateNXor::~GateNXor()
{
}

nts::Tristate nts::GateNXor::SubCompute(std::vector<t_pin>::iterator jt)
{
  nts::Tristate in_one;
  nts::Tristate in_two;

  ++jt;
  in_one = this->Compute(jt->link_pin);
  ++jt;
  in_two = this->Compute(jt->link_pin);
  if (in_one == nts::UNDEFINED || in_two == nts::UNDEFINED)
    return (nts::UNDEFINED);
  if ((in_one == nts::FALSE && in_two == nts::FALSE) ||
      (in_one == nts::TRUE && in_two == nts::TRUE))
    return nts::TRUE;
  return (nts::FALSE);
}