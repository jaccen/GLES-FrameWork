/******************************************************************************
 * Copyright (c) 2017+ The Baidu MapAuto Authors. All Rights Reserved.
 *
 * @Author: jaccen<jiaxiaobo@baidu.com>
 * @Date: 2018-11-22
 * @Version:
 * @Brief:
 *****************************************************************************/

#include "math_inc.h"

#ifdef AR_ANDROID
#define ABS(X) fabs((X))
#else
#define ABS(X) abs((X))
#endif

namespace mapauto {
namespace engine {

    Vec3 dir_to_euler_angles(const Vec3& dir) {
        if (length(dir) < 1e-5) {
            return Vec3(0);
        }

        const Vec3 up(0, 1, 0);
        const auto n_dir = normalize(dir);

        if (ABS(1.f - ABS(dot(up, n_dir))) < 1e-5f) {
            if (n_dir.y > 0) {
                return Vec3(M_PI / 2, 0, 0);
            } else {
                return Vec3(-M_PI / 2, 0, 0);
            }
        } else {
            auto eye = -n_dir;
            auto mat = glm::lookAt(eye, Vec3(0), up);
            Vec3 trans;
            Vec3 rot;
            Vec3 scale;
            decompose_matrix(mat, trans, rot, scale);
            return rot;
        }
    }

    Quat dir_to_quat(const Vec3& dir) {
        if (length(dir) < 1e-5) {
            return Quat();
        }

        const Vec3 up(0, 1, 0);
        const auto n_dir = normalize(dir);

        if (ABS(1.f - ABS(dot(up, n_dir))) < 1e-5f) {
            if (n_dir.y > 0) {
                return Quat(Vec3(M_PI / 2, 0, 0));
            } else {
                return Quat(Vec3(-M_PI / 2, 0, 0));
            }
        } else {
            auto eye = -n_dir;
            auto mat = glm::lookAt(eye, Vec3(0), up);
            Vec3 trans;
            Quat rot;
            Vec3 scale;
            decompose_matrix(mat, trans, rot, scale);
            return rot;
        }
    }

    Mat44 from_rotation(const Vec3& angles) {
        auto m_pitch = glm::rotate(angles.x, Vec3(1, 0, 0));
        auto m_yaw = glm::rotate(angles.y, Vec3(0, 1, 0));
        auto m_roll = glm::rotate(angles.z, Vec3(0, 0, 1));
        return m_roll * m_yaw * m_pitch;
    }
} // namespace engine
} // namespace mapauto
