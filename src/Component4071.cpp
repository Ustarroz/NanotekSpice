//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateOr.hpp"
#include "Component4071.hpp"

nts::Component4071::Component4071(std::string const &name) : AComponent(name)
{
  this->_comp.push_back(new GateOr(1, 2, 3));
  this->_comp.push_back(new GateOr(5, 6, 4));
  this->_comp.push_back(new GateOr(8, 9, 10));
  this->_comp.push_back(new GateOr(12, 13, 11));
}