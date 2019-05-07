//
// Created by jaccen on 2018/12/18.
//

#ifndef ENGINE_ARNAVI_CAMERA_H
#define ENGINE_ARNAVI_CAMERA_H

#include "math_inc.h"
#include "configure.h"
class Camera
{
  public:
    enum class Type
    {
        PERSPECTIVE = 1,
        ORTHOGRAPHIC = 2
    };
    enum CamearaDirection
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        FORWARD,
        BACK
    };
     ~Camera();

    const Mat44 &get_view_perspective_transform() const;

    void aspect_ratio(float ratio);

    void fov(float f);

    void reset(Camera::Type mode);
    void set_mode(Camera::Type mode);
    Camera::Type get_mode() const;

     inline glm::vec3& getPosition() { return _position; };
     inline void setPosition(const glm::vec3& position) { _position = position; };
     inline bool& isActive() { return m_active; }
     inline void setActive(bool value) { m_active = value; }
     inline void update(double delta) {}
  public:
    glm::mat4 get_viewmatrix();
    glm::mat4 get_projectmatrix();

  public:
    Camera(float fovy = glm::radians(45.0f), float aspectRatio = 1080.f / 1920.0f,
           float near = 0.1f, float far = 1000.0f);
    void move(CamearaDirection dir, GLfloat deltet);

    void set_postion(vec3 position);

  private:
    Camera::Type _type;
    void calculate_perspective_transform();
    void calculate_view_transform();
    void calculate_viewperspective_transform();

    float _fov = 60.0f;
    float _aspect = 1.0;
    float _znear = 0.1f;
    float _zfar = 100.0f;
    Vec3 eye = vec3(0.0);
    Vec3 lookat = Vec3(0, 0, -1);
    vec3 up = Vec3(0, 1, 0);
    mat4 _view = mat4(1.0);
    mat4 _projection = mat4(1.0);
    mat4 _view_projection = mat4(1.0);

    Vec3 _front = Vec3(0.0f, 0.0f, -1.0f);
    Vec3 _up = vec3(0.0f, 1.0f, 0.0f);
    Vec3 _right;
    Vec3 _word_up;
    vec3 _position = vec3(0.0f, 0.0f, 0.0f);
    Camera::Type _mode = Type::PERSPECTIVE;
    mutable int _dirtybits;

      bool m_active;
  public:
    mat4 getViewMatrix(void) const;
    mat4 getProjectionMatrix(void) const {return _projection;}

    inline  const char *getType(void) { return "CAMERA"; }
};

class PerspectiveCamera : public Camera
{
  public:
    PerspectiveCamera(float fov, float aspect, float zNear, float zFar);

    virtual glm::mat4 getProjectionMatrix(void) const;

    inline virtual const char *getType(void) { return "PERSPECTIVE_CAMERA"; }

    void setFov(float fov);
    float getFov(void);

  private:
    float _fov;
    float _aspect;
    float _znear;
    float _zfar;
  
};

#endif // MAPAUTO_SDK_CAMERA_H
