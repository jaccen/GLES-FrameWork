# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Engine.Debug:
PostBuild.GLAD.Debug: /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/Engine
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/Engine:\
	/usr/local/lib/libglfw.dylib\
	/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Debug/libGLAD.a
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/Engine


PostBuild.GLAD.Debug:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Debug/libGLAD.a:
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Debug/libGLAD.a


PostBuild.Engine.Release:
PostBuild.GLAD.Release: /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/Engine
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/Engine:\
	/usr/local/lib/libglfw.dylib\
	/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Release/libGLAD.a
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/Engine


PostBuild.GLAD.Release:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Release/libGLAD.a:
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Release/libGLAD.a


PostBuild.Engine.MinSizeRel:
PostBuild.GLAD.MinSizeRel: /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/MinSizeRel/Engine
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/MinSizeRel/Engine:\
	/usr/local/lib/libglfw.dylib\
	/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/MinSizeRel/libGLAD.a
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/MinSizeRel/Engine


PostBuild.GLAD.MinSizeRel:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/MinSizeRel/libGLAD.a:
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/MinSizeRel/libGLAD.a


PostBuild.Engine.RelWithDebInfo:
PostBuild.GLAD.RelWithDebInfo: /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/RelWithDebInfo/Engine
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/RelWithDebInfo/Engine:\
	/usr/local/lib/libglfw.dylib\
	/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/RelWithDebInfo/libGLAD.a
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/bin/RelWithDebInfo/Engine


PostBuild.GLAD.RelWithDebInfo:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/RelWithDebInfo/libGLAD.a:
	/bin/rm -f /Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/RelWithDebInfo/libGLAD.a




# For each target create a dummy ruleso the target does not have to exist
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Debug/libGLAD.a:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/MinSizeRel/libGLAD.a:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/RelWithDebInfo/libGLAD.a:
/Users/jaccen/Desktop/Engine/GLES-FrameWork/Framwork/Xcode/Release/libGLAD.a:
/usr/local/lib/libglfw.dylib:
