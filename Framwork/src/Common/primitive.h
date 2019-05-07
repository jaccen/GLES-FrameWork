//
// Created by jaccen on 19-4-11.
//

#ifndef ENGINE_ARNAVI_PRIMITIVE_H
#define ENGINE_ARNAVI_PRIMITIVE_H

#include "math_inc.h"
#include "configure.h"
#include "mesh.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
namespace mapauto
{
namespace engine
{
enum PrimitiveType
{
    LINEPRIMITIVE = 0,
    CUBEPRIMITIVE = 1,
    QUADPRIMITIVE = 2,
    SPHEPRIMITIVE = 3,
    CYLINDER = 4,
    CANVASPRIMITIVE = 5,
    TOTALPRIMITIVE = 6
};
class Primitive
{
public:
    Primitive();
    virtual ~Primitive();

public:
    virtual std::shared_ptr<Mesh> get_mesh() { return nullptr; };

public:
    PrimitiveType _type;
};

class PrimitiveManager
{
public:
    PrimitiveManager();
    virtual ~PrimitiveManager();
    std::shared_ptr<Mesh> get_mesh(PrimitiveType type);
    void pause_with_gl();
    void refresh();

public:
    Primitive *_mesh_array[PrimitiveType::TOTALPRIMITIVE];
};
} // namespace engine
} // namespace mapauto
#endif //MAPAUTO_SDK_PRIMITIVE_H
