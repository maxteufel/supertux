//  SuperTux
//  Copyright (C) 2016 M. Teufel <mteufel@urandom.eu.org>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_SCRIPTING_COIN_HPP
#define HEADER_SUPERTUX_SCRIPTING_COIN_HPP

#ifndef SCRIPTING_API
class Coin;
#endif

namespace scripting {

class Coin
{
public:
#ifndef SCRIPTING_API
  Coin(::Coin* platform);
  ~Coin();
#endif

#ifndef SCRIPTING_API
  ::Coin* coin;

private:
  Coin(const Coin&);
  Coin& operator=(const Coin&);
#endif
};

} // namespace scripting

#endif

/* EOF */
