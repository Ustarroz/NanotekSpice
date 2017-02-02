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
  enum Pintype
  {
    OUT = 0,
    IN
  };

  typedef struct s_pin
  {
    size_t pin_num;
    Pintype type;
    Tristate value;
    bool linked;
    IComponent &link_comp;
    size_t link_pin;
  } t_pin;

  class AComponent : public nts::IComponent
  {
    std::string	_name;
    std::vector<nts::t_pin> *_pins;
   public:

    AComponent(std::string const &name, size_t const &pins);
    ~AComponent();
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;

    bool CheckPin(size_t pin_num);

    /// Useful to link IComponent together
    void SetLink(size_t pin_num_this,
		 nts::IComponent &component,
		 size_t pin_num_target);

    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won’t be tested, but it may help you
    /// as a trace.
    void Dump(void) const;

    std::string const &getName() const;

  };
};
#endif //NANOTEKSPICE_COMPONENT_HPP
