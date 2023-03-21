#ifndef SCHDULES_H
#define SCHDULES_H

#include "../Header/header.h"

class schedules
{
public:
    string start_at_;
    string end_at_;
    string from_;
    string to_;
    string date_of_week;

public:
    schedules();
    ~schedules();

public:
    friend ostream &operator<<(ostream &os, schedules &schedules_)
    {
        os << "ngay bat dau: " << schedules_.start_at_ << endl;
        os << "ngay ket thuc: " << schedules_.end_at_ << endl;
        os << "thoi gian bat dau: " << schedules_.from_ << endl;
        os << "thoi gian ket thuc: " << schedules_.to_ << endl;
        os << "ngay hoc: " << schedules_.date_of_week << endl;
        return os;
    }
    friend istream &operator>>(istream &in, schedules &schedules_)
    {
        cout << "ngay bat dau: ";
        in >> schedules_.start_at_;
        cout << "ngay ket thuc: ";
        in >> schedules_.end_at_;
        cout << "thoi gian bat dau: ";
        in >> schedules_.from_;
        cout << "thoi gian ket thuc: ";
        in >> schedules_.to_;
        cout << "ngay hoc: ";
        in >> schedules_.date_of_week;
        cout << endl;
        return in;
    }
};

#endif