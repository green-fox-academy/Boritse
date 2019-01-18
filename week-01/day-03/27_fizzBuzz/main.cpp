#include <iostream>

int main(int argc, char* args[]) {

 for (int x=1; x<101; x++){
     if((x%3==0) && (x%5==0)){
         std::cout << "FizzBuzz" << std::endl;
     }else if(x%3==0){
         std::cout << "Fizz" << std::endl;
     }else if(x%5==0){
         std::cout << "Buzz" << std::endl;
     }else{
         std::cout << x << std::endl;
     }
 }

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.

    return 0;
}