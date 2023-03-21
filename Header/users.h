#ifndef USERS_H
#define USERS_H

#include "../Header/header.h"

class users
{
public:
    string username_;
    string fullname_;
    string email_;
    string mobilephone_;
    string type_;
    string password_;
    string class_;

public:
    users();
    ~users();

public:
    friend ostream &operator<<(ostream &os, users &use)
    {
        os << "ho va ten: " << use.fullname_ << endl;
        os << "email: " << use.email_ << endl;
        os << "user: " << use.username_ << endl;
        os << "password: " << use.password_ << endl;
        os << "mobilephone: " << use.mobilephone_ << endl;
        os << "type: " << use.type_ << endl;
        return os;
    }
    friend istream &operator>>(istream &in, users &use)
    {
        cout << "ho va ten: ";
        in >> use.fullname_;
        cout << "password: ";
        in >> use.password_;
        cout << "mobilephone: ";
        in >> use.mobilephone_;
        return in;
    }
};

#endif