//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//                2018 Ingo Ruhnke <grumbel@gmail.com>
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

#ifndef HEADER_SUPERTUX_VIDEO_GL_GL_TEXTURE_RENDERER_HPP
#define HEADER_SUPERTUX_VIDEO_GL_GL_TEXTURE_RENDERER_HPP

#include <memory>

#include "video/gl.hpp"
#include "video/gl/gl_painter.hpp"
#include "video/renderer.hpp"
#include "video/texture_ptr.hpp"

class GLFramebuffer;
class GLTexture;
class GLVideoSystem;
class Rect;
class Texture;
struct DrawingRequest;

class GLTextureRenderer final : public Renderer
{
public:
  GLTextureRenderer(GLVideoSystem& video_system, const Size& size, int downscale);
  ~GLTextureRenderer();

  virtual void start_draw() override;
  virtual void end_draw() override;

  virtual GLPainter& get_painter() override { return m_painter; }

  virtual Rect get_rect() const override;
  virtual Size get_logical_size() const override;

  virtual TexturePtr get_texture() const override { return m_texture; }

  bool is_rendering() const;

private:
  void prepare();

private:
  GLVideoSystem& m_video_system;
  GLPainter m_painter;

  Size m_size;
  int m_downscale;
  TexturePtr m_texture;
  std::unique_ptr<GLFramebuffer> m_framebuffer;
  bool m_rendering;

private:
  GLTextureRenderer(const GLTextureRenderer&);
  GLTextureRenderer& operator=(const GLTextureRenderer&);
};

#endif

/* EOF */
