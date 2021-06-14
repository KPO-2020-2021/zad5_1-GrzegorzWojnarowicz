#pragma once

#include <fstream>
#include "Solid.h"
#include "sstream"

class Hex
        : public Solid{
protected:
    vector3D vertices[VERTICES_NUMBER_OF_HEX];
public:
    Hex();
    Hex(std::string fileNameOfModel, std::string fileNameOfBlock = "../data/HexBlock.txt",
                   Matrix3x3 initialOrientation = Matrix3x3(), vector3D initialPosition = vector3D());
    /*! write readable for gnuplot positions that are interpreted as non empty hexagonal prism*/
    friend std::ostream & operator<<(std::ostream & ost, Hex &hex);
    /*! read position from model file */
    void readModelVerticesPosition();
    const vector3D & operator[](int index) const;
    vector3D & operator[](int index);
    /*! calculate actual position, using model position in model file, and saved position and orientation */
    void calculateActualPosition(vector3D posOfDroneBody);
    /*! Rotate all vertices by matrix, but doesnt touch center vector of hexagonal prism and orientation*/
    void rotationByMatrix(Matrix3x3 rotMatrix);
    /*! Translate all vertices by vector, but doesnt touch center vector of hexagonal prism and orientation*/
    void translationByVector(vector3D vec);

};