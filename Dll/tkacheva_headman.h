#pragma once
#include "pch.h"
#include "tkacheva_student.h"

class tkacheva_headman : public tkacheva_student
{
    friend class boost::serialization::access;
private:
    string group_name = "Группа";
    string email = "Почта";
public:
    BOOST_SERIALIZATION_SPLIT_MEMBER()
        tkacheva_headman() {}
    ~tkacheva_headman() override {}
    template<class Archive>
    void save(Archive& ar, const unsigned int version) const
    {
        ar& boost::serialization::base_object<tkacheva_student>(*this);
        ar << group_name;
        ar << email;
    }
    template<class Archive>
    void load(Archive& ar, const unsigned int version)
    {
        ar >> boost::serialization::base_object<tkacheva_student>(*this);
        ar >> group_name;
        ar >> email;
    }
    void to_class_student(ClassStudent& s);
    void from_class_student(ClassStudent& s);
};