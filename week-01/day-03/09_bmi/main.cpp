#include <iostream>
#include <cmath>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;
    double bmi= massInKg/ pow(heightInM, 2);
    std::cout << bmi << std::endl;
    std::cout << massInKg/(heightInM*heightInM);
    // Print the Body mass index (BMI) based on these values

    return 0;
}
//tömeg/magassásnégyzet