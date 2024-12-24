#pragma once
#include "pch.h"
#include <iostream>
#include "ClassStudent.h"

using namespace std;

class tkacheva_student
{
private:
    friend class boost::serialization::access;
protected:
    string name = "Имя";
    string last_name = "Фамилия";
    int age = 0;
public:
    tkacheva_student() {}
    virtual ~tkacheva_student() {}
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& last_name;
        ar& age;
    }
    virtual void to_class_student(ClassStudent& s);
    virtual void from_class_student(ClassStudent& s);
};