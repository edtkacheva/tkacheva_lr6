#include "pch.h"
#include "tkacheva_headman.h"

void tkacheva_headman::to_class_student(ClassStudent& s)
{
	tkacheva_student::to_class_student(s);
	s.baseclass = 0;
	strcpy_s(s.group_name, group_name.c_str());
	strcpy_s(s.email, email.c_str());
}

void tkacheva_headman::from_class_student(ClassStudent& s)
{
	tkacheva_student::from_class_student(s);
	group_name = s.group_name;
	email = s.email;
}