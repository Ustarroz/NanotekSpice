//
// Created by puilla_e on 20/02/17.
//

#ifndef NANOTEKSPICE_ASUBCOMPONENT_HPP
#define NANOTEKSPICE_ASUBCOMPONENT_HPP

#include "AComponent.hpp"

namespace nts
{
  enum PinType
  {
    OUT = 0,
    IN
  };

  typedef struct s_pin
  {
    size_t pin_num;
    PinType type;
    Tristate value;
    IComponent *link_comp;
    size_t link_pin;
    bool done;
    bool innerpin;
    bool operator==(size_t pin_num) const {
      return (this->pin_num == pin_num);
    };
    struct s_pin & operator=(struct s_pin const &cpy) {
      this->pin_num = cpy.pin_num;
      this->type = cpy.type;
      this->value = cpy.value;
      this->link_comp = cpy.link_comp;
      this->link_pin = cpy.link_pin;
      this->done = cpy.done;
      return (*this);
    };
  } t_pin;

  class ASubComponent : public nts::AComponent
  {
   protected:
    std::vector<nts::t_pin> _pins;

    virtual nts::Tristate SubCompute(std::vector<t_pin>::iterator it) = 0;

   public:

    ASubComponent(std::string const &name = "",
		  size_t pin_in_one = 1,
		  size_t pin_in_two = SIZE_MAX,
		  size_t pin_out = 2);
    ASubComponent(ASubComponent const & cpy);
    virtual ~ASubComponent();

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

    virtual ASubComponent & operator=(ASubComponent & cpy);

    virtual void reset();

    virtual void SetInner(size_t max_outter);
  };
};

#endif //NANOTEKSPICE_ASUBCOMPONENT_HPP
