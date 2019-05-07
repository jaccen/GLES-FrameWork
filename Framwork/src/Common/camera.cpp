//
// Created by jaccen on 2018/12/18.
//

#include "camera.h"
#include <math.h>


Camera::Camera(float fovy, float aspectRatio, float near, float far)
    : _fov{fovy}, _aspect{aspectRatio}, _znear{near}, _zfar{far}
{
    calculate_viewperspective_transform();
}
void Camera::set_postion(vec3 position) { _position = position; }
glm::mat4 Camera::get_viewmatrix()
{
    glm::vec3 currentPosition = _position;
    glm::vec3 lookAt = currentPosition + _front;
    _view = glm::lookAt(currentPosition, lookAt, _up);
    return _view;
}
glm::mat4 Camera::get_projectmatrix()
{
    if (_mode == Type::PERSPECTIVE)
    {
        _projection = glm::perspective(_fov, _aspect, _znear, _zfar);
    }
    else
    {
        _projection = glm::ortho(0, 0, 1096, 1480);
    }
    return _projection;
}

Camera::~Camera() {}
void Camera::calculate_viewperspective_transform()
{
    calculate_perspective_transform();
    calculate_view_transform();
    _view_projection = _projection * _view;
}
void Camera::calculate_perspective_transform()
{
    if (_mode == Type::PERSPECTIVE)
    {
        _projection = glm::perspective(_fov, _aspect, _znear, _zfar);
    }
    else
    {
        _projection = glm::ortho(0, 0, 1920, 1092);
    }
}
void Camera::calculate_view_transform()
{
    glm::vec3 currentPosition = _position;
    glm::vec3 lookAt = currentPosition + _front;
    _view = glm::lookAt(currentPosition, lookAt, _up);
}
void Camera::aspect_ratio(float ratio)
{
    _aspect = ratio;
    calculate_viewperspective_transform();
}

const Mat44 &Camera::get_view_perspective_transform() const
{

    return _view_projection;
}

void Camera::fov(float f)
{
    _fov = glm::radians(f);
    calculate_viewperspective_transform();
}

Camera::Type Camera::get_mode() const { return _mode; }

void Camera::set_mode(Camera::Type mode)
{
    _mode = mode;
    //_dirtybits = CAMERA_DIRTY_ALL;
}

mat4 Camera::getViewMatrix() const
{
    return _view;
}

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float zNear,
                                     float zFar)
{
    _fov = fov;
    _aspect = aspect;
    _znear = zNear;
    _zfar = zFar;

}

glm::mat4 PerspectiveCamera::getProjectionMatrix(void) const
{
    return glm::perspective(_fov, _aspect, _znear, _zfar);
}

void PerspectiveCamera::setFov(float fov) { _fov = fov; }

float PerspectiveCamera::getFov(void) { return _fov; }
