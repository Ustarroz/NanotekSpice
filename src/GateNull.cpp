//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "GateNull.hpp"

nts::GateNull::GateNull(size_t pin_in, size_t pin_out) : ASubComponent("GateNull", pin_in, SIZE_MAX, pin_out)
{
}

nts::GateNull::~GateNull()
{
}

nts::Tristate nts::GateNull::SubCompute(std::vector<t_pin>::iterator jt)
{
  ++jt;
  return (this->Compute(jt->pin_num));
}