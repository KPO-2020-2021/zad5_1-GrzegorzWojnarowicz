#include "../inc/Matrix4x4.h"


Matrix4x4::Matrix4x4(double zAxis, double yAxis, double xAxis, Vector<double, 3> axis) {
    zAxis = toRadians(zAxis);
    yAxis = toRadians(yAxis);
    xAxis = toRadians(xAxis);


    this->matrix[0][0] = cos(zAxis) * cos(yAxis);
    this->matrix[0][1] = cos(zAxis)*sin(yAxis)*sin(xAxis) - sin(zAxis) * cos(xAxis);
    this->matrix[0][2] = cos(zAxis)*sin(yAxis)*cos(xAxis) + sin(zAxis) * sin(xAxis);
    this->matrix[0][3] = axis[0];

    this->matrix[1][0] = sin(zAxis) * cos(yAxis);
    this->matrix[1][1] = sin(zAxis) * sin(yAxis) * sin(xAxis) + cos(zAxis) * cos(xAxis);
    this->matrix[1][2] = sin(zAxis) * sin(yAxis) * cos(xAxis) - cos(zAxis) * sin(xAxis);
    this->matrix[1][3] = axis[1];

    this->matrix[2][0] = -sin(yAxis);
    this->matrix[2][1] = cos(yAxis) * sin(xAxis);
    this->matrix[2][2] = cos(yAxis) * cos(xAxis);
    this->matrix[2][3] = axis[2];


    this->matrix[3][0] = 0;
    this->matrix[3][1] = 0;
    this->matrix[3][2] = 0;
    this->matrix[3][3] = 1;
}

Matrix4x4::Matrix4x4() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (i == j){
                this->matrix[i][j] = 1;
            }else{
                this->matrix[i][j] = 0;
            }   
        }
    }
}

Matrix4x4 &Matrix4x4::operator=(const Matrix4x4 matrix4x4) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->matrix[i][j] = matrix4x4.matrix[i][j];
        }
    }
    return *this;
}

Matrix4x4 &Matrix4x4::operator=(const Matrix<double, 4> matrix4x4) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->matrix[i][j] = matrix4x4.matrix[i][j];
        }
    }
    return *this;
}

