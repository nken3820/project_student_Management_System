#ifndef ADMIN_H
#define ADMIN_H

#include "../Header/header.h"
#include "../Header/users.h"
#include "../Header/course.h"
#include "../Header/schedules.h"
#include "../Header/information.h"
#include "../Header/student.h"
#include "../Header/class.h"

class admin : public users
{
private:
    vector<information> list_information_;
    vector<schedules> list_schedules_;
    vector<course> list_course;
    vector<class_student> list_class_student_;

public:
    vector<student> list_student_csv;

public:
    void Set_dataList(vector<information> data)
    {
        list_information_ = data;
    }
    vector<information> Get_dataList()
    {
        return list_information_;
    }
    void Set_dataList(vector<schedules> data)
    {
        list_schedules_ = data;
    }
    vector<schedules> Get_dataList_schedules()
    {
        return list_schedules_;
    }
    void Set_dataList(vector<course> data)
    {
        list_course = data;
    }
    vector<course> Get_dataList_course()
    {
        return list_course;
    }
    void Set_dataList(vector<class_student> list_class_student)
    {
        list_class_student_ = list_class_student;
    }
    vector<class_student> Get_dataList_class()
    {
        return list_class_student_;
    }

public:
    admin();
    ~admin();
};

#endif