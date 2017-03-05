//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "GateNAnd.hpp"

nts::GateNAnd::GateNAnd(size_t pin_in_one,
			size_t pin_in_two,
			size_t pin_out) : ASubComponent("GateNAnd", pin_in_one, pin_in_two, pin_out)
{
}

nts::GateNAnd::~GateNAnd()
{
}

nts::Tristate nts::GateNAnd::SubCompute(std::vector<t_pin>::iterator jt)
{
  nts::Tristate in_one;
  nts::Tristate in_two;

  ++jt;
  in_one = this->Compute(jt->pin_num);
  ++jt;
  in_two = this->Compute(jt->pin_num);
  if (in_one == nts::TRUE && in_two == nts::TRUE)
    return (nts::FALSE);
  if (in_one == nts::FALSE || in_two == nts::FALSE)
    return (nts::TRUE);
  return (nts::UNDEFINED);
}