#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Test.h"
#include "libraries.h"

int check() {
    int number;
    std::cin >> number;
    while (std::cin.fail() || std::cin.get() != '\n' || number < 0) {
        {
            std::cout << "\nO����� �����.\n��������� �������:";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> number;
        }
    }
    return number;
}
float check1() {
    float number;
    std::cin >> number;
    while (std::cin.fail() || std::cin.get() != '\n' || number < 0) {
        {
            std::cout << "\nO����� �����.\n��������� �������:";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> number;
        }
    }
    return number;
}


const std::string name_fil = "..//File//Persons1.txt";
const std::string name_fik_test = "..//File//Tests1.txt";


int main()
{
    system("chcp 1251");
    system("cls");
    Person* pers = NULL;
   
    std::unordered_set<Person*> teachers;
    std::multimap<float, Person*> students;
    std::set<Test*> tests;

    Test* test = NULL;

    int choice{};
    do {
        std::cout << "1.�������� �������" << std::endl;
        std::cout << "2.�������� �������" << std::endl;
        std::cout << "3.�������� ����" << std::endl;
        std::cout << "4.����������� ���� ��������" << std::endl;
        std::cout << "5.����������� ���� ��������" << std::endl;
        std::cout << "6.���������� ��� �����" << std::endl;
        std::cout << "7.������������� ���� �������� �� ��������" << std::endl;
        std::cout << "8.������������� ��� ����� �� ��������" << std::endl;
        std::cout << "9.������������� �������� �� �������� �����" << std::endl;
        std::cout << "10.����� ������� �� �����" << std::endl;
        std::cout << "11.����� ������� �� �������� �����" << std::endl;
        std::cout << "12.����� ����� �� ��������" << std::endl;
        std::cout << "13.�������� �������" << std::endl;
        std::cout << "14.�������� �������" << std::endl;
        std::cout << "15.�������� �����" << std::endl;
        std::cout << "16.��������� ����� �������" << std::endl;
        std::cout << "17.��������� ����� �������������" << std::endl;
        std::cout << "18.��������� �������� �����" << std::endl;
        std::cout << "19.�����" << std::endl;

        std::cout << "\n\n";
        std::cout << "��� �����?" << std::endl;

        try {
            if (!(std::cin >> choice))
                throw std::runtime_error("�������� ���� ������");
        }
        catch (std::runtime_error errr) {

            std::cout << errr.what() << std::endl;
            system("pause");
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        std::cin.clear();
        std::cin.ignore(1024, '\n');
        system("cls");
        switch (choice)
        {
        case 1:
        {
            
            std::string name_st;
            std::cout << "������� ��� �������" << std::endl;
            std::getline(std::cin, name_st);
            int age_st;
            std::cout << "������� ������� �������" << std::endl;
            age_st = check();
            int year_of;
            std::cout << "������� ���������� ��� �������� �������:" << std::endl;
            year_of = check();
            float GPA;
            std::cout << "������� ������� ���� �������" << std::endl;
            GPA = check1();
            pers = new Student(name_st, age_st, year_of);
            students.emplace(GPA, pers);
            std::cout << "������� ��������" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            std::string name_tch;
            std::cout << "������� ��� �������������" << std::endl;
            std::getline(std::cin, name_tch);
            int age_tch;
            std::cout << "������� ������� �������������" << std::endl;
            age_tch = check();
            int year_of;
            std::cout << "������� ���� �������������:" << std::endl;
            year_of = check();

            pers = new Teacher(name_tch, age_tch, year_of);
            teachers.insert(pers);
            std::cout << "������� ��������" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            std::string name_test;
            std::cout << "������� �������� �����:" << std::endl;
            std::getline(std::cin, name_test);
            std::vector<std::string> quest;
            std::string pointer = "y";
            do {
                std::string question;
                std::cout << "������� ��� ������?" << std::endl;
                std::getline(std::cin, question);
                quest.push_back(question);
                std::cout << "������ ���������� ����?(���� �� - y)" << std::endl;
                std::getline(std::cin, pointer);
            } while (pointer == "y");
            test = new Test(name_test, quest);
            tests.insert(test);
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            std::cout<< "---------------------------------------------------------------------------\n";
            std::cout << "|                             �������                                    |\n";
            std::cout << "--------------------------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << std::setw(18) << "������� ����    |\n";
            std::cout << "---------------------------------------------------------------------------\n";
            for (auto& item : students)
            {
                pers = item.second;
                std::cout << '|' << std::setw(20) << std::left << pers->getName() << '|' << std::setw(20)
                    << pers->getAge() << '|' << std::setw(12) << pers->getYear() << " |"<<std::setw(16) << item.first << "|" << std::endl;
                std::cout << "---------------------------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       �������������                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(9) << "���� ������  |\n";
            std::cout << "---------------------------------------------------------\n";
            for (auto& item : teachers)
            {
                std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                    << item->getAge() << '|' << std::setw(4) << item->getWork() << "         |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            for (auto &item : tests)
            {
                item->printQuestions();
            }
            std::cout << "\n";
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        
        case 7:
        {
            std::list<int> sort;
            for (auto& item : teachers)
            {
                sort.push_back(item->getAge());
            }

            sort.sort();

            std::cout << "��������������� ������:" << std::endl;
            for (std::list<int>::iterator it = sort.begin(); it != sort.end(); it++)
            {
                for (auto& item : teachers)
                {
                    if (item->getAge() == *it)
                    {
                        item->showData();
                    }
                }
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            std::string* temporary = new std::string[tests.size()];
            int i = 0;
            for (auto& item : tests) {
                temporary[i] = item->get_name();
                i++;
            }
            for (int k = 0; k < tests.size(); k++) {
                for (int j = tests.size() - 1; j > k; j--) {
                    if (temporary[j - 1] > temporary[j]) {
                        swap(temporary[j - 1], temporary[j]);
                    }
                }
            }
            for (int j = 0; j < tests.size(); j++) {
                for (auto& item : tests)
                {
                    if (temporary[j] == item->get_name())
                    {
                        item->printQuestions();
                    }
                }
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 9:
        {
            std::list<float> sort;
            for (auto& item : students)
            {
                float G;
                G = item.first;
                sort.push_back(G);
            }

            sort.sort();

            std::cout << "��������������� ������:" << std::endl;
            for (std::list<float>::iterator it = sort.begin(); it != sort.end(); it++)
            {
                for (auto& item : students)
                {
                    pers = item.second;
                    float av;
                    av = item.first;
                    if ( av == *it)
                    {
                        pers->showData();;
                        std::cout << "������� ����: " << av << std::endl;
                        std::cout << "\n";
                    }
                }
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 10:
        {
            std::string name_poi;
            std::cout << "������� ������� ���:" << std::endl;
            std::getline(std::cin, name_poi);
            int i = 0;
            for (auto& item : teachers)
            {
                if (item->getName() == name_poi)
                {
                    std::cout << "������� ������\n" << std::endl;
                    item->showData();
                    i++;
                    break;
                }
            }
            if (i == 0)
            {
                std::cout << "����������� ������� � ����� ������" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 11:
        {
            std::string name_poi;
            std::cout << "������� ������� ���:" << std::endl;
            std::getline(std::cin, name_poi);
            for (auto& item : students)
            {
                pers = item.second;
                if (pers->getName() == name_poi)
                {
                    std::cout << "������ ������\n" << std::endl;
                    pers->showData();
                    std::cout << "������� ����: " << item.first << std::endl;
                }
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 12:
        {
            std::string name_poi;
            std::cout << "������� ������� ����:" << std::endl;
            std::getline(std::cin, name_poi);
            int i = 0;
            for (auto& item : tests)
            {
                if (item->get_name() == name_poi)
                {
                    std::cout << "���� ������\n" << std::endl;
                    item->printQuestions();
                    i++;
                    break;
                }
            }
            if (i == 0)
            {
                std::cout << "����������� ����� � ����� ������" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 13:
        {
            std::cout << "---------------------------------------------------------------------------\n";
            std::cout << "|                             �������                                    |\n";
            std::cout << "--------------------------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << std::setw(18) << "������� ����    |\n";
            std::cout << "---------------------------------------------------------------------------\n";
            for (auto& item : students)
            {
                pers = item.second;
                std::cout << '|' << std::setw(20) << std::left << pers->getName() << '|' << std::setw(20)
                    << pers->getAge() << '|' << std::setw(12) << pers->getYear() << " |" << std::setw(16) << item.first << "|" << std::endl;
                std::cout << "---------------------------------------------------------------------------\n";
            }
            std::cout << "\n";
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "������� ��� �������, �������� ������ �������" << std::endl;
            std::getline(std::cin, name_poi);
            int x = 0;
            int flag = 0;
            float GPA;
            for (auto& item : students)
            {
                GPA = item.first;
                pers = item.second;
                if (pers->getName() == name_poi)
                {
                    flag = 1;
                    students.erase(GPA);
                    std::cout << "������ ������" << std::endl;
                    break;
                }
                x++;
            }
            if (flag == 0)
            {
                std::cout << "������ ������� ���" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 14:
        {
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       �������������                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "��������� " << '|' << std::setw(9) << "���� ������  |\n";
            std::cout << "---------------------------------------------------------\n";
            for (auto& item : teachers)
            {
                std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                    << item->getAge() << '|' << std::setw(4) << item->getWork() << "         |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "������� ��� �������, �������� ������ �������" << std::endl;
            std::getline(std::cin, name_poi);
            int x = 0;
            int flag = 0;
            for (auto& item : teachers)
            {
                if (item->getName() == name_poi)
                {
                    flag = 1;
                    teachers.erase(item);
                    std::cout << "������������� ������" << std::endl;
                    
                    break;
                }
                x++;
            }
            if (flag == 0)
            {
                std::cout << "������ ������������� ���" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 15:
        {
            for (auto& item : tests)
            {
                item->printQuestions();
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "������� �������� �����, ������� ������ �������" << std::endl;
            std::getline(std::cin, name_poi);
            int x = 0;
            for (auto& item : tests)
            {
                if (item->get_name() == name_poi)
                {
                    tests.erase(item);
                    std::cout << "���� ������" << std::endl;
                    x++;
                    break;
                }
            }
            if (x == 0)
            {
                std::cout << "������ ����� ���" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 16:
        {           
            std::cout << "---------------------------------------------------------------------------\n";
            std::cout << "|                             �������                                    |\n";
            std::cout << "--------------------------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << std::setw(18) << "������� ����    |\n";
            std::cout << "---------------------------------------------------------------------------\n";
            for (auto& item : students)
            {
                pers = item.second;
                std::cout << '|' << std::setw(20) << std::left << pers->getName() << '|' << std::setw(20)
                    << pers->getAge() << '|' << std::setw(12) << pers->getYear() << " |" << std::setw(16) << item.first << "|" << std::endl;
                std::cout << "---------------------------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "������� ���, ������� ������ ��������:" << std::endl;
            std::getline(std::cin, name_poi);
            int poi = 0;
            for (auto& item : students)
            {
                pers = item.second;
                if (pers->getName() == name_poi)
                {
                    poi = 1;
                    std::string name_new;
                    std::cout << "������� ����� ���, ������� ����� � �������:" << std::endl;
                    std::getline(std::cin, name_new);
                    pers->setName(name_new);
                    std::cout << "��� ��������" << std::endl;
                    item.second = pers;
                    break;
                }
            }
            if (poi == 0)
            {
                std::cout << "������ ������� ���" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 17:
        {
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       �������������                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "��������� " << '|' << std::setw(9) << "���� ������  |\n";
            std::cout << "---------------------------------------------------------\n";
            for (auto& item : teachers)
            {
                std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                    << item->getAge() << '|' << std::setw(4) << item->getWork() << "         |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "������� ���, ������� ������ ��������:" << std::endl;
            std::getline(std::cin, name_poi);
            int poi = 0;
            for (auto& item : teachers)
            {
                if (item->getName() == name_poi)
                {
                    std::string name_new;
                    poi = 1;
                    std::cout << "������� ����� ���, ������� ����� � �������������:" << std::endl;
                    std::getline(std::cin, name_new);
                    item->setName(name_new);
                    std::cout << "��� ��������" << std::endl;
                    break;
                }
            }
            if (poi == 0)
            {
                std::cout << "������ ������������� ���" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 18:
        {
            for (auto& item : tests)
            {
                item->printQuestions();
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "������� ��������, ������� ������ ��������:" << std::endl;
            std::getline(std::cin, name_poi);
            int poi = 0;
            for (auto& item : tests)
            {
                if (item->get_name() == name_poi)
                {
                    std::string name_new;
                    poi = 1;
                    std::cout << "������� ����� ��������, ������� ����� � �����:" << std::endl;
                    std::getline(std::cin, name_new);
                    item->setName(name_new);
                    std::cout << "��� ��������" << std::endl;
                    break;
                }
            }
            if (poi == 0)
            {
                std::cout << "������ ����� ���" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 19:
            break;
        default:
            std::cout << "�������� ����" << std::endl;
        }
    } while (choice != 19);

    std::ofstream File;
    File.open(name_fil, std::ios::binary);
    if (File.is_open())
    {
        File<< "---------------------------------------------------------------------------\n";
        File << "|                             �������                                    |\n";
        File << "--------------------------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << std::setw(18) << "������� ����    |\n";
        File << "---------------------------------------------------------------------------\n";
        for (auto& item : students)
        {
            pers = item.second;
            File << '|' << std::setw(20) << std::left << pers->getName() << '|' << std::setw(20)
                << pers->getAge() << '|' << std::setw(12) << pers->getYear() << " |" << std::setw(16) << item.first << "|" << std::endl;
            File << "---------------------------------------------------------------------------\n";
        }
        File <<  "---------------------------------------------------------\n";
        File << "|                       �������������                   |\n";
        File << "---------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(9) << "���� ������  |\n";
        File << "---------------------------------------------------------\n";
        for (auto& item : teachers)
        {
            File << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                << item->getAge() << '|' << std::setw(4) << item->getWork() << "         |" << std::endl;
            File << "---------------------------------------------------------\n";
        }
        std::cout << "������ ������� �������� � ����\n";
    }
    else std::cout << "������ �������� �����\n";
    File.close();

    std::ofstream File1;
    File1.open(name_fik_test, std::ios::binary);
    if (File1.is_open())
    {
        for (auto& item : tests)
        {
            File1 <<"�������� �����:  "<< item->get_name();
            File1 << "\n";
            File1 << "�������:\n";
            for (int j = 0; j < item->get_col_que(); j++)
            {
                File1 << item->get_quest(j);
                File1 << "\n";
            }
            File1 << "\n\n";
        }
    }
    else std::cout << "������ �������� �����\n";
    File1.close();
    return 0;
}