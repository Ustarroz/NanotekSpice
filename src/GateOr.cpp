//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "GateOr.hpp"

nts::GateOr::GateOr(size_t pin_in_one,
		    size_t pin_in_two,
		    size_t pin_out) : ASubComponent("GateOr", pin_in_one, pin_in_two, pin_out)
{
}

nts::GateOr::~GateOr()
{
}

nts::Tristate nts::GateOr::SubCompute(std::vector<t_pin>::iterator jt)
{
  nts::Tristate in_one;
  nts::Tristate in_two;

  ++jt;
  in_one = this->Compute(jt->link_pin);
  ++jt;
  in_two = this->Compute(jt->link_pin);
  if (in_one == nts::TRUE || in_two == nts::TRUE)
    return (nts::TRUE);
  if (in_one == nts::UNDEFINED || in_two == nts::UNDEFINED)
    return (nts::UNDEFINED);
  return (nts::FALSE);
}