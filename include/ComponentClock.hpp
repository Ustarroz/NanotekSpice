//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_COMPONENTCLOCK_HPP
#define NANOTEKSPICE_COMPONENTCLOCK_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class ComponentClock : public nts::ASubComponent
  {
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    ComponentClock(std::string const &name = "", size_t pin_out = 0);
    virtual ~ComponentClock();
  };
};

#endif //NANOTEKSPICE_COMPONENTCLOCK_HPP
