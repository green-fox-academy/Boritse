#include <iostream>
#include <ctime>
#include <string>
#include "blogpost.h"

int main() {

    blogpost firstPost("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04");
    blogpost secondPost("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10");

    return 0;
}