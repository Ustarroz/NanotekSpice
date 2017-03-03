//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "GateNot.hpp"

nts::GateNot::GateNot(size_t pin_in, size_t pin_out) : ASubComponent("GateNot", pin_in, SIZE_MAX, pin_out)
{
}

nts::GateNot::~GateNot()
{
}

nts::Tristate nts::GateNot::SubCompute(std::vector<t_pin>::iterator jt)
{
  nts::Tristate in;

  ++jt;
  in = this->Compute(jt->link_pin);
  if (in == nts::UNDEFINED)
    return (nts::UNDEFINED);
  return (in == nts::TRUE ? nts::FALSE : nts::TRUE);
}