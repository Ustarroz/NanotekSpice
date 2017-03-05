//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateXor.hpp"
#include "GateOr.hpp"
#include "GateAnd.hpp"
#include "Component4008.hpp"
#include "GateNull.hpp"

nts::Component4008::Component4008(std::string const &name) : AComponent(name)
{
  AComponent *prev;

  prev = this->createFullAdder(6, 7, 9, 10, 180, NULL, 0);
  prev = this->createFullAdder(4, 5, 197, 11, 198, prev, 180);
  prev = this->createFullAdder(2, 3, 215, 12, 216, prev, 198);
  this->createFullAdder(15, 1, 233, 13, 14, prev, 216);
}

nts::AComponent* nts::Component4008::createFullAdder(size_t pin_a,
						     size_t pin_b,
						     size_t pin_c,
						     size_t res,
						     size_t carry_out,
						     AComponent *prev,
						     size_t prev_carry)
{
  GateXor *ab_xor_gate;
  GateXor *res_xor_gate;
  GateAnd *ab_and_gate;
  GateAnd *res_and_gate;
  GateOr *or_gate;
  GateNull *null_gate_a;
  GateNull *null_gate_b;
  GateNull *null_gate_c;

  null_gate_a = new GateNull(pin_a, res * 18 + 8);
  null_gate_b = new GateNull(pin_b, res * 18 + 11);
  null_gate_c = new GateNull(pin_c, res * 18 + 14);

  ab_xor_gate = new GateXor(res * 18 + 9, res * 18 + 12, res * 18 + 1);
  res_xor_gate = new GateXor(res * 18 + 2, res * 18 + 15, res);
  ab_and_gate = new GateAnd(res * 18 + 10, res * 18 + 13, res * 18 + 3);
  res_and_gate = new GateAnd(res * 18 + 4, res * 18 + 16, res * 18 + 5);
  or_gate = new GateOr(res * 18 + 6, res * 18 + 7, carry_out);

  res_xor_gate->SetLink(res * 18 + 2, *ab_xor_gate, res * 18 + 1);
  res_and_gate->SetLink(res * 18 + 4, *ab_xor_gate, res * 18 + 1);
  or_gate->SetLink(res * 18 + 6, *res_and_gate, res * 18 + 5);
  or_gate->SetLink(res * 18 + 7, *ab_and_gate, res * 18 + 3);

  ab_xor_gate->SetLink(res * 18 + 9, *null_gate_a, res * 18 + 8);
  ab_and_gate->SetLink(res * 18 + 10, *null_gate_a, res * 18 + 8);

  ab_xor_gate->SetLink(res * 18 + 12, *null_gate_b, res * 18 + 11);
  ab_and_gate->SetLink(res * 18 + 13, *null_gate_b, res * 18 + 11);

  res_xor_gate->SetLink(res * 18 + 15, *null_gate_c, res * 18 + 14);
  res_and_gate->SetLink(res * 18 + 16, *null_gate_c, res * 18 + 14);

  if (prev)
    null_gate_c->SetLink(pin_c, *prev, prev_carry);

  this->_comp.push_back(ab_xor_gate);
  this->_comp.push_back(res_xor_gate);
  this->_comp.push_back(ab_and_gate);
  this->_comp.push_back(res_and_gate);
  this->_comp.push_back(or_gate);
  this->_comp.push_back(null_gate_a);
  this->_comp.push_back(null_gate_b);
  this->_comp.push_back(null_gate_c);
  return (or_gate);
}