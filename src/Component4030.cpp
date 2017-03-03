//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateXor.hpp"
#include "Component4030.hpp"

nts::Component4030::Component4030(std::string const &name) : AComponent(name)
{
  this->_comp.push_back(new GateXor(1, 2, 3));
  this->_comp.push_back(new GateXor(5, 6, 4));
  this->_comp.push_back(new GateXor(8, 9, 10));
  this->_comp.push_back(new GateXor(12, 13, 11));
}