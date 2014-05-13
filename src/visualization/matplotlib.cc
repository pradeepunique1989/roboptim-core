// Copyright (C) 2014 by Benjamin Chrétien, CNRS-LIRMM.
//
// This file is part of the roboptim.
//
// roboptim is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// roboptim is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with roboptim.  If not, see <http://www.gnu.org/licenses/>.

#include "roboptim/core/config.hh"
#include "config.h"

#include <iostream>

#include <roboptim/core/visualization/matplotlib.hh>
#include <roboptim/core/visualization/matplotlib-commands.hh>
#include <roboptim/core/indent.hh>

namespace roboptim
{
  namespace visualization
  {
    Matplotlib::Matplotlib (bool with_header)
      : withHeader_ (with_header)
    {
      resetImports ();
    }

    Matplotlib::~Matplotlib ()
    {
    }

    void
    Matplotlib::resetImports ()
    {
      imports_.clear ();
      imports_.push_back (std::string ("matplotlib.pyplot as plt"));
      imports_.push_back (std::string ("numpy as np"));
    }

    void
    Matplotlib::push_command (const matplotlib::Command& cmd)
    {
      commands_.push_back (cmd);
    }

    void
    Matplotlib::push_import (const matplotlib::Import& import)
    {
      imports_.push_back (import);
    }

    std::ostream&
    Matplotlib::print (std::ostream& o) const
    {
      typedef std::vector<matplotlib::Import>::const_iterator citer_imp_t;
      typedef std::vector<matplotlib::Command>::const_iterator citer_cmd_t;

      if (withHeader_)
	{
	  o << "#!/usr/bin/env python" << std::endl;
	  o << "# Generated by " PACKAGE_NAME << std::endl;

	  for (citer_imp_t it = imports_.begin (); it != imports_.end (); ++it)
	    o << "import " << it->package () << std::endl;

	  o << std::endl;
	  o << "plt.figure ()" << std::endl;
	  o << std::endl;
	}

      for (citer_cmd_t it = commands_.begin (); it != commands_.end (); ++it)
	o << it->command () << std::endl;

      o << std::endl;

      if (withHeader_)
	{
	  o << "plt.show ()" << std::endl;
	}

      return o;
    }

    Matplotlib&
    Matplotlib::operator << (matplotlib::Command cmd)
    {
      push_command (cmd);
      return *this;
    }

    Matplotlib&
    Matplotlib::operator << (matplotlib::Import import)
    {
      push_import (import);
      return *this;
    }

    std::ostream&
    operator<< (std::ostream& o, const Matplotlib& ml)
    {
      return ml.print (o);
    }

    void
    Matplotlib::clear ()
    {
      resetImports ();
      commands_.clear ();
    }
  } // end of namespace visualization.
} // end of namespace roboptim.
