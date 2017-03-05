//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput(std::string const &name) :
	ASubComponent(name, 1, SIZE_MAX, SIZE_MAX)
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

nts::Tristate nts::ComponentOutput::getValue() const
{
  std::vector<nts::t_pin>::const_iterator it;

  it = this->_pins.begin();
  return ((*it).value);
}

void nts::ComponentOutput::simulate()
{
  std::vector<t_pin>::iterator it;

  it = this->_pins.begin();
  this->Compute((*it).pin_num);
}

bool nts::ComponentOutput::CheckLink() const
{
  std::vector<t_pin>::const_iterator it;

  it = this->_pins.begin();
  return (it->link_comp != NULL);
}