#ifndef CLASS_H
#define CLASS_H

#include "../Header/header.h"
#include "../Header/student.h"

class class_student
{
public:
    string class_name_;
    vector<student> list_student;

public:
    class_student(/* args */);
    ~class_student();
};

#endif