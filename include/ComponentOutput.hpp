//
// Created by puilla_e on 02/03/17.
//

#ifndef NANOTEKSPICE_COMPONENTOUTPUT_HPP
#define NANOTEKSPICE_COMPONENTOUTPUT_HPP

#include "ASubComponent.hpp"

namespace nts
{
  class ComponentOutput : public nts::ASubComponent
  {
    virtual Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    ComponentOutput(std::string const &name = "", size_t pin_in = 0);
    virtual ~ComponentOutput();
  };
};

#endif //NANOTEKSPICE_COMPONENTOUTPUT_HPP
