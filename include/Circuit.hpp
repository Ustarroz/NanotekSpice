//
// Created by puilla_e on 03/03/17.
//

#ifndef NANOTEKSPICE_CIRCUIT_HPP
#define NANOTEKSPICE_CIRCUIT_HPP

#include "ComponentOutput.hpp"
#include "ComponentInput.hpp"
#include "Parser.hpp"

namespace nts
{
  enum Commands
  {
    EXIT = 0,
    DISPLAY,
    SIMULATE,
    LOOP,
    DUMP,
    NB_COMMAND
  };

  enum ComponentType
  {
    COMP_INPUT = 0,
    COMP_FALSE,
    COMP_TRUE,
    COMP_CLOCK,
    COMP_OUTPUT,
    COMP_4001,
    COMP_4008,
    COMP_4011,
    COMP_4030,
    COMP_4069,
    COMP_4071,
    COMP_4081,
    NB_COMPONENT
  };

  class Circuit
  {
   private:
    std::vector<nts::AComponent *> _comp;
    std::vector<nts::ComponentOutput *> _out;
    std::vector<nts::ComponentInput *> _in;
    std::string _cmd[NB_COMMAND];
    std::string _typecomp[NB_COMPONENT];
    bool _started;

    void reset();
    void display() const;
    void simulate();
    void loop();
    void dump() const;
    void createComp(std::string const &comp, std::string const & name);
    void setLink(std::string const &comp_in, size_t pin_in, std::string const & comp_out, size_t pin_out);
    AComponent *findComponent(std::string const & name);
    void createComponents(nts::t_ast_node *comp);
    void createLinks(nts::t_ast_node *links);
   public:
    Circuit(nts::t_ast_node *root);
    Circuit(Circuit const &cpy);
    ~Circuit();
    Circuit &operator=(Circuit const &cpy);
    void setInput(std::string const & input);
    void checkCircuit();
    bool execute_command(std::string const & cmd);
  };
}

#endif //NANOTEKSPICE_CIRCUIT_HPP
