#ifndef APP_H
#define APP_H

#include "../Header/header.h"
#include "../Header/users.h"
#include "../Header/menu.h"
#include "../Header/student.h"
#include "../Header/lecturer.h"
#include "../Header/admin.h"

class app
{
private:
    vector<users> dataList;
    menu menu_;

private:
    vector<admin> dataList_admin;
    vector<lecturer> dataList_lecturer;
    vector<student> dataList_student;

public:
    void Set_dataList(vector<users> data)
    {
        dataList = data;
    }
    vector<users> Get_dataList()
    {
        return dataList;
    }

public:
    app();
    ~app();

public:
    void LogIn();
    void rundata();
    void UpdateAccount(string file_path);

public:
    int count(string s);
    void stringProcessing_file_csv(string s, vector<string> &result);
    string stringProcessing(string input);
};

#endif