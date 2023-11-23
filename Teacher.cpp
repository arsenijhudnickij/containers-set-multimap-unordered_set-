#include "libraries.h"
#include "Teacher.h"

Teacher::Teacher()
{
    work_experience = 0;
}
Teacher::Teacher(const Teacher& object)
{
    work_experience = object.work_experience;
}

void Teacher::showData()
{
    std::cout << "��� ������������� : " << this->name << std::endl;
    std::cout << "������� �������������:" << this->age << std::endl;
    std::cout << "���������� ��� ����� �������������:" << this->work_experience << std::endl;
    std::cout << "\n";
}