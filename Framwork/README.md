

## Windows building
All relevant libraries are found in /libs and all DLLs found in /dlls (pre-)compiled for Windows. 
The CMake script knows where to find the libraries so just run CMake script and generate project of choice.
Note that you still have to manually copy the required .DLL files from the /dlls folder to your binary folder for the binaries to run.

Keep in mind the supplied libraries were generated with a specific compiler version which may or may not work on your system (generating a large batch of link errors). In that case it's advised to build the libraries yourself from the source.

## Linux building
First make sure you have CMake, Git, and GCC by typing as root (sudo) `apt-get install g++ cmake git` and then get the required packages:
Using root (sudo) and type `apt-get install libsoil-dev libglm-dev libassimp-dev libglew-dev libglfw3-dev libxinerama-dev libxcursor-dev  libxi-dev` .
Next, run CMake (preferably CMake-gui). The source directory is TestGL and specify the build directory as TestGL/build. Creating the build directory within TestGL is important for linking to the resource files (it also will be ignored by Git). Hit configure and specify your compiler files (Unix Makefiles are recommended), resolve any missing directories or libraries, and then hit generate. Navigate to the build directory (`cd TestGL/build`) and type `make` in the terminal. This should generate the executables in the respective chapter folders.

Note that CodeBlocks or other IDEs may have issues running the programs due to problems finding the shader and resource files, however it should still be able to generate the exectuables. To work around this problem it is possible to set an environment variable to tell the tutorials where the resource files can be found. The environment variable is named LOGL_ROOT_PATH and may be set to the path to the root of the TestGL directory tree. For example:

    `export LOGL_ROOT_PATH=/home/user/tutorials/TestGL`

Running `ls $LOGL_ROOT_PATH` should list, among other things, this README file and the resources direcory.

## Mac OS X building
Building on Mac OS X is fairly simple 

brew install cmake  glm glfw
mkdir build
cd build
cmake ../.
make -j8
```



