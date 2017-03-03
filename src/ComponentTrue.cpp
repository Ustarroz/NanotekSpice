//
// Created by puilla_e on 02/03/17.
//

#include <algorithm>
#include "ComponentTrue.hpp"

nts::ComponentTrue::ComponentTrue(std::string const &name, size_t pin_out) : ComponentInput(name, pin_out, nts::TRUE)
{
}

nts::ComponentTrue::~ComponentTrue()
{
}

void nts::ComponentTrue::setValue(nts::Tristate value)
{
  (void) value;
}