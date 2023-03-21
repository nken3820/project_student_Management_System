#include "../Header/menu.h"

menu::menu(/* args */)
{
}

menu::~menu()
{
}

// interface of users

void menu::menu_of_student(student &data_student, admin &admin_, vector<lecturer> &list_lecture_)
{
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.dang ky khoa hoc: " << endl;
        cout << "2.xem ket qua dang ky: " << endl;
        cout << "3.xem diem: " << endl;
        cout << "4.xem lich trinh: " << endl;
        cout << "5.xem thong tin: " << endl;
        cout << "6.thay doi mat khau: " << endl;
        cout << "0.dang xuat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 6 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "dang ky khoa hoc:" << endl
                     << endl;
                dangkykhoahoc(data_student, admin_);
                break;
            case 2:
                cout << "xem ket qua dang ky:" << endl;
                xemketquadangky(data_student);
                break;
            case 3:
                cout << "xem diem:" << endl
                     << endl;
                xemdiem(data_student, list_lecture_);
                break;
            case 4:
                cout << "xem lich trinh:" << endl
                     << endl;
                cout << "danh sach lich trinh" << endl
                     << endl;
                for (int i = 0; i < data_student.Get_dataList().size(); i++)
                {
                    cout << data_student.Get_dataList()[i].information_.course_name_ << endl;
                    cout << data_student.Get_dataList()[i].schedules_ << endl;
                }
                break;
            case 5:
                cout << "xem thong tin:" << endl
                     << endl;
                cout << data_student << endl;
                break;
            case 6:
                cout << "Thay doi mat khau:" << endl;
                thaydoimatkhau(data_student);
                break;
            case 0:
                input = false;
                break;

            default:
                break;
            }
        }
    }
}

void menu::menu_of_lecturer(lecturer &data_lecturer, admin &admin_)
{
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.nhap diem cua mot khoa hoc: " << endl;
        cout << "2.chinh sua diem cua mot hoc sinh: " << endl;
        cout << "3.xem bang diem: " << endl;
        cout << "4.xem thong tin: " << endl;
        cout << "5.thay doi mat khau: " << endl;
        cout << "0.dang xuat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 5 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "nhap diem cua mot khoa hoc:" << endl
                     << endl;
                nhapbangdiemcuamotkhoahoc(admin_, data_lecturer);
                break;
            case 2:
                cout << "chinh sua diem cua mot sinh vien:" << endl;
                chinhsuadiemcuamotsinhvien(data_lecturer);
                break;
            case 3:
                cout << "xem bang diem:" << endl;
                xembangdiem(data_lecturer);
                break;
            case 4:
                cout << "xem thong tin:" << endl
                     << endl;
                cout << data_lecturer << endl;
                break;
            case 5:
                cout << "Thay doi mat khau:" << endl;
                thaydoimatkhau(data_lecturer);
                break;
            case 0:
                input = false;
                break;

            default:
                break;
            }
        }
    }
}

void menu::menu_of_admin(admin &data_admin, vector<lecturer> &list_lecture_, vector<student> &data)
{
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.muc lop: " << endl;
        cout << "2.muc khoa hoc: " << endl;
        cout << "3.muc lich trinh: " << endl;
        cout << "4.muc danh sach tham du: " << endl;
        cout << "5.muc diem: " << endl;
        cout << "6.xem thong tin: " << endl;
        cout << "7.thay doi mat khau: " << endl;
        cout << "0.dang xuat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 7 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "muc lop:" << endl;
                menu_class_of_admin(data_admin, data);
                break;
            case 2:
                cout << "muc khoa hoc:" << endl;
                menu_course_of_admin(data_admin);
                break;
            case 3:
                cout << "muc lich trinh:" << endl;
                menu_course_schedules_of_admin(data_admin);
                break;
            case 4:
                cout << "muc danh sach tham du:" << endl;
                menu_attendance_of_admin(data_admin);
                break;
            case 5:
                cout << "muc diem:" << endl;
                menu_scoreboard_of_admin(data_admin, list_lecture_);
                break;
            case 6:
                cout << "xem thong tin:" << endl
                     << endl;
                cout << data_admin << endl;
                break;
            case 7:
                cout << "thay doi mat khau:" << endl;
                thaydoimatkhau(data_admin);
                break;
            case 0:
                input = false;
                break;

            default:
                break;
            }
        }
    }
}

// function of Menu student

void menu::thaydoimatkhau(student &data_student)
{
    string newMk;
    string newMkagain;
    cout << "nhap mat khau moi: ";
    getline(cin, newMk);
    cout << "mat khau vua nhap: ";
    getline(cin, newMkagain);
    if (newMk.compare(newMkagain) == 0)
    {
        data_student.password_ = newMkagain;
        cout << endl
             << "thay doi mat khau thanh cong!" << endl
             << endl;
    }
}

void menu::dangkykhoahoc(student &data_student, admin &admin_)
{
    bool input = true;
    vector<course> list_course_ = admin_.Get_dataList_course();
    vector<course> list_course_student = data_student.Get_dataList();
    while (input == true)
    {
        course course_;

        int line = 0;
        cout << "Danh sach khoa hoc: " << endl
             << endl;
        for (int i = 0; i < admin_.Get_dataList().size(); i++)
        {
            cout << "STT: " << i << endl;
            cout << admin_.Get_dataList()[i] << endl;
        }
        cout << endl
             << "nhap STT: ";
        cin >> line;
        for (int ii = 0; ii < admin_.Get_dataList().size(); ii++)
        {
            if (line - ii == 0)
            {
                course_.information_ = admin_.Get_dataList()[ii];
            }
        }

        cout << endl
             << "Danh sach lich trinh cua khoa hoc: " << endl
             << endl;
        for (int j = 0; j < admin_.Get_dataList_schedules().size(); j++)
        {
            cout << "STT: " << j << endl;
            cout << admin_.Get_dataList_schedules()[j] << endl;
        }
        cout << endl
             << "nhap STT: ";
        cin >> line;
        cin.ignore();
        for (int jj = 0; jj < admin_.Get_dataList_schedules().size(); jj++)
        {
            if (line - jj == 0)
            {
                course_.schedules_ = admin_.Get_dataList_schedules()[jj];
            }
        }

        vector<user> list_user = course_.Get_dataList();

        user user_;
        user_.name_ = data_student.fullname_;
        user_.mssv_ = data_student.username_;
        // user_.score_ = data_student.scores_;

        list_user.push_back(user_);
        course_.Set_dataList(list_user);

        list_course_.push_back(course_);
        list_course_student.push_back(course_);

        cout << endl
             << "DANG KY THANH CONG! " << endl;

        int number;
        cout << endl
             << "nhan 1 de tiep tuc , 0 de ket thuc: ";
        cin >> number;
        cin.ignore();
        cout << endl;
        if (number > 1 || number < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (number)
            {
            case 1:
                input = true;
                break;
            case 0:
                input = false;

                data_student.Set_dataList(list_course_student);
                admin_.Set_dataList(list_course_);

                break;

            default:
                break;
            }
        }
    }
}

void menu::xemketquadangky(student &data)
{
    for (int i = 0; i < data.Get_dataList().size(); i++)
    {
        cout << data.Get_dataList()[i].information_ << data.Get_dataList()[i].schedules_ << endl;
    }
}

void menu::xemdiem(student &data, vector<lecturer> &list_lecture_)
{
    score score_;

    vector<score> list_score_ = data.Get_dataList_score();
    vector<course> list_course_ = data.Get_dataList();

    for (int i = 0; i < list_course_.size(); i++)
    {
        for (int j = 0; j < list_lecture_.size(); j++)
        {
            if (list_lecture_[j].username_.compare(list_course_[i].information_.lecturer_username_) == 0)
            {
                vector<user> list_user = list_lecture_[j].Get_dataList_user();
                for (int k = 0; k < list_user.size(); k++)
                {
                    if (list_user[k].mssv_.compare(data.username_) == 0)
                    {
                        score_ = list_user[k].score_;
                        list_score_.push_back(score_);
                    }
                }
            }
        }
    }

    cout << endl
         << "bang diem" << endl
         << endl;

    if (list_score_.size() == 0)
    {
        cout << "Danh sach trong!" << endl
             << endl;
    }
    else
    {
        for (int count = 0; count < list_score_.size(); count++)
        {
            list_course_[count].information_.course_code_ = list_score_[count].courseCode_;
            list_score_[count].studentId_ = data.username_;
            cout << list_course_[count].information_.course_name_ << endl;
            cout << list_score_[count] << endl;
        }
    }
}

// function of Menu lecturer

void menu::thaydoimatkhau(lecturer &data_lecturer)
{
    string newMk;
    string newMkagain;
    cout << "nhap mat khau moi: ";
    getline(cin, newMk);
    cout << "mat khau vua nhap: ";
    getline(cin, newMkagain);
    if (newMk.compare(newMkagain) == 0)
    {
        data_lecturer.password_ = newMkagain;
        cout << endl
             << "thay doi mat khau thanh cong!" << endl
             << endl;
    }
}

void menu::nhapbangdiemcuamotkhoahoc(admin &data_admin, lecturer &lecturer_)
{
    int count = 0;
    vector<course> list_course_;

    vector<user> list_user_;
    vector<user> result_user;

    list_course_ = data_admin.Get_dataList_course();
    for (int i = 0; i < list_course_.size(); i++)
    {
        if (lecturer_.username_.compare(list_course_[i].information_.lecturer_username_) == 0)
        {
            count++;
            list_user_ = list_course_[i].Get_dataList();
            cout << "STT: " << count << " " << list_user_[0].name_ << " "
                 << list_user_[0].mssv_ << endl;
            cout << "nhap diem" << endl;
            cin >> list_user_[0].score_;
            list_user_[0].score_.courseCode_ = list_course_[i].information_.course_code_;
            list_user_[0].score_.studentId_ = list_user_[0].mssv_;
            result_user.push_back(list_user_[0]);
        }
    }
    lecturer_.Set_dataList(result_user);
}

void menu::chinhsuadiemcuamotsinhvien(lecturer &data_lecturer)
{
    vector<user> list_user_ = data_lecturer.Get_dataList_user();
    string input;
    cout << "nhap MSSV: ";
    getline(cin, input);
    for (int i = 0; i < list_user_.size(); i++)
    {
        if (input.compare(list_user_[i].mssv_) == 0)
        {
            cin >> list_user_[i].score_;
        }
    }
    cout << endl
         << "cap nhap thanh cong!" << endl
         << endl;
    data_lecturer.Set_dataList(list_user_);
}

void menu::xembangdiem(lecturer &data_lecturer)
{
    vector<user> list_user_ = data_lecturer.Get_dataList_user();
    cout << endl
         << "bang diem cua sinh vien:" << endl
         << endl;
    for (int i = 0; i < list_user_.size(); i++)
    {
        cout << "ho va ten: " << list_user_[i].name_ << endl
             << list_user_[i].score_ << endl;
    }
}

// function of Menu admin

void menu::thaydoimatkhau(admin &data_admin)
{
    string newMk;
    string newMkagain;
    cout << "nhap mat khau moi: ";
    getline(cin, newMk);
    cout << "mat khau vua nhap: ";
    getline(cin, newMkagain);
    if (newMk.compare(newMkagain) == 0)
    {
        data_admin.password_ = newMkagain;
        cout << endl
             << "thay doi mat khau thanh cong!" << endl
             << endl;
    }
}

// menu support of menu admin

void menu::menu_course_of_admin(admin &data_admin)
{
    vector<string> result_vector;
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.nhap khoa hoc tu tep csv: " << endl;
        cout << "2.them khoa hoc: " << endl;
        cout << "3.chinh sua khoa hoc: " << endl;
        cout << "4.xoa khoa hoc: " << endl;
        cout << "5.xem danh sach khoa hoc: " << endl;
        cout << "0.thoat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 5 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "nhap khoa hoc tu tep csv: " << endl;
                nhapkhoahoc(result_vector, data_admin);
                break;
            case 2:
                cout << "them khoa hoc:" << endl
                     << endl;
                themkhoahoc(data_admin);
                break;
            case 3:
                cout << "chinh sua khoa hoc:" << endl
                     << endl;
                chinhsuakhoahoc(data_admin);
                break;
            case 4:
                cout << "xoa khoa hoc:" << endl;
                xoakhoahoc(data_admin);
                break;
            case 5:
                cout << "xem danh sach khoa hoc:" << endl
                     << endl;
                for (int i = 0; i < data_admin.Get_dataList().size(); i++)
                {
                    cout << "STT " << i << endl;
                    cout << data_admin.Get_dataList()[i] << endl;
                }
                break;
            case 0:
                input = false;
                break;

            default:
                break;
            }
        }
    }
}

void menu::menu_course_schedules_of_admin(admin &data_admin)
{
    vector<string> result_vector;
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.nhap lich trinh cua khoa hoc tu tep csv: " << endl;
        cout << "2.them lich trinh cua khoa hoc: " << endl;
        cout << "3.chinh sua lich trinh cua khoa hoc: " << endl;
        cout << "4.xoa lich trinh cua khoa hoc: " << endl;
        cout << "5.xem danh sach lich trinh cua khoa hoc: " << endl;
        cout << "0.thoat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 5 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "nhap lich trinh cua khoa hoc tu tep csv: " << endl;
                nhaplichtrinh(result_vector, data_admin);
                break;
            case 2:
                cout << "them lich trinh cua khoa hoc:" << endl
                     << endl;
                themlichtrinh(data_admin);
                break;
            case 3:
                cout << "chinh sua lich trinh cua khoa hoc:" << endl
                     << endl;
                chinhsualichtrinh(data_admin);
                break;
            case 4:
                cout << "xoa lich trinh cua khoa hoc:" << endl;
                xoalichtrinh(data_admin);
                break;
            case 5:
                cout << "xem danh sach lich trinh cua khoa hoc:" << endl
                     << endl;
                for (int i = 0; i < data_admin.Get_dataList_schedules().size(); i++)
                {
                    cout << "STT " << i << endl;
                    cout << data_admin.Get_dataList_schedules()[i] << endl;
                }
                break;
            case 0:
                input = false;
                break;

            default:
                break;
            }
        }
    }
}

void menu::menu_attendance_of_admin(admin &data_admin)
{
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.tim kiem va xem danh sach tham du cua 1 khoa hoc: " << endl;
        cout << "2.xuat danh sach tham du sang tep csv: " << endl;
        cout << "0.thoat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 2 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "tim kiem va xem danh sach tham du cua 1 khoa hoc:" << endl;
                search_view_export(data_admin, numberFunction_);
                break;
            case 2:
                cout << "xuat danh sach tham du sang tep csv:" << endl;
                search_view_export(data_admin, numberFunction_);
                break;
            case 0:
                input = false;
                break;
            default:
                break;
            }
        }
    }
}

void menu::menu_scoreboard_of_admin(admin &data_admin, vector<lecturer> &data)
{
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.tim kiem va xem bang diem cua 1 khoa hoc: " << endl;
        cout << "2.xuat bang diem sang tep csv: " << endl;
        cout << "0.thoat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 2 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "tim kiem va xem bang diem cua 1 khoa hoc:" << endl;
                search_view_export(data_admin, numberFunction_, data);
                break;
            case 2:
                cout << "xuat bang diem sang tep csv:" << endl;
                search_view_export(data_admin, numberFunction_, data);
                break;
            case 0:
                input = false;
                break;
            default:
                break;
            }
        }
    }
}

void menu::menu_class_of_admin(admin &data_admin, vector<student> &data)
{
    vector<string> result_vector;
    bool input = true;
    cout << endl
         << endl;
    while (input == true)
    {
        cout << "1.nhap sinh vien cua lop hoc tu tep csv: " << endl;
        cout << "2.them sinh vien vao lop hoc: " << endl;
        cout << "3.chinh sua mot sinh vien hien co: " << endl;
        cout << "4.xoa sinh vien khoi mot lop hoc: " << endl;
        cout << "5.xem danh sach cac lop hoc: " << endl;
        cout << "6.chuyen sinh vien tu lop A sang lop B: " << endl;
        cout << "7.them lop trong: " << endl;
        cout << "8.xem danh sach hoc sinh cua mot lop: " << endl;
        cout << "0.thoat " << endl
             << endl;

        int numberFunction_;
        cout << "chon: ";
        cin >> numberFunction_;
        cin.ignore();
        cout << endl;

        if (numberFunction_ > 8 || numberFunction_ < 0)
        {
            cout << "khong hop le!" << endl
                 << endl;
        }
        else
        {
            switch (numberFunction_)
            {
            case 1:
                cout << "nhap sinh vien cua lop hoc tu tep csv: " << endl
                     << endl;
                nhapsinhviencuamotlophoc(data_admin);
                break;
            case 2:
                cout << "them sinh vien vao lop hoc:" << endl
                     << endl;
                themsinhvienvaolophoc(data_admin, data);
                break;
            case 3:
                cout << "chinh sua mot sinh vien hien co:" << endl
                     << endl;
                chinhsuasinhvienhienco(data_admin, data);
                break;
            case 4:
                cout << "xoa sinh vien khoi mot lop hoc:" << endl
                     << endl;
                xoasinhvienkhoilop(data_admin);
                break;
            case 5:
                cout << "xem danh sach cac lop hoc:" << endl
                     << endl;
                xemdanhsachcaclop(data_admin);
                break;
            case 6:
                cout << "chuyen sinh vien tu lop A sang lop B: " << endl
                     << endl;
                chuyensinhviensanglopkhac(data_admin, data);
                break;
            case 7:
                cout << "them lop trong:" << endl
                     << endl;
                themloptrong(data_admin);
                break;
            case 8:
                cout << "xem danh sach hoc sinh cua mot lop:" << endl
                     << endl;
                xemdanhsachhocsinh(data_admin);
                break;
            case 0:
                input = false;
                break;

            default:
                break;
            }
        }
    }
}

// function menu course of menu admin

int menu::count(string s)
{
    int result;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            return i;
            break;
        }
    }
    return -1;
}

void menu::stringProcessing_file_csv(string s, vector<string> &result)
{
    while (s.size() > 0)
    {
        string input;
        string line;
        int index = count(s) - 1;
        line = s.substr(0, index);
        result.push_back(line);
        input = s.substr(index + 3, s.size());
        if (count(input) != -1)
        {
            if (input.size() > 0)
            {
                return stringProcessing_file_csv(input, result);
            }
            return;
        }
        line = s.substr(index + 3, s.size());
        result.push_back(line);
        return;
    }
}

void menu::nhapkhoahoc(vector<string> &result_vector, admin &admin_)
{
    vector<information> result;
    information data[100];
    string line;
    ifstream output_file("../Data_structures/Data/course.csv");
    int count = 0;

    if (!output_file.is_open())
    {
        cout << "Could not open the file - " << endl;
        return;
    }
    while (getline(output_file, line))
    {
        stringProcessing_file_csv(line, result_vector);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        int j = i * 5;

        data[i].course_code_ = result_vector[j];
        data[i].year_ = result_vector[j + 1];
        data[i].semester_ = result_vector[j + 2];
        data[i].course_name_ = result_vector[j + 3];
        data[i].lecturer_username_ = result_vector[j + 4];
    }
    for (int k = 0; k < count; k++)
    {
        result.push_back(data[k]);
    }
    admin_.Set_dataList(result);
    cout << endl
         << "nhap thanh cong!" << endl
         << endl;
}

void menu::themkhoahoc(admin &admin_)
{
    information information_;
    cin >> information_;
    vector<information> data;
    data = admin_.Get_dataList();
    data.push_back(information_);
    admin_.Set_dataList(data);
    cout << endl
         << "them thanh cong!" << endl
         << endl;
}

void menu::chinhsuakhoahoc(admin &admin_)
{
    string line;
    vector<information> data;
    data = admin_.Get_dataList();
    cout << "nhap ma khoa hoc: ";
    getline(cin, line);
    for (int i = 0; i < data.size(); i++)
    {
        if (line.compare(data[i].course_code_) == 0)
        {
            cin >> data[i];
        }
    }
    admin_.Set_dataList(data);
    cout << "chinh sua thanh cong!" << endl
         << endl;
}

void menu::xoakhoahoc(admin &admin_)
{
    string line;
    vector<information> data;
    data = admin_.Get_dataList();
    cout << "nhap ma khoa hoc: ";
    getline(cin, line);
    for (int i = 0; i < data.size(); i++)
    {
        if (line.compare(data[i].course_code_) == 0)
        {
            data.erase(data.begin() + i);
        }
    }
    admin_.Set_dataList(data);
    cout << endl
         << "xoa thanh cong!" << endl
         << endl;
}

// function menu course's schdules of menu admin

void menu::nhaplichtrinh(vector<string> &result_vector, admin &admin_)
{
    vector<schedules> result;
    schedules data[100];
    string line;
    ifstream output_file("../Data_structures/Data/schedules.csv");
    int count = 0;

    if (!output_file.is_open())
    {
        cout << "Could not open the file - " << endl;
        return;
    }
    while (getline(output_file, line))
    {
        stringProcessing_file_csv(line, result_vector);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        int j = i * 5;

        data[i].start_at_ = result_vector[j];
        data[i].end_at_ = result_vector[j + 1];
        data[i].from_ = result_vector[j + 2];
        data[i].to_ = result_vector[j + 3];
        data[i].date_of_week = result_vector[j + 4];
    }
    for (int k = 0; k < count; k++)
    {
        result.push_back(data[k]);
    }
    admin_.Set_dataList(result);
    cout << endl
         << "nhap thanh cong!" << endl
         << endl;
}

void menu::themlichtrinh(admin &admin_)
{
    schedules schedules_;
    cin >> schedules_;
    vector<schedules> data;
    data = admin_.Get_dataList_schedules();
    data.push_back(schedules_);
    admin_.Set_dataList(data);
    cout << endl
         << "them thanh cong!" << endl
         << endl;
}

void menu::chinhsualichtrinh(admin &admin_)
{
    int line;
    vector<schedules> data;
    data = admin_.Get_dataList_schedules();
    cout << "nhap STT: ";
    cin >> line;
    cin.ignore();
    for (int i = 0; i < data.size(); i++)
    {
        if (line == i)
        {
            cin >> data[i];
        }
    }
    admin_.Set_dataList(data);
    cout << "chinh sua thanh cong!" << endl
         << endl;
}

void menu::xoalichtrinh(admin &admin_)
{
    int line;
    vector<schedules> data;
    data = admin_.Get_dataList_schedules();
    cout << "nhap STT: ";
    cin >> line;
    cin.ignore();
    for (int i = 0; i < data.size(); i++)
    {
        if (line == i)
        {
            data.erase(data.begin() + i);
        }
    }
    admin_.Set_dataList(data);
    cout << endl
         << "xoa thanh cong!" << endl
         << endl;
}

// function menu attendance of menu admin

void menu::search_view_export(admin &admin, int number)
{
    vector<course> list_course_;
    vector<user> list_user_;
    int count = 0;
    list_course_ = admin.Get_dataList_course();
    string line;
    cout << endl
         << "nhap khoa hoc: ";
    getline(cin, line);

    if (number == 1)
    {
        cout << endl
             << "danh sach tham du" << endl
             << endl;
        for (int i = 0; i < list_course_.size(); i++)
        {
            if (line.compare(list_course_[i].information_.course_name_) == 0)
            {
                count++;
                list_user_ = list_course_[i].Get_dataList();
                cout << "STT: " << count << " " << list_user_[0].name_ << " "
                     << list_user_[0].mssv_ << endl;
            }
        }
        cout << endl;
    }
    if (number == 2)
    {
        ofstream input_file;
        input_file.open("../Data_structures/result_Data/attendanceList.csv");
        input_file << "STT"
                   << " , "
                   << "ho va ten"
                   << " , "
                   << "MSSV" << endl;
        for (int i = 0; i < list_course_.size(); i++)
        {
            if (line.compare(list_course_[i].information_.course_name_) == 0)
            {
                count++;
                list_user_ = list_course_[i].Get_dataList();
                for (int j = 0; j < list_user_.size(); j++)
                {
                    input_file << count << " , " << list_user_[j].name_ << " , "
                               << list_user_[j].mssv_ << endl;
                }
            }
        }

        input_file.close();

        cout << endl
             << "xuat file thanh cong!" << endl
             << endl;
    }
}

// function menu scoreboard of menu admin

void menu::search_view_export(admin &admin_, int number, vector<lecturer> &data)
{
    vector<course> list_course;
    vector<user> list_user_;

    int count = 0;
    list_course = admin_.Get_dataList_course();
    string line;
    cout << "nhap khoa hoc: ";
    getline(cin, line);
    if (number == 1)
    {
        cout << endl
             << "bang diem" << endl
             << endl;
        for (int i = 0; i < list_course.size(); i++)
        {
            if (line.compare(list_course[i].information_.course_name_) == 0)
            {
                for (int j = 0; j < data.size(); j++)
                {
                    if (list_course[i].information_.lecturer_username_.compare(data[j].username_) == 0)
                    {
                        list_user_ = data[j].Get_dataList_user();
                        for (int k = i; k < i + 1; k++)
                        {
                            cout << "ho va ten: " << list_user_[k].name_ << endl
                                 << list_user_[k].score_ << endl;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    else if (number == 2)
    {
        ofstream input_file;
        input_file.open("../Data_structures/result_Data/scoreboard.csv");
        input_file << "ho va ten"
                   << " , "
                   << "MSSV"
                   << " , "
                   << "diem giua ky"
                   << " , "
                   << "diem phong thi nghiem"
                   << " , "
                   << "diem cuoi ky" << endl;
        for (int i = 0; i < list_course.size(); i++)
        {
            if (line.compare(list_course[i].information_.course_name_) == 0)
            {
                for (int j = 0; j < data.size(); j++)
                {
                    if (list_course[i].information_.lecturer_username_.compare(data[j].username_) == 0)
                    {
                        list_user_ = data[j].Get_dataList_user();
                        for (int k = i; k < i + 1; k++)
                        {
                            input_file << list_user_[k].name_ << " , "
                                       << list_user_[k].score_.studentId_ << " , "
                                       << list_user_[k].score_.midtermScore_ << " , "
                                       << list_user_[k].score_.labScore_ << " , "
                                       << list_user_[k].score_.finalScore_ << endl;
                        }
                    }
                }
            }
        }

        input_file.close();

        cout << endl
             << "xuat file thanh cong!" << endl
             << endl;
    }
}

// function menu class of menu admin

void menu::nhapsinhviencuamotlophoc(admin &admin_)
{
    student student_;
    vector<string> result_vector_student_csv;
    users data_2[100];
    int count_2 = 0;
    string line_2;
    ifstream output_file_2("../Data_structures/File_Users_.csv/student.csv");
    if (!output_file_2.is_open())
    {
        cout << "Could not open the file - " << endl;
        return;
    }
    while (getline(output_file_2, line_2))
    {
        stringProcessing_file_csv(line_2, result_vector_student_csv);
        count_2++;
    }
    for (int ii = 0; ii < count_2; ii++)
    {
        int jj = ii * 7;

        data_2[ii].fullname_ = result_vector_student_csv[jj];
        data_2[ii].username_ = stringProcessing(result_vector_student_csv[jj + 1]);
        data_2[ii].email_ = result_vector_student_csv[jj + 2];
        data_2[ii].password_ = result_vector_student_csv[jj + 3];
        data_2[ii].mobilephone_ = result_vector_student_csv[jj + 4];
        data_2[ii].type_ = result_vector_student_csv[jj + 6];
    }
    for (int kk = 0; kk < count_2; kk++)
    {
        dataList.push_back(data_2[kk]);
    }
    class_student class_student_;
    cout << "nhap ten lop hoc: ";
    getline(cin, class_student_.class_name_);
    vector<class_student> list_class = admin_.Get_dataList_class();
    for (int change = 0; change < count_2; change++)
    {
        student_.fullname_ = data_2[change].fullname_;
        student_.username_ = data_2[change].username_;
        student_.email_ = data_2[change].email_;
        student_.password_ = data_2[change].password_;
        student_.mobilephone_ = data_2[change].mobilephone_;
        student_.type_ = data_2[change].type_;

        dataList_student.push_back(student_);
        admin_.list_student_csv.push_back(student_);
    }
    for (int index = 0; index < admin_.list_student_csv.size(); index++)
    {
        class_student_.list_student.push_back(admin_.list_student_csv[index]);
    }

    list_class.push_back(class_student_);
    admin_.Set_dataList(list_class);
    cout << endl
         << "nhap thanh cong!" << endl
         << endl;
}

void menu::xemdanhsachhocsinh(admin &admin_)
{
    string line;
    cout << "nhap ten khoa hoc: ";
    getline(cin, line);

    cout << endl
         << "danh sach sinh vien" << endl
         << endl;

    for (int j = 0; j < admin_.Get_dataList_class().size(); j++)
    {
        if (line.compare(admin_.Get_dataList_class()[j].class_name_) == 0)
        {
            for (int i = 0; i < admin_.Get_dataList_class()[j].list_student.size(); i++)
            {
                cout << admin_.Get_dataList_class()[j].list_student[i] << endl;
            }
        }
    }
}

void menu::xemdanhsachcaclop(admin &admin_)
{
    if (admin_.Get_dataList_class().size() == 0)
    {
        cout << endl
             << "danh sach trong" << endl
             << endl;
    }
    else if (admin_.Get_dataList_class().size() != 0)
    {
        cout << endl
             << "danh sach cac lop" << endl
             << endl;
        for (int i = 0; i < admin_.Get_dataList_class().size(); i++)
        {
            cout << "STT " << i + 1 << " "
                 << "Ten lop hoc: " << admin_.Get_dataList_class()[i].class_name_ << endl;
        }
    }
    cout << endl;
}

void menu::themloptrong(admin &admin_)
{
    vector<class_student> list_class = admin_.Get_dataList_class();
    class_student class_student_;
    cout << "nhap ten lop hoc: ";
    getline(cin, class_student_.class_name_);
    list_class.push_back(class_student_);
    admin_.Set_dataList(list_class);
    cout << endl
         << "Them thanh cong!" << endl
         << endl;
}

void menu::xoasinhvienkhoilop(admin &admin_)
{
    string line;
    string line_2;
    cout << "nhap lop hoc: ";
    getline(cin, line);
    cout << "nhap MSSV: ";
    getline(cin, line_2);
    vector<class_student> list_class = admin_.Get_dataList_class();
    for (int i = 0; i < list_class.size(); i++)
    {
        if (line.compare(list_class[i].class_name_) == 0)
        {
            for (int j = 0; j < list_class[i].list_student.size(); j++)
            {
                if (line_2.compare(list_class[i].list_student[j].username_) == 0)
                {
                    list_class[i].list_student.erase(list_class[i].list_student.begin() + j);
                    break;
                }
            }
        }
    }
    admin_.Set_dataList(list_class);
    cout << endl
         << "xoa thanh cong" << endl
         << endl;
}

void menu::chuyensinhviensanglopkhac(admin &admin_, vector<student> &data)
{
    student student_;
    string line;
    cout << "nhap lop hoc: ";
    getline(cin, line);
    string line_2;
    cout << "nhap MSSV: ";
    getline(cin, line_2);
    vector<class_student> list_class = admin_.Get_dataList_class();
    for (int i = 0; i < list_class.size(); i++)
    {
        if (line.compare(list_class[i].class_name_) == 0)
        {
            for (int j = 0; j < list_class[i].list_student.size(); j++)
            {
                if (line_2.compare(list_class[i].list_student[j].username_) == 0)
                {
                    student_ = list_class[i].list_student[j];
                    list_class[i].list_student.erase(list_class[i].list_student.begin() + j);
                    break;
                }
            }
        }
    }
    string line_3;
    cout << "nhap lop chuyen den: ";
    getline(cin, line_3);
    for (int k = 0; k < list_class.size(); k++)
    {
        if (line_3.compare(list_class[k].class_name_) == 0)
        {
            list_class[k].list_student.push_back(student_);
            break;
        }
    }
    admin_.Set_dataList(list_class);
    cout << endl
         << "chuyen thanh cong" << endl
         << endl;
}

void menu::themsinhvienvaolophoc(admin &admin_, vector<student> &data)
{
    if (admin_.Get_dataList_class().size() > 1)
    {
        string line;
        string line_2;
        cout << "nhap lop hoc: ";
        getline(cin, line);
        cout << "nhap MSSV: ";
        getline(cin, line_2);
        student student_;
        vector<class_student> list_class = admin_.Get_dataList_class();
        for (int k = 0; k < data.size(); k++)
        {
            if (line_2.compare(data[k].username_) == 0)
            {
                student_ = data[k];
                break;
            }
        }
        for (int i = 0; i < list_class.size(); i++)
        {
            if (line.compare(list_class[i].class_name_) == 0)
            {
                list_class[i].list_student.push_back(student_);
            }
        }
        admin_.Set_dataList(list_class);
        cout << endl
             << "them thanh cong" << endl
             << endl;
    }
}

void menu::chinhsuasinhvienhienco(admin &admin_, vector<student> &data)
{
    string line_2;
    cout << "nhap lop hoc: ";
    getline(cin, line_2);
    string line;
    cout << "nhap MSSV: ";
    getline(cin, line);
    vector<class_student> list_class = admin_.Get_dataList_class();
    for (int j = 0; j < list_class.size(); j++)
    {
        if (line_2.compare(list_class[j].class_name_) == 0)
        {
            for (int k = 0; k < list_class[j].list_student.size(); k++)
            {
                if (line.compare(list_class[j].list_student[k].username_) == 0)
                {
                    for (int i = 0; i < data.size(); i++)
                    {
                        if (list_class[j].list_student[k].username_.compare(data[i].username_) == 0)
                        {
                            student student_;
                            student_.email_ = data[i].email_;
                            student_.username_ = data[i].username_;
                            student_.type_ = data[i].type_;
                            cin >> student_;
                            data[i] = student_;
                            list_class[j].list_student[k] = student_;
                            break;
                        }
                    }
                }
            }
        }
    }
    admin_.Set_dataList(list_class);

    cout << endl
         << "chinh sua thanh cong" << endl
         << endl;
}

string menu::stringProcessing(string input)  
{
    int size_ = input.size();
    int index = 1;
    for (int i = 0; i < size_; i++)
    {
        if (input[i] == ' ')
        {
            input.erase(input.begin() + index, input.begin() + i + 1);
            break;
        }
    }

    for (int j = 0; j < size_; j++)
    {
        if (input[j] == ' ')
        {
            input.erase(input.begin() + index + 1, input.begin() + j + 1);
            break;
        }
    }

    for (int k = 0; k <= 2; k++)
    {

        if ('A' <= input[k] && input[k] <= 'Z')
        {
            input[k] = input[k] + ((int)('a') - (int)('A'));
        }
    }

    return input;
}