// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "tkacheva_group.h"

//BOOL APIENTRY DllMain( HMODULE hModule,
//                       DWORD  ul_reason_for_call,
//                       LPVOID lpReserved
//                     )
//{
//    switch (ul_reason_for_call)
//    {
//    case DLL_PROCESS_ATTACH:
//    case DLL_THREAD_ATTACH:
//    case DLL_THREAD_DETACH:
//    case DLL_PROCESS_DETACH:
//        break;
//    }
//    return TRUE;
//}

tkacheva_group group;

extern "C" {
	__declspec(dllexport) void __stdcall GetClassStudent(ClassStudent& s, int i)
	{
		group.get(i)->to_class_student(s);
	}

	__declspec(dllexport) void __stdcall SetClassStudent(ClassStudent& s, int i)
	{
		group.get(i)->from_class_student(s);
	}

	__declspec(dllexport) int __stdcall GetGroupSize()
	{
		return group.get_size();
	}

	__declspec(dllexport) void __stdcall Erase(int i)
	{
		group.delete_student(i);
	}

	__declspec(dllexport) void __stdcall AddStudent()
	{
		group.add_student(make_shared<tkacheva_student>());
	}

	__declspec(dllexport) void __stdcall AddHeadman()
	{
		group.add_student(make_shared<tkacheva_headman>());
	}

	__declspec(dllexport) void __stdcall SaveData(const char* filename)
	{
		group.save(filename);
	}
	__declspec(dllexport) void __stdcall LoadData(const char* filename)
	{
		group.load(filename);
	}
}