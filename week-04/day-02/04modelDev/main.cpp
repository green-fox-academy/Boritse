#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2D.h"
#include "printer3D.h"
#include "scanner.h"
#include "copier.h"

int main() {

    std::vector<Printer*> printers;

    Printer2D printer2d(5, 7);
    Printer2D printer22d(23, 12);
    Printer2D printer222d(45, 32);
    printers.push_back(&printer2d);
    printers.push_back(&printer22d);
    printers.push_back(&printer222d);

    Printer3D printer3d(12, 14, 20);
    Printer3D printer33d(32, 12, 11);
    printers.push_back(&printer3d);
    printers.push_back(&printer33d);

    Copier myCopier(12, 13, 1232);
    printers.push_back(&myCopier);

    std::vector<Scanner*> scanners;

    Scanner scanner1(1111);
    Scanner scanner2(2222);
    scanners.push_back(&scanner1);
    scanners.push_back(&scanner2);

    Copier copier1(21, 23, 1212);
    Copier copier2(11, 111, 1111);
    scanners.push_back(&copier1);
    scanners.push_back(&copier2);

    for(int i=0; i<scanners.size(); i++){
        std::cout << (*scanners[i]).scan() << std::endl;
        std::cout << scanners[i]->scan() << std::endl;
    }

    std::cout << copier1.copy() << std::endl;

    return 0;
}



// Create a Copier object and invoke copy function on it.