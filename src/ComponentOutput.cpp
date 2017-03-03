//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput(std::string const &name, size_t pin_in) :
	ASubComponent(name, pin_in, SIZE_MAX, SIZE_MAX)
{
}

nts::ComponentOutput::~ComponentOutput()
{
}

nts::Tristate nts::ComponentOutput::SubCompute(std::vector<t_pin>::iterator jt)
{
  (void) jt;
  return (nts::UNDEFINED);
}