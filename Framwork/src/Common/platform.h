//
// Created by jaccen on 19-3-25.
//

#ifndef ENGINE_ARNAVI_PLATFORM_H
#define ENGINE_ARNAVI_PLATFORM_H

#include "configure.h"
#include "math_inc.h"

namespace mapauto
{
namespace engine
{
enum class PlatformType
{
    /// Unknown platform.
    Unknown = 0,
    /// Windows platform.
    Windows = 1,
    /// Windows universal platform.
    UWP = 2,
    /// Xbox One platform.
    XboxOne = 3,
    /// Linux platform
    Linux = 4,
    /// Apple OSX platform.
    MacOS = 5,
    /// Android platform.
    Android = 6,
    /// Apple iOS platform.
    iOS = 7,
    /// Apple TV platform.
    AppleTV = 8,
    /// Web (Emscripten/WASM) platform.
    Web = 9,
};
class Platform
{
    Platform();
    ~Platform();

public:
    PlatformType get_platform_type();

private:
    PlatformType _type;
};
} // namespace engine
} // namespace mapauto

#endif //MAPAUTO_SDK_PLATFORM_H
