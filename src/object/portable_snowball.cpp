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

#include "object/portable_snowball.hpp"

#include <algorithm>

#include "audio/sound_manager.hpp"
#include "sprite/sprite.hpp"
#include "sprite/sprite_manager.hpp"
#include "supertux/object_factory.hpp"
#include "supertux/tile.hpp"
#include "util/reader_mapping.hpp"

namespace {
  const float SNAIL_KICK_SPEED_X = 500;
  const float SNAIL_KICK_SPEED_Y = -500;
}

PortableSnowball::PortableSnowball(const ReaderMapping& reader) :
  Rock(reader, "images/objects/lantern/lantern.sprite")
{
  SoundManager::current()->preload("sounds/willocatch.wav");
}

PortableSnowball::PortableSnowball(const Vector& pos) :
  Rock(pos, "images/objects/lantern/lantern.sprite")
{
  SoundManager::current()->preload("sounds/willocatch.wav");
}

ObjectSettings
PortableSnowball::get_settings() {
  ObjectSettings result = Rock::get_settings();
  //result.options.push_back( ObjectOption(MN_COLOR, _("Colour"), &lightcolor, "color"));

  return result;
}

PortableSnowball::~PortableSnowball()
{
}

void
PortableSnowball::draw(DrawingContext& context){
  //Draw the Sprite.
  MovingSprite::draw(context);
}

HitResponse PortableSnowball::collision(GameObject& other, const CollisionHit& hit) {
  return Rock::collision(other, hit);
}

void
PortableSnowball::collision_tile(uint32_t tile_attributes)
{
  if (tile_attributes & Tile::WATER) {
    log_warning << "PortableSnowball collided with water tile" << std::endl;
  }
}

void
PortableSnowball::grab(MovingObject& object, const Vector& pos, Direction dir)
{
  Rock::grab(object, pos, dir);
}

void
PortableSnowball::ungrab(MovingObject& object, Direction dir)
{
  Rock::ungrab(object, dir);
  physic.set_velocity_x(dir == LEFT ? -SNAIL_KICK_SPEED_X : SNAIL_KICK_SPEED_X);
  physic.set_velocity_y(0);

  //set_colgroup_active(COLGROUP_MOVING);
  set_group(COLGROUP_MOVING);

  //Rock::ungrab(object, dir);
}

/* EOF */
