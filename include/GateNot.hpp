//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_GATENOT_HPP
#define NANOTEKSPICE_GATENOT_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateNot : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateNot(size_t pin_in = 0, size_t pin_out = 1);
    virtual ~GateNot();
  };
};

#endif //NANOTEKSPICE_GATENOT_HPP
