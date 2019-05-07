//
// Created by jaccen on 19-3-25.
//

#include "platform.h"
namespace mapauto
{
namespace engine
{
Platform::Platform()
{
}
Platform::~Platform()
{
}
PlatformType Platform::get_platform_type()
{
#if defined(_DURANGO) || defined(_XBOX_ONE)
    return PlatformType::XboxOne;
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY != WINAPI_FAMILY_DESKTOP_APP)
    return PlatformType::UWP;
#elif defined(_WIN64) || defined(_WIN32)
    return PlatformType::Windows;
#elif defined(__APPLE__)
#if TARGET_OS_IOS
    return PlatformType::iOS;
#elif TARGET_OS_TV
    return PlatformType::AppleTV;
#elif TARGET_OS_MAC
    return PlatformType::MacOS;
#endif
#elif defined(__ANDROID__)
    return PlatformType::Android;
#elif defined(__linux__)
    return PlatformType::Linux;
#elif defined(__EMSCRIPTEN__)
    return PlatformType::Web;
#else
    return PlatformType::Unknown;
#endif
}
} // namespace engine
} // namespace mapauto