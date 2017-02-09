//
// Created by puilla_e on 03/02/17.
//

#include "Gate.hpp"

void nts::pushPin(std::vector <nts::t_pin> *_pins, size_t pin_in, nts::Pintype type)
{
  nts::t_pin pin;

  pin.value = nts::UNDEFINED;
  pin.link_comp = NULL;
  pin.type = type;
  pin.pin_num = pin_in;
  _pins->push_back(pin);
}

void nts::pushPinInside(std::vector <nts::t_pin> *_pins, size_t pin_in, size_t pin_out, AComponent *component)
{
  nts::t_pin pin;

  pin.value = nts::UNDEFINED;
  pin.link_comp = component;
  pin.link_pin = pin_out;
  pin.type = IN;
  pin.pin_num = pin_in;
  _pins->push_back(pin);
}

void nts::pushTripletPin(std::vector <nts::t_pin> *_pins, size_t first_in, size_t second_in, size_t out)
{
  nts::t_pin pin;

  pin.value = nts::UNDEFINED;
  pin.link_comp = NULL;
  pin.type = nts::OUT;
  pin.pin_num = out;
  _pins->push_back(pin);
  pin.type = nts::IN;
  pin.pin_num = first_in;
  _pins->push_back(pin);
  pin.pin_num = second_in;
  _pins->push_back(pin);
}

void nts::pushDoublePin(std::vector <nts::t_pin> *_pins, size_t in, size_t out)
{
  nts::t_pin pin;

  pin.value = nts::UNDEFINED;
  pin.link_comp = NULL;
  pin.type = nts::OUT;
  pin.pin_num = out;
  _pins->push_back(pin);
  pin.type = nts::IN;
  pin.pin_num = in;
  _pins->push_back(pin);
}

nts::Tristate nts::gateNot(nts::Tristate in)
{
  if (in == nts::UNDEFINED)
    return (nts::UNDEFINED);
  return (in == nts::TRUE ? nts::FALSE : nts::TRUE);
}

nts::Tristate nts::gateOr(nts::Tristate in_one, nts::Tristate in_two)
{
  if (in_one == nts::TRUE || in_two == nts::TRUE)
    return (nts::TRUE);
  if (in_one == nts::UNDEFINED || in_two == nts::UNDEFINED)
    return (nts::UNDEFINED);
  return (nts::FALSE);
}

nts::Tristate nts::gateAnd(nts::Tristate in_one, nts::Tristate in_two)
{
  if (in_one == nts::TRUE && in_two == nts::TRUE)
    return (nts::TRUE);
  if (in_one == nts::FALSE || in_two == nts::FALSE)
    return (nts::FALSE);
  return (nts::UNDEFINED);
}

nts::Tristate nts::gateNor(nts::Tristate in_one, nts::Tristate in_two)
{
  return (gateNot(gateOr(in_one, in_two)));
}

nts::Tristate nts::gateNand(nts::Tristate in_one, nts::Tristate in_two)
{
  return (gateNot(gateAnd(in_one, in_two)));
}

nts::Tristate nts::gateXor(nts::Tristate in_one, nts::Tristate in_two)
{
  if (in_one == nts::UNDEFINED || in_two == nts::UNDEFINED)
    return (nts::UNDEFINED);
  if ((in_one == nts::FALSE && in_two == nts::FALSE) ||
      (in_one == nts::TRUE && in_two == nts::TRUE))
    return nts::FALSE;
  return (nts::TRUE);
}

nts::Tristate nts::gateXNor(nts::Tristate in_one, nts::Tristate in_two)
{
  return (gateNot(gateXor(in_one, in_two)));
}