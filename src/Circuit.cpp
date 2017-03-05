//
// Created by puilla_e on 03/03/17.
//

#include <algorithm>
#include <iostream>
#include <signal.h>
#include "Error.hpp"
#include "Component4081.hpp"
#include "Component4071.hpp"
#include "Component4069.hpp"
#include "Component4030.hpp"
#include "Component4011.hpp"
#include "Component4008.hpp"
#include "Component4001.hpp"
#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentClock.hpp"
#include "Circuit.hpp"

bool end_loop = false;

nts::Circuit::Circuit(nts::t_ast_node *root)
{
  (void) root;
  this->_cmd[EXIT] = "exit";
  this->_cmd[DISPLAY] = "display";
  this->_cmd[SIMULATE] = "simulate";
  this->_cmd[LOOP] = "loop";
  this->_cmd[DUMP] = "dump";

  this->_typecomp[COMP_INPUT] = "input";
  this->_typecomp[COMP_OUTPUT] = "output";
  this->_typecomp[COMP_FALSE] = "false";
  this->_typecomp[COMP_TRUE] = "true";
  this->_typecomp[COMP_CLOCK] = "clock";
  this->_typecomp[COMP_4001] = "4001";
  this->_typecomp[COMP_4008] = "4008";
  this->_typecomp[COMP_4011] = "4011";
  this->_typecomp[COMP_4030] = "4030";
  this->_typecomp[COMP_4069] = "4069";
  this->_typecomp[COMP_4071] = "4071";
  this->_typecomp[COMP_4081] = "4081";
  createComp("input", "i0");
  createComp("input", "i1");
  createComp("input", "i2");
  createComp("4081", "and0");
  createComp("output", "out");
  setLink("i0", 1, "and0", 1);
  setLink("i1", 1, "and0", 2);
  setLink("and0", 3, "and0", 5);
  setLink("i2", 1, "and0", 6);
  setLink("and0", 4, "out", 1);
}

nts::Circuit::Circuit(Circuit const &cpy)
{
  std::copy(cpy._comp.begin(), cpy._comp.end(), this->_comp.begin());
  std::copy(cpy._out.begin(), cpy._out.end(), this->_out.begin());
  std::copy(cpy._in.begin(), cpy._in.end(), this->_in.begin());
  for (int i = 0; i != NB_COMMAND; i++)
    {
      this->_cmd[i] = cpy._cmd[i];
    }
}

static void clearComp(nts::AComponent *comp)
{
  delete comp;
}

nts::Circuit::~Circuit()
{
  std::for_each(this->_comp.begin(), this->_comp.end(), &clearComp);
  std::for_each(this->_out.begin(), this->_out.end(), &clearComp);
  std::for_each(this->_in.begin(), this->_in.end(), &clearComp);
}

nts::Circuit & nts::Circuit::operator=(nts::Circuit const &cpy)
{
  std::copy(cpy._comp.begin(), cpy._comp.end(), this->_comp.begin());
  std::copy(cpy._out.begin(), cpy._out.end(), this->_out.begin());
  std::copy(cpy._in.begin(), cpy._in.end(), this->_in.begin());
  return (*this);
}

static void resetComp(nts::AComponent *comp)
{
  comp->reset();
}

void nts::Circuit::reset()
{
  std::for_each(this->_comp.begin(), this->_comp.end(), &resetComp);
  std::for_each(this->_out.begin(), this->_out.end(), &resetComp);
  std::for_each(this->_in.begin(), this->_in.end(), &resetComp);
}

static void displayOutput(nts::ComponentOutput *out)
{
  nts::Tristate value = out->getValue();

  if (value == nts::UNDEFINED)
    std::cout << out->getName() << "=-1" << std::endl;
  else if (value == nts::TRUE)
      std::cout << out->getName() << "=1" << std::endl;
  else
      std::cout << out->getName() << "=0" << std::endl;
}

void nts::Circuit::display() const
{
  std::for_each(this->_out.begin(), this->_out.end(), &displayOutput);
}

void nts::Circuit::setInput(std::string const & input)
{
  std::vector<nts::ComponentInput *>::iterator it;
  std::string name;
  std::string value_str;
  nts::Tristate  value;
  size_t pos;

  if ((pos = input.find_first_of('=')) == std::string::npos)
    {
      std::cerr << "Error: '" << input << "' is an incorrect command" << std::endl;
      throw Error("Circuit: command error", -1);
    }
  name = input.substr(0, pos);
  value_str = input.substr(pos + 1);

  for (it = this->_in.begin(); it != this->_in.end(); ++it)
    {
      if ((*it)->getName() == name)
	break;
    }
  if (it == this->_in.end())
    {
      std::cerr << "Error: '" << name << "' is an incorrect input" << std::endl;
      throw Error("Circuit: input error", -1);
    }

  if (value_str == "1")
    value = nts::TRUE;
  else if (value_str == "0")
      value = nts::FALSE;
  else
    {
      std::cerr << "Error: '" << value_str << "' is an incorrect value" << std::endl;
      throw Error("Circuit: input error", -1);
    }
  (*it)->setValue(value);
}

static void simulateOutput(nts::ComponentOutput *out)
{
  out->simulate();
}

void nts::Circuit::simulate()
{
  std::for_each(this->_out.begin(), this->_out.end(), &simulateOutput);
  this->reset();
}

static void my_handler (int param)
{
  (void) param;
  end_loop = true;
}

void nts::Circuit::loop()
{
  signal (SIGINT, my_handler);

  while (!end_loop)
    {
      this->simulate();
    }
  this->display();
  end_loop = false;
  signal(SIGINT, SIG_DFL);
}

static void dumpComp(nts::AComponent *comp)
{
  comp->Dump();
}


void nts::Circuit::dump() const
{
  std::cout << "Input:" << std::endl;
  std::for_each(this->_in.begin(), this->_in.end(), &dumpComp);

  std::cout << std::endl << "Output:" << std::endl;
  std::for_each(this->_out.begin(), this->_out.end(), &dumpComp);

  std::cout << std::endl << "Component:" << std::endl;
  std::for_each(this->_comp.begin(), this->_comp.end(), &dumpComp);
  std::cout << std::endl;
}

bool nts::Circuit::execute_command(std::string const & cmd)
{
  size_t cmd_pos;

  for (cmd_pos = EXIT; cmd_pos != NB_COMMAND; cmd_pos++)
    {
      if (this->_cmd[cmd_pos] == cmd)
	break;
    }
  switch (cmd_pos)
    {
      case (EXIT):
	{
	  return (false);
	}
      case (DISPLAY):
	{
	  this->display();
	  break;
	}
      case (SIMULATE):
	{
	  this->simulate();
	  break;
	}
      case (LOOP):
	{
	  this->loop();
	  break;
	}
      case (DUMP):
	{
	  this->dump();
	  break;
	}
      default:
	{
	  this->setInput(cmd);
	  break;
	}
    }
  return (true);
}

void nts::Circuit::createComp(std::string const &comp, std::string const & name)
{
  size_t pos;

  for (pos = 0; pos != NB_COMPONENT; pos++)
    {
      if (comp == this->_typecomp[pos])
	break;
    }
  switch (pos)
    {
      case (COMP_INPUT):
	{
	  this->_in.push_back(new ComponentInput(name));
	  break;
	}
      case (COMP_OUTPUT):
	{
	  this->_out.push_back(new ComponentOutput(name));
	  break;
	}
      case (COMP_CLOCK):
	{
	  this->_in.push_back(new ComponentClock(name));
	  break;
	}
      case (COMP_FALSE):
	{
	  this->_in.push_back(new ComponentFalse(name));
	  break;
	}
      case (COMP_TRUE):
	{
	  this->_in.push_back(new ComponentTrue(name));
	  break;
	}
      case (COMP_4001):
	{
	  this->_comp.push_back(new Component4001(name));
	  break;
	}
      case (COMP_4008):
	{
	  this->_comp.push_back(new Component4008(name));
	  break;
	}
      case (COMP_4011):
	{
	  this->_comp.push_back(new Component4011(name));
	  break;
	}
      case (COMP_4030):
	{
	  this->_comp.push_back(new Component4030(name));
	  break;
	}
      case (COMP_4069):
	{
	  this->_comp.push_back(new Component4069(name));
	  break;
	}
      case (COMP_4071):
	{
	  this->_comp.push_back(new Component4071(name));
	  break;
	}
      case (COMP_4081):
	{
	  this->_comp.push_back(new Component4081(name));
	  break;
	}
      default:
	{
	  std::cerr << "Error: '" << comp << "' is an incorrect component" << std::endl;
	  throw Error("Circuit: component error", -1);
	}
    }
}

nts::AComponent *nts::Circuit::findComponent(std::string const & name)
{
  for (std::vector<nts::ComponentInput *>::iterator it = this->_in.begin(); it != this->_in.end(); ++it)
    {
      if ((*it)->getName() == name)
	{
	  return (*it);
	}
    }
  for (std::vector<nts::ComponentOutput *>::iterator jt = this->_out.begin(); jt != this->_out.end(); ++jt)
    {
      if ((*jt)->getName() == name)
	{
	  return (*jt);
	}
    }
  for (std::vector<nts::AComponent *>::iterator kt = this->_comp.begin(); kt != this->_comp.end(); ++kt)
    {
      if ((*kt)->getName() == name)
	{
	  return (*kt);
	}
    }
  std::cerr << "Error: '" << name << "' is an unknown component" << std::endl;
  throw Error("Circuit: component error", -1);
  return (NULL);
}

void nts::Circuit::setLink(std::string const &name_comp_in, size_t pin_in,
			   std::string const &name_comp_out, size_t pin_out)
{
  AComponent *comp_in;
  AComponent *comp_out;

  comp_in = findComponent(name_comp_in);
  comp_out = findComponent(name_comp_out);

  if (!comp_in->CheckPin(pin_in))
    {
      std::cerr << "Error: can't link pin " << pin_in
		<< " of '" << comp_in->getName()
		<< "' : non-existing pin!" << std::endl;
      throw Error("Circuit: link error", -1);
    }
  if (!comp_out->CheckPin(pin_out))
    {
      std::cerr << "Error: can't link pin " << pin_out
		<< " of '" << comp_out->getName()
		<< "' : non-existing pin!" << std::endl;
      throw Error("Circuit: link error", -1);
    }

  comp_in->SetLink(pin_in, *comp_out, pin_out);
  comp_out->SetLink(pin_out, *comp_in, pin_in);
}

static void check_output(nts::ComponentOutput *out)
{
  if (out->CheckLink())
    return;
  std::cerr << "Error: output '" << out->getName() << "' is not linked" << std::endl;
  throw Error("Circuit: output error", -1);
}

static void check_input(nts::ComponentInput *in)
{
  if (in->CheckValue())
    return;
  std::cerr << "Error: input '" << in->getName() << "' is undefined" << std::endl;
  throw Error("Circuit: input error", -1);
}

void nts::Circuit::checkCircuit() const
{
  std::for_each(this->_in.begin(), this->_in.end(), &check_input);
  std::for_each(this->_out.begin(), this->_out.end(), &check_output);
}