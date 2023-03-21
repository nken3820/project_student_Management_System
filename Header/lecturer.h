#ifndef LECTURER_H
#define LECTURER_H

#include "../Header/header.h"
#include "../Header/users.h"
#include "../Header/score.h"
#include "../Header/student.h"
#include "../Header/course.h"

class lecturer : public users
{
private:
    vector<user> list_user_;

public:
    void Set_dataList(vector<user> data)
    {
        list_user_ = data;
    }
    vector<user> Get_dataList_user()
    {
        return list_user_;
    }

public:
    lecturer();
    ~lecturer();
};

#endif