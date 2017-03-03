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
  std::copy(cpy._comp.begin(), cpy._comp.end(), this->_comp.begin());
}

nts::AComponent &nts::AComponent::operator=(nts::AComponent &cpy)
{
  if (this == &cpy)
    return (*this);
  this->_name = cpy._name;
  std::copy(cpy._comp.begin(), cpy._comp.end(), this->_comp.begin());
  return (*this);
}

nts::AComponent::~AComponent()
{
  this->_comp.clear();
}

bool nts::AComponent::CheckPin(size_t pin_num)
{
  for (std::vector<nts::AComponent *>::iterator it = this->_comp.begin(); it != this->_comp.end(); ++it)
    {
      if ((*it)->CheckPin(pin_num))
	return (true);
    }
  return (false);
}

void nts::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  if ((static_cast<AComponent &>(component)).CheckPin(pin_num_target))
    return;
  for (std::vector<nts::AComponent *>::iterator it = this->_comp.begin(); it != this->_comp.end(); ++it)
    {
      if ((*it)->CheckPin(pin_num_this))
	{
	  (*it)->SetLink(pin_num_this, component, pin_num_target);
	  return ;
	}
    }
}

static void dump_sub(nts::AComponent const *comp)
{
  comp->Dump();
}

void nts::AComponent::Dump(void) const
{
  std::cout << "Component: "
	    << this->_name
	    << std::endl;
  std::for_each(this->_comp.begin(), this->_comp.end(), &dump_sub);
}

std::string const &nts::AComponent::getName() const
{
  return (this->_name);
}

nts::Tristate nts::AComponent::Compute(size_t pin_num_this)
{
  for (std::vector<nts::AComponent *>::iterator it = this->_comp.begin(); it !=this->_comp.end(); ++it)
    {
      if ((*it)->CheckPin(pin_num_this))
	{
	  return ((*it)->Compute(pin_num_this));
	}
    }
  return (nts::UNDEFINED);
}

void resetSubComp(nts::AComponent *comp)
{
  comp->reset();
}

void nts::AComponent::reset()
{
  std::for_each(this->_comp.begin(), this->_comp.end(), &resetSubComp);
}