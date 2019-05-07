//
// Created by jaccen on 2018/12/12.
//

#include "texture.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "stb_image.h"
Texture::~Texture()
{
    glDeleteTextures(1, &_textureid);
    _textureid = 0;
}

void Texture::bind(unsigned int uint)
{
    glActiveTexture(GL_TEXTURE0 + uint);
    glBindTexture(GL_TEXTURE_2D, _textureid);
}

void Texture::unbind() { glBindTexture(GL_TEXTURE_2D, 0); }

Texture::Texture(const std::string &filename)
{

    _filename = filename;
    if (filename.empty())
    {
        _textureid = create_default_texture(100, 100);
        return;
    }
    unsigned char *image =
        stbi_load(filename.c_str(), &_width, &_height, &_chanel, STBI_rgb_alpha);
    if (image == nullptr)
    {
        printf("read texture error");
        _textureid = create_default_texture(100, 100);
        return;
    }
    glGenTextures(1, &_textureid);

    glBindTexture(GL_TEXTURE_2D, _textureid);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (_chanel == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, image);
    }
    else if (_chanel == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, image);
    }
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(image);
}
GLuint Texture::create_default_texture(int width, int height)
{
    GLuint textureId;
    _width = width;
    _height = height;
    // 2x2 Image, 3 bytes per pixel (R, G, B)
    GLubyte pixels[4 * 3] = {
        255, 0, 0,  // Red
        0, 255, 0,  // Green
        0, 0, 255,  // Blue
        255, 255, 0 // Yellow
    };
    GLuint *pTexData = new GLuint[width * height];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Fills the data with a fancy pattern
            GLuint col = (255 << 24) + ((255 - j * 2) << 16) + ((255 - i) << 8) +
                         (255 - i * 2);
            if (((i * j) / 8) % 2)
                col = (GLuint)(255 << 24) + (255 << 16) + (0 << 8) + (255);
            pTexData[j * width + i] = col;
        }
    }
    // Use tightly packed data
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Generate a texture object
    glGenTextures(1, &textureId);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Load the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, pTexData);

    // Set the filtering mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    delete[] pTexData;
    pTexData = nullptr;

    _filename = "defualt";
    return textureId;
}

GLuint Texture::create_texture(GLenum type)
{
    GLuint textureId;
    // 设置解包对齐
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // 创建纹理
    glGenTextures(1, &textureId);
    // 绑定纹理
    glBindTexture(type, textureId);
    // 设置放大缩小模式
    glTexParameterf(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    return textureId;
}

GLuint Texture::create_texture_withbytes(unsigned char *bytes, int width,
                                         int height,  int chanle)
{
    GLuint textureId;
    if (bytes == nullptr)
    {
        return 0;
    }
    // 创建Texture
    glGenTextures(1, &textureId);
    // 绑定类型
    glBindTexture(GL_TEXTURE_2D, textureId);
    // 利用像素创建texture
    if (chanle == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, bytes);
    } else if (_chanel == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, bytes);
    }

    // 设置放大缩小模式
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    return textureId;
}

void Texture::create_frame_buffer(GLuint *framebuffer, GLuint *texture,
                                  int width, int height)
{
    create_frame_buffers(framebuffer, texture, width, height, 1);
}

void Texture::create_frame_buffers(GLuint *frambuffers, GLuint *textures,
                                   int width, int height, int size)
{
    // 创建FBO
    glGenFramebuffers(size, frambuffers);
    // 创建Texture
    glGenTextures(size, textures);
    for (int i = 0; i < size; ++i)
    {
        // 绑定Texture
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        // 创建一个没有像素的的Texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, NULL);
        // 设置放大缩小模式
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        // 创建完成后需要解绑
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}

#ifdef __ANDROID__
const int VIDEO_TARGET = GL_TEXTURE_EXTERNAL_OES;
#else
const int VIDEO_TARGET = GL_TEXTURE_2D;
#endif
VideoTexture::VideoTexture()
{
}

void VideoTexture::refresh()
{
}
void VideoTexture::update_buffer(const unsigned char *data, const int w, const int h)
{
}
