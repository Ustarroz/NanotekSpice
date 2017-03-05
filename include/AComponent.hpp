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
    IComponent *link_comp;
    size_t link_pin;
    bool operator==(size_t pin_num) {
      return (this->pin_num == pin_num);
    };
    struct s_pin & operator=(struct s_pin &cpy) {
      this->pin_num = cpy.pin_num;
      this->type = cpy.type;
      this->value = cpy.value;
      this->link_comp = cpy.link_comp;
      this->link_pin = cpy.link_pin;
    };
  } t_pin;

  class AComponent : public nts::IComponent
  {
   protected:
    std::string	_name;
    std::vector<nts::t_pin> *_pins;
   public:

    AComponent(std::string const &name = "");
    AComponent(AComponent const & cpy);
    ~AComponent();
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;

    virtual bool CheckPin(size_t pin_num);

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

    AComponent & operator=(AComponent & cpy);
  };
};
#endif //NANOTEKSPICE_COMPONENT_HPP
