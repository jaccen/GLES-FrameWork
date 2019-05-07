//
// Created by jaccen on 2018/12/12.
//

#ifndef ENGINE_ARNAVI_TEXTURE_H
#define ENGINE_ARNAVI_TEXTURE_H

#include "configure.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



class Texture
{
  public:
    Texture() {}
    Texture(const std::string &filename);
    virtual ~Texture();
    // 创建texture
    GLuint create_texture(GLenum type);

    // 创建texture
    GLuint create_texture_withbytes(unsigned char *bytes, int width, int height, int chanle = 4);

    GLuint create_default_texture(int width, int height);

    void bind(unsigned int uint = 0);
    void unbind();
    // 创建一个FBO和Texture
    void create_frame_buffer(GLuint *framebuffer, GLuint *texture, int width,
                             int height);

    // 创建FBO和Texture
    void create_frame_buffers(GLuint *frambuffers, GLuint *textures, int width,
                              int height, int size);

    const GLuint get_id() const { return _textureid; }
    std::string _filename = "";

  private:
    GLuint _textureid = 0;
    int _width = 0;
    int _height = 0;
    int _chanel = 0;
};
class VideoTexture : public Texture
{
  public:
    VideoTexture();
    void set_video_path(const std::string &video_path)
    {
        _video_path = video_path;
    };
    std::string get_video_path()
    {
        return _video_path;
    };
    void update_buffer(const unsigned char *data, const int w = 320, const int h = 180);
    void refresh();
    std::string _video_path;
};
// namespace mapauto

#endif // MAPAUTO_SDK_TEXTURE_H
