//
// Created by voyevoda on 31/01/17.
//

#include <iostream>
#include "AComponent.hpp"

nts::AComponent::AComponent(std::string const &name, size_t const &pins): _name(name), _pins(new std::vector<t_pin>)
{
}

nts::AComponent::~AComponent()
{
}

bool nts::AComponent::CheckPin(size_t pin_num)
{
  for (std::vector<t_pin>::iterator it = this->_pins->begin(); it != this->_pins->end(); ++it)
    {
      if (it->pin_num == pin_num)
	return true;
    }
  return false;
}


void nts::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  if ((static_cast<AComponent &>(component)).CheckPin(pin_num_target))
    return;
  for (std::vector<t_pin>::iterator it = this->_pins->begin(); it != this->_pins->end(); ++it)
    {
      if (it->pin_num == pin_num_this)
	{
	  it->link_comp = component;
	  it->linked = true;
	  it->link_pin = pin_num_target;
	  return;
	}
    }
}

void nts::AComponent::Dump(void) const
{
  std::cout << "Component: "
	    << this->_name
	    << std::endl;
  for (std::vector<t_pin>::iterator it = this->_pins->begin(); it != this->_pins->end(); ++it)
    {
      if (it->type == nts::OUT)
	std::cout << "pin: " << it->pin_num << "; type: OUT; value : " << it->value << ";";
      else
	std::cout << "pin: " << it->pin_num << "; type: IN; value : " << it->value << ";";
      if (it->linked)
	std::cout << " link to pin " << it->link_pin << " in component "
		  << (static_cast<AComponent &>(it->link_comp)).getName();
      std::cout << std::endl;
    }
}

std::string const &nts::AComponent::getName() const
{
  return this->_name;
}
