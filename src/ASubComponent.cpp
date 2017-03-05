//
// Created by voyevoda on 31/01/17.
//

#include <iostream>
#include <algorithm>
#include "ASubComponent.hpp"

nts::ASubComponent::ASubComponent(std::string const &name,
				  size_t pin_in_one,
				  size_t pin_in_two,
				  size_t pin_out): AComponent(name)
{
  t_pin pin;

  pin.value = nts::UNDEFINED;
  pin.done = false;
  pin.innerpin = false;
  pin.link_comp = NULL;
  pin.type = nts::OUT;
  if (pin_out != SIZE_MAX)
    {
      pin.pin_num = pin_out;
      this->_pins.push_back(pin);
    }
  pin.type = nts::IN;
  if (pin_in_one != SIZE_MAX)
    {
      pin.pin_num = pin_in_one;
      this->_pins.push_back(pin);
    }
  if (pin_in_two != SIZE_MAX)
    {
      pin.pin_num = pin_in_two;
      this->_pins.push_back(pin);
    }
}

nts::ASubComponent::ASubComponent(const nts::ASubComponent &cpy): AComponent(cpy)
{
  std::copy(cpy._pins.begin(), cpy._pins.end(), this->_pins.begin());
}

nts::ASubComponent &nts::ASubComponent::operator=(nts::ASubComponent &cpy)
{
  if (this == &cpy)
    return (*this);
  this->_name = cpy._name;
  std::copy(cpy._comp.begin(), cpy._comp.end(), this->_comp.begin());
  std::copy(cpy._pins.begin(), cpy._pins.end(), this->_pins.begin());
  return (*this);
}

nts::ASubComponent::~ASubComponent()
{
  this->_pins.clear();
}

bool nts::ASubComponent::CheckPin(size_t pin_num) const
{
  std::vector<nts::t_pin>::const_iterator it = std::find(this->_pins.begin(), this->_pins.end(), pin_num);
  return (it != this->_pins.end() && !it->innerpin);
}

bool nts::ASubComponent::CheckInnerPin(size_t pin_num) const
{
  std::vector<nts::t_pin>::const_iterator it = std::find(this->_pins.begin(), this->_pins.end(), pin_num);
  return (it != this->_pins.end());
}

bool nts::ASubComponent::CheckPinOut(size_t pin_num) const
{
  std::vector<nts::t_pin>::const_iterator it = std::find(this->_pins.begin(), this->_pins.end(), pin_num);
  return (it != this->_pins.end() && it->type == nts::OUT);
}

void nts::ASubComponent::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  bool type_out;
  std::vector<nts::t_pin>::iterator it = std::find(this->_pins.begin(), this->_pins.end(), pin_num_this);

  if (it == this->_pins.end())
    {
      std::cerr << "Error: can't link pin " << pin_num_this
		<< " of '" << this->_name
		<< "' : non-existing pin!" << std::endl;
      return ;
    }
  else if (!(static_cast<AComponent &>(component)).CheckInnerPin(pin_num_target))
    {
      std::cerr << "Error: can't link pin " << pin_num_target
	      	<< " of '" << (static_cast<AComponent &>(component)).getName()
		<< "' : non-existing pin!" << std::endl;
      return ;
    }

  type_out = (static_cast<AComponent &>(component)).CheckPinOut(pin_num_target);
  if (it->type == nts::OUT && !type_out)
    return;
  else if (it->type == nts::OUT)
    {
      std::cerr << "Error: can't link pin " << pin_num_this
		<< " of '" << this->_name
		<< "' to the pin " << pin_num_target
		<< " of '" << (static_cast<AComponent &>(component)).getName()
		<< "' : trying to link two pin OUT!" << std::endl;
    }
  else if (!type_out)
    {
      std::cerr << "Error: can't link pin " << pin_num_this
		<< " of '" << this->_name
		<< "' to the pin " << pin_num_target
		<< " of '" << (static_cast<AComponent &>(component)).getName()
		<< "' : trying to link two pin IN!" << std::endl;
    }
  (*it).link_pin = pin_num_target;
  (*it).link_comp = &component;
}

void nts::ASubComponent::SetInner(size_t max_outter)
{
  for (std::vector<t_pin>::iterator it = this->_pins.begin(); it != this->_pins.end(); ++it)
    {
      if (it->pin_num > max_outter)
	it->innerpin = true;
    }
}

static void dump_pin(nts::t_pin const &pin)
{
  if (pin.type == nts::OUT)
    std::cout << "pin: " << pin.pin_num << "; type: OUT; value : " << pin.value << ";";
  else
    std::cout << "pin: " << pin.pin_num << "; type: IN; value : " << pin.value << ";";
  if (pin.link_comp)
    std::cout << " link to pin " << pin.link_pin << " in component "
	      << (static_cast<nts::ASubComponent *>(pin.link_comp))->getName();
  std::cout << std::endl;
}

void nts::ASubComponent::Dump(void) const
{
  std::cout << "SubComponent: "
	    << this->_name
	    << std::endl;
  std::for_each(this->_pins.begin(), this->_pins.end(), &dump_pin);
}

nts::Tristate nts::ASubComponent::Compute(size_t pin_num_this)
{
  std::vector<t_pin>::iterator it;
  nts::Tristate res;

  it = std::find(this->_pins.begin(), this->_pins.end(), pin_num_this);
  if (it == this->_pins.end())
    return (UNDEFINED);
  if (it->done)
    return (it->value);
  it->value = nts::UNDEFINED;
  it->done = true;
  if (it->type == IN)
    {
      if (it->link_comp != nullptr)
	res = it->link_comp->Compute(it->link_pin);
      else
	res = UNDEFINED;
    }
  else
    {
      res = this->SubCompute(it);
    }
  it->value = res;
  return (res);
}

static void resetPins(nts::t_pin &pin)
{
  pin.done = false;
}

void nts::ASubComponent::reset()
{
  std::for_each(this->_pins.begin(), this->_pins.end(), &resetPins);
}