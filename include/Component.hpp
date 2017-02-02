//
// Created by voyevoda on 02/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT_HPP
#define NANOTEKSPICE_COMPONENT_HPP

namespace nts
{
#include <stdio>

  class Component : public ICcomponent
  {
    std::string	name;
    std::vector<pin>;
   public:

    Component(std::string const &name, size_t const &pins);
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1);

    /// Useful to link IComponent together
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target);

    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won’t be tested, but it may help you
    /// as a trace.
    virtual void Dump(void) const;

    virtual ~IComponent(void)
    {}
  };
};
#endif //NANOTEKSPICE_COMPONENT_HPP
