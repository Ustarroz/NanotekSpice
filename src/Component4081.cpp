//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateAnd.hpp"
#include "Component4081.hpp"

nts::Component4081::Component4081(std::string const &name) : AComponent(name)
{
  this->_comp.push_back(new GateAnd(1, 2, 3));
  this->_comp.push_back(new GateAnd(5, 6, 4));
  this->_comp.push_back(new GateAnd(8, 9, 10));
  this->_comp.push_back(new GateAnd(12, 13, 11));
}