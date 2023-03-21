#include "../Header/app.h"

app::app()
{
}

app::~app()
{
}

void app::LogIn()
{
    cout << endl
         << "student_Management_System" << endl
         << endl;

    string tk;
    cout << "Tai khoan: ";
    getline(cin, tk);
    string mk;
    cout << "Mat khau:  ";
    getline(cin, mk);
    for (int i = 0; i < dataList.size(); i++)
    {
        if (tk.compare(dataList[i].username_) == 0)
        {
            if (dataList[i].type_.compare("student") == 0)
            {
                for (int type_chang = 0; type_chang < dataList_student.size(); type_chang++)
                {
                    if (dataList_student[type_chang].username_.compare(tk) == 0)
                    {
                        if (mk.compare(dataList_student[type_chang].password_) == 0)
                        {
                            cout << endl
                                 << "Dang nhap thanh cong!" << endl
                                 << endl;
                            menu_.menu_of_student(dataList_student[type_chang], dataList_admin[4], dataList_lecturer);
                            for (int type_chang2 = 0; type_chang2 < dataList.size(); type_chang2++)
                            {
                                for (int type_chang3 = 0; type_chang3 < dataList_student.size(); type_chang3++)
                                {
                                    if (dataList[type_chang2].username_.compare(dataList_student[type_chang3].username_) == 0)
                                    {
                                        dataList[type_chang2] = dataList_student[type_chang3];
                                        break;
                                    }
                                }
                            }
                            UpdateAccount("../Data_structures/Data/account.csv");
                            LogIn();
                        }
                    }
                }
            }
            if (dataList[i].type_.compare("lecturer") == 0)
            {
                for (int type_chang = 0; type_chang < dataList_lecturer.size(); type_chang++)
                {
                    if (dataList_lecturer[type_chang].username_.compare(tk) == 0)
                    {
                        if (mk.compare(dataList_lecturer[type_chang].password_) == 0)
                        {
                            cout << endl
                                 << "Dang nhap thanh cong!" << endl
                                 << endl;
                            menu_.menu_of_lecturer(dataList_lecturer[type_chang], dataList_admin[4]);
                            for (int type_chang2 = 0; type_chang2 < dataList.size(); type_chang2++)
                            {
                                for (int type_chang3 = 0; type_chang3 < dataList_lecturer.size(); type_chang3++)
                                {
                                    if (dataList[type_chang2].username_.compare(dataList_lecturer[type_chang3].username_) == 0)
                                    {
                                        dataList[type_chang2] = dataList_lecturer[type_chang3];
                                        break;
                                    }
                                }
                            }
                            UpdateAccount("../Data_structures/Data/account.csv");
                            LogIn();
                        }
                    }
                }
            }
            if (dataList[i].type_.compare("admin") == 0)
            {
                for (int type_chang = 0; type_chang < dataList_admin.size(); type_chang++)
                {
                    if (dataList_admin[type_chang].username_.compare(tk) == 0)
                    {
                        if (mk.compare(dataList_admin[type_chang].password_) == 0)
                        {
                            cout << endl
                                 << "Dang nhap thanh cong!" << endl
                                 << endl;
                            menu_.menu_of_admin(dataList_admin[type_chang], dataList_lecturer, dataList_student);
                            for (int type_chang2 = 0; type_chang2 < dataList.size(); type_chang2++)
                            {
                                for (int type_chang3 = 0; type_chang3 < dataList_student.size(); type_chang3++)
                                {
                                    if (dataList[type_chang2].username_.compare(dataList_student[type_chang3].username_) == 0)
                                    {
                                        dataList[type_chang2] = dataList_student[type_chang3];
                                        break;
                                    }
                                }
                            }
                            for (int type_chang2 = 0; type_chang2 < dataList.size(); type_chang2++)
                            {
                                for (int type_chang3 = 0; type_chang3 < dataList_admin.size(); type_chang3++)
                                {
                                    if (dataList[type_chang2].username_.compare(dataList_admin[type_chang3].username_) == 0)
                                    {
                                        dataList[type_chang2] = dataList_admin[type_chang3];
                                        break;
                                    }
                                }
                            }
                            UpdateAccount("../Data_structures/Data/account.csv");
                            LogIn();
                        }
                    }
                }
            }
        }
    }
    cout << endl
         << "Ten tai Khoan hoac mat khau khong dung!" << endl;
    LogIn();
}

void app::rundata()
{
    student student_;
    lecturer lecturer_;
    admin admin_;

    int count = 0;

    users data[100];

    vector<string> result_vector;
    vector<string> result_vector_student_csv;

    string line;

    ifstream output_file("../Data_structures/Data/data.csv");
    if (!output_file.is_open())
    {
        cout << "Could not open the file - " << endl;
        return;
    }

    //  xử lý file
    while (getline(output_file, line))
    {
        stringProcessing_file_csv(line, result_vector);
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        int j = i * 7;

        data[i].fullname_ = result_vector[j];
        data[i].username_ = stringProcessing(result_vector[j + 1]);
        data[i].email_ = result_vector[j + 2];
        data[i].password_ = result_vector[j + 3];
        data[i].mobilephone_ = result_vector[j + 4];
        data[i].type_ = result_vector[j + 6];
    }
    for (int k = 0; k < count; k++)
    {
        dataList.push_back(data[k]);
    }
    UpdateAccount("../Data_structures/Data/account.csv");
    for (int change = 0; change < dataList.size(); change++)
    {
        if (dataList[change].type_.compare("student") == 0)
        {
            student_.fullname_ = dataList[change].fullname_;
            student_.username_ = dataList[change].username_;
            student_.email_ = dataList[change].email_;
            student_.password_ = dataList[change].password_;
            student_.mobilephone_ = dataList[change].mobilephone_;
            student_.type_ = dataList[change].type_;
            dataList_student.push_back(student_);
        }
        if (dataList[change].type_.compare("lecturer") == 0)
        {
            lecturer_.fullname_ = dataList[change].fullname_;
            lecturer_.username_ = dataList[change].username_;
            lecturer_.email_ = dataList[change].email_;
            lecturer_.password_ = dataList[change].password_;
            lecturer_.mobilephone_ = dataList[change].mobilephone_;
            lecturer_.type_ = dataList[change].type_;
            dataList_lecturer.push_back(lecturer_);
        }
        if (dataList[change].type_.compare("admin") == 0)
        {
            admin_.fullname_ = dataList[change].fullname_;
            admin_.username_ = dataList[change].username_;
            admin_.email_ = dataList[change].email_;
            admin_.password_ = dataList[change].password_;
            admin_.mobilephone_ = dataList[change].mobilephone_;
            admin_.type_ = dataList[change].type_;
            dataList_admin.push_back(admin_);
        }
    }
    // xu ly file sinh vien nhap tu csv
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
    UpdateAccount("../Data_structures/Data/account.csv");
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
}

void app::UpdateAccount(string file_path)
{
    ofstream input_file;
    input_file.open(file_path);
    input_file << "Tai khoan"
               << " , "
               << "Mat khau"
               << " , "
               << "type" << endl;
    for (int i = 0; i < dataList.size(); i++)
    {
        input_file << dataList[i].username_ << " , " << dataList[i].password_
                   << " , " << dataList[i].type_ << endl;
    }
    input_file.close();
}

// function xử lý chuỗi

int app::count(string s)
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

void app::stringProcessing_file_csv(string s, vector<string> &result)
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

string app::stringProcessing(string input)
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
