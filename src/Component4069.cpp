//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateNot.hpp"
#include "Component4069.hpp"

nts::Component4069::Component4069(std::string const &name) : AComponent(name)
{
  this->_comp.push_back(new GateNot(1, 2));
  this->_comp.push_back(new GateNot(3, 4));
  this->_comp.push_back(new GateNot(5, 6));
  this->_comp.push_back(new GateNot(9, 8));
  this->_comp.push_back(new GateNot(11, 10));
  this->_comp.push_back(new GateNot(13, 12));
}