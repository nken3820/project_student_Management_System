#ifndef MENU_H
#define MENU_H

#include "../Header/header.h"
#include "../Header/student.h"
#include "../Header/lecturer.h"
#include "../Header/admin.h"
#include "../Header/class.h"
#include "../Header/users.h"

class menu
{
private:
    vector<users> dataList;
    vector<student> dataList_student;

public:
    void menu_of_student(student &data_student, admin &admin_, vector<lecturer> &list_lecture_);
    void menu_of_lecturer(lecturer &data_lecturer, admin &admin_);
    void menu_of_admin(admin &data_admin, vector<lecturer> &list_lecture_, vector<student> &data);

public:
    void menu_course_of_admin(admin &data_admin);
    void menu_course_schedules_of_admin(admin &data_admin);
    void menu_attendance_of_admin(admin &data_admin);
    void menu_scoreboard_of_admin(admin &data_admin, vector<lecturer> &data);
    void menu_class_of_admin(admin &data_admin, vector<student> &data);

public:
    menu(/* args */);
    ~menu();

public:
    void thaydoimatkhau(student &data_student);
    void thaydoimatkhau(lecturer &data_lecturer);
    void thaydoimatkhau(admin &data_admin);
    void nhapbangdiemcuamotkhoahoc(admin &data_admin, lecturer &lecturer_);
    void chinhsuadiemcuamotsinhvien(lecturer &data_lecturer);
    void xemdiem(student &data, vector<lecturer> &list_lecture_);
    void xembangdiem(lecturer &data_lecturer);
    void dangkykhoahoc(student &data_student, admin &admin_);
    void xemketquadangky(student &data);

    // function menu course of menu admin
    int count(string s);
    void stringProcessing_file_csv(string s, vector<string> &result);
    void nhapkhoahoc(vector<string> &result, admin &admin_);
    void themkhoahoc(admin &admin_);
    void chinhsuakhoahoc(admin &admin_);
    void xoakhoahoc(admin &admin_);

    // function menu course's schdules of menu admin
    void nhaplichtrinh(vector<string> &result_vector, admin &admin_);
    void themlichtrinh(admin &admin_);
    void chinhsualichtrinh(admin &admin_);
    void xoalichtrinh(admin &admin_);

    // function menu attendance of menu admin
    void search_view_export(admin &admin_, int number);

    // function menu scoreboard of menu admin
    void search_view_export(admin &admin_, int number, vector<lecturer> &data);

    // function menu class of menu admin
    void nhapsinhviencuamotlophoc(admin &admin_);
    void xemdanhsachcaclop(admin &admin_);
    void xemdanhsachhocsinh(admin &admin_);
    void themloptrong(admin &admin_);
    void xoasinhvienkhoilop(admin &admin_);
    void chuyensinhviensanglopkhac(admin &admin_, vector<student> &data);
    void themsinhvienvaolophoc(admin &admin_, vector<student> &data);
    void chinhsuasinhvienhienco(admin &admin_, vector<student> &data);
    string stringProcessing(string input);
};

#endif