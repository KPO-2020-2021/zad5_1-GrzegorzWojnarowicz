#include "Cuboid.h"

Cuboid::Cuboid() {
    this -> fileNameModel = "../data/CuboidModel.txt";
    this -> fileNameSolid = "../data/CuboidBlock.txt";
    this -> orientation = Matrix3x3();
    this -> centerOfMassPosition = vector3D();
}


Cuboid::Cuboid(std::string fileNameModel, std::string fileNameSolid,
               Matrix3x3 initialOrientation, vector3D initialPosition){

    this -> fileNameModel = fileNameModel;
    this -> fileNameSolid = fileNameSolid;
    this -> orientation = initialOrientation;
    this -> centerOfMassPosition = initialPosition;
}

void Cuboid::readModelVerticesPosition() {

    std::string tmp;
    std::stringstream ss;
    int i = 0;
    std::ifstream is;
    is.open(this->fileNameModel);

    while(getline(is, tmp)){
        ss << tmp;
        ss >> this->vertices[i];
        i++;
        ss = std::stringstream();
    }
    is.close();
}

bool operator==(const Cuboid &cub1, const Cuboid &cub2){
    if(
            cub1.vertices[0] == cub2.vertices[0] &&
            cub1.vertices[1] == cub2.vertices[1] &&
            cub1.vertices[2] == cub2.vertices[2] &&
            cub1.vertices[3] == cub2.vertices[3] &&
            cub1.vertices[4] == cub2.vertices[4] &&
            cub1.vertices[5] == cub2.vertices[5] &&
            cub1.vertices[6] == cub2.vertices[6] &&
            cub1.vertices[7] == cub2.vertices[7] ){
        return true;
    }
    return false;
}


void Cuboid::translationByVector(vector3D &Vec){

    for(int i = 0; i < VERTICES_NUMBER_OF_CUBOID; ++i){
        this->vertices[i] = Vec + (this->vertices[i]);
    }
}


void Cuboid::rotationByMatrix(const Matrix3x3 &rotMatrix){

    for(int i = 0; i < VERTICES_NUMBER_OF_CUBOID; ++i){
        this->vertices[i] = rotMatrix * (this->vertices[i]);
    }
}


const vector3D &Cuboid::operator[](int index) const {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        default:
            throw std::invalid_argument("index out of range");
    }
}


vector3D &Cuboid::operator[](int index) {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        default:
            throw std::invalid_argument("index out of range");
    }
}

std::ostream &operator<<(std::ostream &ost, Cuboid &cub) {
    ost << std::setprecision(10) << std::fixed;

    vector3D up = cub[2];
    up = up - cub[0];
    up = up/2;
    up = up + cub[0];
    vector3D down = cub[6];
    down = down - cub[4];
    down = down/2;
    down = down + cub[4];


    ost << up;
    ost << cub[2];
    ost << cub[6];
    ost << down << "#\n\n";

    ost << up;
    ost << cub[1];
    ost << cub[5];
    ost << down << "#\n\n";

    ost << up;
    ost << cub[0];
    ost << cub[4];
    ost << down << "#\n\n";

    ost << up;
    ost << cub[3];
    ost << cub[7];
    ost << down << "#\n\n";

    ost << up;
    ost << cub[2];
    ost << cub[6];
    ost << down << "#\n\n";

    return ost;
}

void Cuboid::calculateActualPosition() {
    readModelVerticesPosition();
    for(int i = 0; i < VERTICES_NUMBER_OF_CUBOID; ++i){
        this->vertices[i] = this->orientation * (this->vertices[i]);
    }

    for(int j = 0; j < VERTICES_NUMBER_OF_CUBOID; ++j){
        this->vertices[j] = this->centerOfMassPosition + (this->vertices[j]);
    }
}
