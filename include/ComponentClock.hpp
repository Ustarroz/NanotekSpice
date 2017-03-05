//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_COMPONENTCLOCK_HPP
#define NANOTEKSPICE_COMPONENTCLOCK_HPP

#include "ComponentInput.hpp"

namespace nts
{
  class ComponentClock : public nts::ComponentInput
  {
    bool _first;
    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    ComponentClock(std::string const &name = "");
    virtual ~ComponentClock();

    virtual void setValue(Tristate value);
    virtual void reset();
  };
};

#endif //NANOTEKSPICE_COMPONENTCLOCK_HPP
