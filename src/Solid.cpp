#include "Solid.h"

Solid::Solid() {
    this -> fileNameSolid = "../data/fileNameSolid";
    this -> fileNameModel = "../data/fileNameModel";
    this -> orientation = Matrix3x3();
    this -> centerOfMassPosition = vector3D();
}

Solid::Solid(std::string fileNameModel, std::string fileNameSolid){
    this -> fileNameModel = fileNameModel;
    this -> fileNameSolid = fileNameSolid;
    this -> orientation = Matrix3x3();
    this -> centerOfMassPosition = vector3D();
}

std::string Solid::getModelFileName() {
    return this->fileNameModel;
}

std::string Solid::getSolidFileName() {
    return this->fileNameSolid;
}

vector3D Solid::getPosition() {
    return this->centerOfMassPosition;
}

Matrix3x3 Solid::getOrientation() {
    return this->orientation;
}

Solid &Solid::operator+=(vector3D vec) {
    this->centerOfMassPosition = this->centerOfMassPosition + vec;
    return *this;
}

Solid &Solid::operator*=(Matrix3x3 rotMat) {
    this->orientation = rotMat * this->orientation;
    return *this;
}

Solid &Solid::operator-=(vector3D vec) {
    this->centerOfMassPosition = this->centerOfMassPosition - vec;
    return *this;
}

void Solid::setOrientation(Matrix3x3 orient) {
    this->orientation =orient;
}

void Solid::setPosition(vector3D pos) {
    this->centerOfMassPosition = pos;
}
