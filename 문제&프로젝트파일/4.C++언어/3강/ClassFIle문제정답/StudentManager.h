#pragma once
#include"Student.h"

#define STUDENT_MAX 10

class StudentManager
{
private:
	int m_iStudentCount = 0;
	Student* m_StudentList[STUDENT_MAX] = { NULL };
public:
	void AddStudent();
	void ShowStudentList();
	inline int GetStudentCount()
	{
		return m_iStudentCount;
	}
	bool FindStudentName(string Name);
	bool ShowStudentClass(CLASS Class);
	void DeleteStudent();
	void ClearStudent();
	StudentManager();
	~StudentManager();
};

