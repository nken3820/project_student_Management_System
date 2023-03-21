#ifndef SCORE_H
#define SCORE_H

#include "../Header/header.h"

class score
{
public:
    string courseCode_; //(mã khóa học)
    string year_;
    string semester_; //(học kỳ)
    string studentId_;
    string midtermScore_; //(điểm giữa kỳ)
    string labScore_;     //(điểm phòng thí nghiệm) (nếu có)
    string finalScore_;   //(diểm cuối kỳ)

public:
    friend istream &operator>>(istream &in, score &score_)
    {
        // cout << "ma khoa hoc: ";
        // in >> score_.courseCode_;
        cout << "nam hoc: ";
        in >> score_.year_;
        cout << "hoc ky: ";
        in >> score_.semester_;
        // cout << "Mssv: ";
        // in >> score_.studentId_;
        cout << "diem giua ky: ";
        in >> score_.midtermScore_;
        cout << "diem phong thi nghiem: ";
        in >> score_.labScore_;
        cout << "diem cuoi ky: ";
        in >> score_.finalScore_;
        cout << endl;
        return in;
    }
    friend ostream &operator<<(ostream &os, score &score_)
    {
        os << "ma khoa hoc: " << score_.courseCode_ << endl;
        os << "nam hoc: " << score_.year_ << endl;
        os << "hoc ky: " << score_.semester_ << endl;
        os << "Mssv: " << score_.studentId_ << endl;
        os << "diem giua ky: " << score_.midtermScore_ << endl;
        os << "diem phong thi nghiem: " << score_.labScore_ << endl;
        os << "diem cuoi ky: " << score_.finalScore_ << endl;
        return os;
    }

public:
    score(/* args */);
    ~score();
};

#endif