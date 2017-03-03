//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateXor.hpp"
#include "GateOr.hpp"
#include "GateAnd.hpp"
#include "Component4008.hpp"

nts::Component4008::Component4008(std::string const &name) : AComponent(name)
{
  this->createFullAdder(6, 7, 9, 10, 100);
  this->createFullAdder(4, 5, 100, 11, 110);
  this->createFullAdder(2, 3, 110, 12, 120);
  this->createFullAdder(15, 1, 120, 13, 14);
}

void nts::Component4008::createFullAdder(size_t pin_a,
					 size_t pin_b,
					 size_t pin_c,
					 size_t res,
					 size_t carry_out)
{
  GateXor *ab_xor_gate;
  GateXor *res_xor_gate;
  GateAnd *ab_and_gate;
  GateAnd *res_and_gate;
  GateOr *or_gate;

  ab_xor_gate = new GateXor(pin_a, pin_b, res * 10 + 1);
  res_xor_gate = new GateXor(res * 10 + 2, pin_c, res);
  ab_and_gate = new GateAnd(pin_a, pin_b, res * 10 + 3);
  res_and_gate = new GateAnd(res * 10 + 4, pin_c, res * 10 + 5);
  or_gate = new GateOr(res * 10 + 6, res * 10 + 7, carry_out);
  res_xor_gate->SetLink(res * 10 + 2, *ab_xor_gate, res * 10 + 1);
  res_and_gate->SetLink(res * 10 + 4, *ab_xor_gate, res * 10 + 1);
  or_gate->SetLink(res * 10 + 6, *res_and_gate, res * 10 + 5);
  or_gate->SetLink(res * 10 + 7, *ab_and_gate, res * 10 + 3);
  this->_comp.push_back(ab_xor_gate);
  this->_comp.push_back(res_xor_gate);
  this->_comp.push_back(ab_and_gate);
  this->_comp.push_back(res_and_gate);
  this->_comp.push_back(or_gate);
}