#pragma once

#include "Matrix3x3.h"
#include "Vector3D.h"
#include "Constants.h"

class Solid{
protected:
    std::string fileNameModel;
    std::string fileNameSolid;
    Matrix3x3 orientation;
    vector3D centerOfMassPosition;
public:
    Solid();
    Solid(std::string fileNameModel, std::string fileNameSolid);
    std::string getModelFileName();
    std::string getSolidFileName();
    vector3D getPosition();
    Matrix3x3 getOrientation();
    void setOrientation(Matrix3x3 orient);
    void setPosition(vector3D pos);
    /*! adds vector to current position */
    Solid &operator+=(vector3D vec);
    /*! subtract vector from current position */
    Solid &operator-=(vector3D vec);
    /*! multiply matrix by orienation*/
    Solid &operator*=(Matrix3x3 rotMat);
};