// Reaktoro is a unified framework for modeling chemically reactive systems.
//
// Copyright (C) 2014-2018 Allan Leal
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library. If not, see <http://www.gnu.org/licenses/>.

#include "Hessian.hpp"

// Reaktoro includes
#include <Reaktoro/Common/Exception.hpp>

namespace Reaktoro {

auto operator*(const Hessian& H, VectorConstRef x) -> Vector
{
    if(H.mode == Hessian::Dense)
        return H.dense * x;
    if(H.mode == Hessian::Diagonal)
        return H.diagonal % x;
    RuntimeError("Could not multiply a Hessian matrix with a vector.",
        "The Hessian matrix must be in either Dense or Diagonal mode.");
}

} // namespace Reaktoro
