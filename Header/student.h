#ifndef STUDENT_H
#define STUDENT_H

#include "../Header/header.h"
#include "../Header/users.h"
#include "../Header/score.h"
#include "../Header/course.h"

class student : public users
{
private:
    vector<score> list_score_;
    vector<course> list_course_;

public:
    score scores_;

public:
    void Set_dataList(vector<course> data)
    {
        list_course_ = data;
    }
    vector<course> Get_dataList()
    {
        return list_course_;
    }
    void Set_dataList(vector<score> data)
    {
        list_score_ = data;
    }
    vector<score> Get_dataList_score()
    {
        return list_score_;
    }

public:
    student();
    ~student();
};

#endif