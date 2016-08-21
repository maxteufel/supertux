//  SuperTux - PortableSnowball
//  Copyright (C) 2006 Wolfgang Becker <uafr@gmx.de>
//  Copyright (C) 2016 Max Teufel <max@teufelsnetz.com>
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

#ifndef HEADER_SUPERTUX_OBJECT_PORTABLE_SNOWBALL_HPP
#define HEADER_SUPERTUX_OBJECT_PORTABLE_SNOWBALL_HPP

#include "object/rock.hpp"

/**
 * PortableSnowball.
 */
class PortableSnowball : public Rock
{
public:
  PortableSnowball(const Vector& pos);
  PortableSnowball(const ReaderMapping& reader);
  void draw(DrawingContext& context) /*override*/;
  ~PortableSnowball();

  HitResponse collision(GameObject& other, const CollisionHit& hit) /*override*/;
  virtual void collision_tile(uint32_t tile_attributes) /*override*/;

  void grab(MovingObject& object, const Vector& pos, Direction dir) /*override*/;
  void ungrab(MovingObject& object, Direction dir) /*override*/;

  std::string get_class() const /*override*/{
    return "portablesnowball";
  }
  std::string get_display_name() const /*override*/{
    return _("Portable Snowball");
  }

  virtual ObjectSettings get_settings() /*override*/;

private:
  //

private:
  PortableSnowball(const PortableSnowball&);
  PortableSnowball& operator=(const PortableSnowball&);
};

#endif

/* EOF */
