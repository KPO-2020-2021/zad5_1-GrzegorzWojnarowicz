#include <iostream>
#include <fstream>
#include <lacze_do_gnuplota.hh>
#include <utility>
#include "../inc/Matrix3x3.h"
#include "Cuboid.h"
#include "Vector3D.h"
#include "Scene.h"



void menuDisplay();


int main() {


    /* Initialize "Lacze do gnuplota" to work within class Scene*/
    double XRange[2] = {0, 200};
    double YRange[2] = {0, 200};
    double ZRange[2] = {0, 200};
    Scene gnu = Scene(XRange, YRange, ZRange);


    /*display menu*/
    menuDisplay();
    gnu.changeDronesColors();
    gnu.drawScene();

    double lengthOfFlight; double angleOfFlight;;
    int droneIndex;
    char c = ' ';
    while(c != 'k'){
        gnu.drawScene();
        if(!(std::cin >> c)){
            throw std::exception();
        }
        switch (c) {
            case 'm':
                menuDisplay();
                break;
            case 'a':
                if(gnu.getIndex() == 0){
                    std::cout << "position of Drone 0: (" << gnu[0].getdroneBody().getPosition()[0]
                    << ", " << gnu[0].getdroneBody().getPosition()[1] <<") <- active\n";

                    std::cout << "position of Drone 1: (" << gnu[1].getdroneBody().getPosition()[0]
                    << ", " << gnu[1].getdroneBody().getPosition()[1] <<")\n";;
                }else if(gnu.getIndex() == 1){
                    std::cout << "position of Drone 0: (" << gnu[0].getdroneBody().getPosition()[0]
                              << ", " << gnu[0].getdroneBody().getPosition()[1] <<")\n";

                    std::cout << "position of Drone 1: (" << gnu[1].getdroneBody().getPosition()[0]
                              << ", " << gnu[1].getdroneBody().getPosition()[1] <<") <- active\n";;
                }else{
                    throw std::invalid_argument("Chosen drone index is incorrect");
                }
                    std::cout << "Choose drone index (from 0 to 1)\n";
                    std::cin >> droneIndex;
                    if(droneIndex != 0 && droneIndex != 1){
                        throw std::invalid_argument("Chosen drone index is invalid");
                    }
                    gnu.setIndex(droneIndex);
                    gnu.changeDronesColors();
                break;
            case 'p':
                std::cout << "Give target angle in degree\n";
                std::cin >> angleOfFlight;
                std::cout << "Give length of flight in degree\n";
                std::cin >> lengthOfFlight;

                gnu.animateDroneTranslation(angleOfFlight, lengthOfFlight);

                /*updating Scene */
                gnu[gnu.getIndex()].calculatePosition();
                gnu.drawScene();

            case 'w':
                std::cout << vector3D::getTotal() << "<-- Total\n";
                std::cout << vector3D::getActual() << "<-- Actual\n";
                break;
            case 'c':
                gnu.makeCircleWithDrone(20);
                break;
            case 'k':
                break;
            default:
                std::cout << "Unknown argument\n";
                break;
        }
        std::cout << "You chose: '"<< c << "' (m-menu)\n";
    }
}

void menuDisplay(){
  std::cout << "a - choose drone index (0 or 1)\n";
  std::cout << "p - choose target position of chosen drone\n";
  std::cout << "c - make circle\n";
  std::cout << "w - print number of vector3D\n";
  std::cout << "m - display menu\n";
  std::cout << "k - close\n";

}
