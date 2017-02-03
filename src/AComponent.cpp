//
// Created by voyevoda on 31/01/17.
//

#include <iostream>
#include <algorithm>
#include "AComponent.hpp"

nts::AComponent::AComponent(std::string const &name): _name(name)
{
}

nts::AComponent::AComponent(const nts::AComponent &cpy): _name(cpy._name)
{
  copy(cpy._pins->begin(), cpy._pins->end(), this->_pins->begin());
}

nts::AComponent &nts::AComponent::operator=(nts::AComponent &cpy)
{
  if (this == &cpy)
    return (*this);
  this->_name = cpy._name;
  copy(cpy._pins->begin(), cpy._pins->end(), this->_pins->begin());
  return (*this);
}

nts::AComponent::~AComponent()
{
  delete this->_pins;
}

bool nts::AComponent::CheckPin(size_t pin_num)
{
  std::vector<t_pin>::iterator it;
  it = find(this->_pins->begin(), this->_pins->end(), pin_num);
  return (it != this->_pins->end());
}

void nts::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  if ((static_cast<AComponent &>(component)).CheckPin(pin_num_target))
    return;
  std::vector<t_pin>::iterator it;
  it = find(this->_pins->begin(), this->_pins->end(), pin_num_this);
  if (it != this->_pins->end())
    {
      it->link_comp = &component;
      it->link_pin = pin_num_target;
    }
}

static void dump_pin(nts::t_pin pin)
{
  if (pin.type == nts::OUT)
    std::cout << "pin: " << pin.pin_num << "; type: OUT; value : " << pin.value << ";";
  else
    std::cout << "pin: " << pin.pin_num << "; type: IN; value : " << pin.value << ";";
  if (pin.link_comp)
    std::cout << " link to pin " << pin.link_pin << " in component "
	      << (static_cast<nts::AComponent *>(pin.link_comp))->getName();
  std::cout << std::endl;
}

void nts::AComponent::Dump(void) const
{
  std::cout << "Component: "
	    << this->_name
	    << std::endl;
  for_each(this->_pins->begin(), this->_pins->end(), &dump_pin);
}

std::string const &nts::AComponent::getName() const
{
  return this->_name;
}

