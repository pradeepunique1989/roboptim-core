// Copyright (C) 2009 by Thomas Moulard, FIXME.
//
// This file is part of the liboptimization.
//
// liboptimization is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// liboptimization is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with liboptimization.  If not, see <http://www.gnu.org/licenses/>.


/**
 * \brief Implementation of the Function class.
 */

#include "liboptimization/function.hh"
#include "liboptimization/indent.hh"
#include "liboptimization/util.hh"

namespace optimization
{
  Function::Function (size_type n, size_type m) throw ()
    : n (n),
      m (m)
  {
    // Positive size is required.
    assert (n >= 0 && m >= 0);
  }

  Function::~Function () throw ()
  {
  }

  std::ostream&
  Function::print (std::ostream& o) const throw ()
  {
    return o << "Function";
  }

  std::ostream&
  operator<< (std::ostream& o, const Function& f)
  {
    return f.print (o);
  }
} // end of namespace optimization
