/******************************************************************************
 * Copyright (c) 2017+ The Baidu MapAuto Authors. All Rights Reserved.
 *
 * @Author: jaccen<jiaxiaobo@baidu.com>
 * @Date: 2018-11-22
 * @Version:
 * @Brief:
 *****************************************************************************/

#ifndef COMMON_MATH_MATH_INC_H
#define COMMON_MATH_MATH_INC_H
#include <glm/matrix.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/matrix_interpolation.hpp>
#include <glm/gtx/transform.hpp>

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


/// @warning short type name JUST used in math module
typedef signed char s8;
typedef unsigned char u8;
typedef char c8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned int u32;
typedef signed int s32;

typedef unsigned long long u64;
typedef signed long long s64;

//typedef bool   b2;

typedef float f32;
typedef double f64;

const double MATH_EPSILON = 1e-6;

using namespace glm;
        struct Vec2i {
            union {
                struct {
                    s32 x;
                    s32 y;
                };
                struct {
                    s32 w;
                    s32 h;
                };
                s32 v[2];
            };
        };

        using Vec2 = glm::vec2;
        using Vec3 = glm::vec3;
        using Vec4 = glm::vec4;

        using vec2 = glm::vec2;
        using vec3 = glm::vec3;
        using vec4 = glm::vec4;

        using Mat22 = glm::mat2;
        using Mat33 = glm::mat3;
        using Mat44 = glm::mat4;

        using mat2 = glm::mat2;
        using mat3 = glm::mat3;
        using mat4 = glm::mat4;
        using Color = glm::vec4;
        using Quat = glm::quat;

        inline Mat44 perspective(f32 x, f32 y, f32 z, f32 w) { return glm::perspective(x, y, z, w); }

        inline Mat44 ortho(f32 x, f32 y, f32 z, f32 a, f32 b, f32 c) {
            return glm::ortho(x, y, z, a, b, c);
        }

        template <typename T>
        inline T radians(T v) {
            return glm::radians(v);
        }

        template <typename T>
        inline T degrees(T v) {
            return glm::degrees(v);
        }

        template <typename T>
        inline f32 dot(const T& v0, const T& v1) {
            return glm::dot(v0, v1);
        }

        inline Vec3 cross(const Vec3& v0, const Vec3& v1) { return glm::cross(v0, v1); }

        inline Vec3 normalize(const Vec3& v) { return glm::normalize(v); }

        inline f32 length(const Vec3& v) { return glm::length(v); }

        inline Mat44 rotate(f32 angle, const Vec3& v) { return glm::rotate(angle, v); }

        inline Mat44 from_translation(const Vec3& v) { return glm::translate(v); }

// build mat44 from an euler angles (rotation vector),
// which are x for pitch, y for yaw, and z for roll,
// the measurement is in radians
        Mat44 from_rotation(const Vec3& angles);

        inline Mat44 from_scale(const Vec3& v) { return glm::scale(v); }

        inline Mat44 from_rts(const Vec3& rotation, const Vec3& translation, const Vec3& scale) {
            return from_translation(translation) * from_rotation(rotation) * from_scale(scale);
        }

        inline Mat44 from_rts(const Quat& rotation, const Vec3& translation, const Vec3& scale) {
            return from_translation(translation) * glm::toMat4(rotation) * from_scale(scale);
        }

        template <typename T>
        inline T inverse(const T& v) {
            return glm::inverse(v);
        }

        template <typename T>
        inline T inverseTranspose(const T& v) {
            return glm::inverseTranspose(v);
        }

        extern Vec3 dir_to_euler_angles(const Vec3& dir);
        extern Quat dir_to_quat(const Vec3& dir);

        inline Vec3 euler_angles(const Quat& q) { return glm::eulerAngles(q); }

        inline void decompose_matrix(const Mat44& matrix, Vec3& translation, Quat& rotation, Vec3& scale) {
            Vec3 skew;
            Vec4 pers;
            glm::decompose(matrix, scale, rotation, translation, skew, pers);
            rotation = glm::conjugate(rotation);
        }

        inline void decompose_matrix(const Mat44& matrix, Vec3& translation, Vec3& rotation, Vec3& scale) {
            Vec3 skew;
            Vec4 pers;
            Quat rot;
            glm::decompose(matrix, scale, rot, translation, skew, pers);
            rotation = euler_angles(glm::conjugate(rot));
        }


#endif
