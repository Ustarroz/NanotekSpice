//
// Created by puilla_e on 03/02/17.
//

#ifndef NANOTEKSPICE_GATE_HPP
#define NANOTEKSPICE_GATE_HPP

#include "AComponent.hpp"

namespace nts
{
  void pushTripletPin(std::vector<nts::t_pin> *_pins, size_t first_in, size_t second_in, size_t out);

  void pushDoublePin(std::vector<nts::t_pin> *_pins, size_t in, size_t out);

  nts::Tristate gateNor(nts::Tristate in_one, nts::Tristate in_two);

  nts::Tristate gateOr(nts::Tristate in_one, nts::Tristate in_two);

  nts::Tristate gateNand(nts::Tristate in_one, nts::Tristate in_two);

  nts::Tristate gateAnd(nts::Tristate in_one, nts::Tristate in_two);

  nts::Tristate gateXor(nts::Tristate in_one, nts::Tristate in_two);

  nts::Tristate gateXNor(nts::Tristate in_one, nts::Tristate in_two);

  nts::Tristate gateNot(nts::Tristate in);
}
#endif //NANOTEKSPICE_GATE_HPP
