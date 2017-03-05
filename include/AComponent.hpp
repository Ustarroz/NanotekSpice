//
// Created by voyevoda on 02/02/17.
//

#ifndef NANOTEKSPICE_COMPONENT_HPP
#define NANOTEKSPICE_COMPONENT_HPP

#include <string>
#include <vector>
#include "ICcomponent.hpp"

namespace nts
{
  class AComponent : public nts::IComponent
  {
   protected:
    std::string	_name;
    std::vector<nts::AComponent *> _comp;
   public:

    AComponent(std::string const &name = "");
    AComponent(AComponent const & cpy);
    virtual ~AComponent();
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1);

    virtual bool CheckPin(size_t pin_num) const;

    virtual bool CheckInnerPin(size_t pin_num) const;

    virtual bool CheckPinOut(size_t pin_num) const;

    /// Useful to link IComponent together
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target);

    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won’t be tested, but it may help you
    /// as a trace.
    virtual void Dump(void) const;

    std::string const &getName() const;

    AComponent & operator=(AComponent const & cpy);

    virtual void reset();

    virtual void SetInner(size_t max_outter);
  };
};

#endif //NANOTEKSPICE_COMPONENT_HPP
