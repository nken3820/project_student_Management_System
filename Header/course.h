#ifndef COURSE_H
#define COURSE_H

#include "../Header/header.h"
#include "../Header/schedules.h"
#include "../Header/information.h"
#include "../Header/score.h"

struct user
{
    string name_;
    string mssv_;
    score score_;
};

class course
{
public:
    information information_;
    schedules schedules_;

private:
    vector<user> list_attendance;

public:
    void Set_dataList(vector<user> data)
    {
        list_attendance = data;
    }
    vector<user> Get_dataList()
    {
        return list_attendance;
    }

public:
    course();
    ~course();
};

#endif