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
   protected:
    virtual Tristate SubCompute(std::vector<t_pin>::iterator it);
   public:

    ComponentOutput(std::string const &name = "");
    virtual ~ComponentOutput();
    nts::Tristate getValue() const;
    void simulate();

    bool CheckLink() const;
  };
};

#endif //NANOTEKSPICE_COMPONENTOUTPUT_HPP
