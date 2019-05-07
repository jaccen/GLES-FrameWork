//
// Created by jaccen on 2018/12/29.
//

#ifndef ENGINE_ARNAVI_PLAYYUV_H
#define ENGINE_ARNAVI_PLAYYUV_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "shader.h"
#include "texture.h"
#include <memory>
#include "transform.h"
#include "component.h"
#include "mesh.h"
#include "material.h"

namespace mapauto
{
namespace engine
{
enum
{
    tYUV420,
    tVK_YUV420,
    tYUV420_FILTER
};

struct video_frame
{
    size_t width;
    size_t height;
    size_t stride_y;
    size_t stride_uv;
    unsigned char *y;
    unsigned char *u;
    unsigned char *v;
};
class PlayYUV : public Transform
{

  public:
    PlayYUV(const int w = 320, const int h = 180);
    virtual ~PlayYUV();

    void init();
    void ondraw();
    void destroy();

  public:
    void set_buffer(const unsigned char *data, const int w = 320, const int h = 180);
    void load_file(const std::string &filename);
    void display();
    void update_frame(const video_frame &frame);
    void draw(unsigned char *buffer, size_t length, size_t width, size_t height);
    bool create_textures();
    bool update_textures();
    void delete_textures();
    void update(const mat4 &mat)
    {
        _mvp = glm::toMat4(get_rotation()) * mat;
    }

  private:
    Shader *_shader = nullptr;
    GLuint _vboid = 0;
    GLuint _iboid = 0;

    GLuint id_y = 0;
    GLuint id_u = 0;
    GLuint id_v = 0; // Texture id

    FILE *fp = nullptr;
    int _pixel_w = 0;
    int _pixel_h = 0;

    unsigned char *buffer = nullptr;
    unsigned char *plane[3] = {nullptr};
    bool _islocalfile = true;
    bool _isdirty = false;
    size_t _length;
    size_t _sizey;
    size_t _sizeu;
    size_t _sizev;

  public:
    mat4 _mvp = mat4(1.0);
};
class VideoFrame : public Component
{
    VideoFrame(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material);
    virtual ~VideoFrame(void);

    virtual void render(Shader *shader);

    inline virtual const char *getType(void) { return "VIDEO_RENDERER"; }

private:
    std::shared_ptr<Mesh> _mesh;
    std::shared_ptr<Material> _material;
};


} // namespace engine
} // namespace mapauto
#endif //MAPAUTO_SDK_PLAYYUV_H
