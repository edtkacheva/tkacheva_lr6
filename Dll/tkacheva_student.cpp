#include "pch.h"
#include "tkacheva_student.h"

using namespace std;

BOOST_CLASS_IMPLEMENTATION(tkacheva_student, boost::serialization::level_type::object_serializable);

void tkacheva_student::to_class_student(ClassStudent& s)
{
	s.baseclass = 1;
	strcpy_s(s.name, name.c_str());
	strcpy_s(s.lastname, last_name.c_str());
	s.age = age;
}

void tkacheva_student::from_class_student(ClassStudent& s)
{
	name = s.name;
	last_name = s.lastname;
	age = s.age;

}