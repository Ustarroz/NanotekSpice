//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_GATENULL_HPP
#define NANOTEKSPICE_GATENULL_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class GateNull : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    GateNull(size_t pin_in = 0, size_t pin_out = 1);
    virtual ~GateNull();
  };
};

#endif //NANOTEKSPICE_GATENULL_HPP
