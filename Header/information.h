#ifndef INFORMATION_H
#define INFORMATION_H

#include "../Header/header.h"

class information
{
public:
    string course_code_;
    string year_;
    string semester_;
    string course_name_;
    string lecturer_username_;

public:
    information(/* args */);
    ~information();

public:
    friend ostream &operator<<(ostream &os, information &information)
    {
        os << "ma hoc phan: " << information.course_code_ << endl;
        os << "nam hoc: " << information.year_ << endl;
        os << "hoc ky: " << information.semester_ << endl;
        os << "ten hoc phan: " << information.course_name_ << endl;
        os << "ten giang vien: " << information.lecturer_username_ << endl;
        return os;
    }
    friend istream &operator>>(istream &in, information &information)
    {
        cout << "ma hoc phan: ";
        in >> information.course_code_;
        cout << "nam hoc: ";
        in >> information.year_;
        cout << "hoc ky: ";
        in >> information.semester_;
        cout << "ten hoc phan: ";
        in >> information.course_name_;
        cout << "ten giang vien: ";
        in >> information.lecturer_username_;
        cout << endl;
        return in;
    }
};

#endif