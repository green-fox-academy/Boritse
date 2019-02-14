//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef GREENFOX_COHORT_H
#define GREENFOX_COHORT_H

#include <vector>
#include <string>
#include "mentor.h"
#include "student.h"

class Cohort : public Mentor, public Student {
public:
    Cohort(std::string _name);
    void addStudent(Student* _student);
    void addMentor(Mentor* _mentor);
    void info();
private:
    std::string cohortName;
    std::vector<Student*> students;
    std::vector<Mentor*> mentors;
};


#endif //GREENFOX_COHORT_H
