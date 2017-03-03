//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentFalse.hpp"

nts::ComponentFalse::ComponentFalse(std::string const &name, size_t pin_out) : ComponentInput(name, pin_out, nts::FALSE)
{
}

nts::ComponentFalse::~ComponentFalse()
{
}

void nts::ComponentFalse::setValue(nts::Tristate value)
{
  (void) value;
}