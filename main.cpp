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
            std::cout << "\nOшибка ввода.\nПовторите попытку:";
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
            std::cout << "\nOшибка ввода.\nПовторите попытку:";
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
        std::cout << "1.Добавить ученика" << std::endl;
        std::cout << "2.Добавить учителя" << std::endl;
        std::cout << "3.Добавить тест" << std::endl;
        std::cout << "4.Просмотреть всех учеников" << std::endl;
        std::cout << "5.Просмотреть всех учителей" << std::endl;
        std::cout << "6.Посмотреть все тесты" << std::endl;
        std::cout << "7.Отсортировать всех учителей по возрасту" << std::endl;
        std::cout << "8.Отсортировать все тесты по названию" << std::endl;
        std::cout << "9.Отсортировать учеников по среднему баллу" << std::endl;
        std::cout << "10.Поиск учителя по имени" << std::endl;
        std::cout << "11.Поиск ученика по среднему баллу" << std::endl;
        std::cout << "12.Поиск теста по названию" << std::endl;
        std::cout << "13.Удаление ученика" << std::endl;
        std::cout << "14.Удаление учителя" << std::endl;
        std::cout << "15.Удаление теста" << std::endl;
        std::cout << "16.Изменение имени ученика" << std::endl;
        std::cout << "17.Изменение имени преподавателя" << std::endl;
        std::cout << "18.Изменение названия теста" << std::endl;
        std::cout << "19.Выход" << std::endl;

        std::cout << "\n\n";
        std::cout << "Ваш выбор?" << std::endl;

        try {
            if (!(std::cin >> choice))
                throw std::runtime_error("Неверный ввод данных");
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
            std::cout << "Введите имя ученика" << std::endl;
            std::getline(std::cin, name_st);
            int age_st;
            std::cout << "Введите возраст ученика" << std::endl;
            age_st = check();
            int year_of;
            std::cout << "Введите количество лет обучения ученика:" << std::endl;
            year_of = check();
            float GPA;
            std::cout << "Введите средний балл ученика" << std::endl;
            GPA = check1();
            pers = new Student(name_st, age_st, year_of);
            students.emplace(GPA, pers);
            std::cout << "Успешно добавлен" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            std::string name_tch;
            std::cout << "Введите имя преподавателя" << std::endl;
            std::getline(std::cin, name_tch);
            int age_tch;
            std::cout << "Введите возраст преподавателя" << std::endl;
            age_tch = check();
            int year_of;
            std::cout << "Введите стаж преподавателя:" << std::endl;
            year_of = check();

            pers = new Teacher(name_tch, age_tch, year_of);
            teachers.insert(pers);
            std::cout << "Успешно добавлен" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            std::string name_test;
            std::cout << "Введите название теста:" << std::endl;
            std::getline(std::cin, name_test);
            std::vector<std::string> quest;
            std::string pointer = "y";
            do {
                std::string question;
                std::cout << "Введите ваш вопрос?" << std::endl;
                std::getline(std::cin, question);
                quest.push_back(question);
                std::cout << "Хотите продолжить ввод?(если да - y)" << std::endl;
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
            std::cout << "|                             УЧЕНИКИ                                    |\n";
            std::cout << "--------------------------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << std::setw(18) << "Средний балл    |\n";
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
            std::cout << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(9) << "Стаж работы  |\n";
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

            std::cout << "Отсортированный список:" << std::endl;
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

            std::cout << "Отсортированный список:" << std::endl;
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
                        std::cout << "Средний балл: " << av << std::endl;
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
            std::cout << "Введите искомое имя:" << std::endl;
            std::getline(std::cin, name_poi);
            int i = 0;
            for (auto& item : teachers)
            {
                if (item->getName() == name_poi)
                {
                    std::cout << "Учитель найден\n" << std::endl;
                    item->showData();
                    i++;
                    break;
                }
            }
            if (i == 0)
            {
                std::cout << "Отсутствует учитель с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 11:
        {
            std::string name_poi;
            std::cout << "Введите искомое имя:" << std::endl;
            std::getline(std::cin, name_poi);
            for (auto& item : students)
            {
                pers = item.second;
                if (pers->getName() == name_poi)
                {
                    std::cout << "Ученик найден\n" << std::endl;
                    pers->showData();
                    std::cout << "Средний балл: " << item.first << std::endl;
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
            std::cout << "Введите искомый тест:" << std::endl;
            std::getline(std::cin, name_poi);
            int i = 0;
            for (auto& item : tests)
            {
                if (item->get_name() == name_poi)
                {
                    std::cout << "Тест найден\n" << std::endl;
                    item->printQuestions();
                    i++;
                    break;
                }
            }
            if (i == 0)
            {
                std::cout << "Отсутствуют тесты с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 13:
        {
            std::cout << "---------------------------------------------------------------------------\n";
            std::cout << "|                             УЧЕНИКИ                                    |\n";
            std::cout << "--------------------------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << std::setw(18) << "Средний балл    |\n";
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
            std::cout << "Введите имя ученика, которого хотите удалить" << std::endl;
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
                    std::cout << "Ученик удален" << std::endl;
                    break;
                }
                x++;
            }
            if (flag == 0)
            {
                std::cout << "Такого ученика нет" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 14:
        {
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Должность " << '|' << std::setw(9) << "Стаж работы  |\n";
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
            std::cout << "Введите имя учителя, которого хотите удалить" << std::endl;
            std::getline(std::cin, name_poi);
            int x = 0;
            int flag = 0;
            for (auto& item : teachers)
            {
                if (item->getName() == name_poi)
                {
                    flag = 1;
                    teachers.erase(item);
                    std::cout << "Преподаватель удален" << std::endl;
                    
                    break;
                }
                x++;
            }
            if (flag == 0)
            {
                std::cout << "Такого преподавателя нет" << std::endl;
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
            std::cout << "Введите название теста, который хотите удалить" << std::endl;
            std::getline(std::cin, name_poi);
            int x = 0;
            for (auto& item : tests)
            {
                if (item->get_name() == name_poi)
                {
                    tests.erase(item);
                    std::cout << "Тест удален" << std::endl;
                    x++;
                    break;
                }
            }
            if (x == 0)
            {
                std::cout << "Такого теста нет" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 16:
        {           
            std::cout << "---------------------------------------------------------------------------\n";
            std::cout << "|                             УЧЕНИКИ                                    |\n";
            std::cout << "--------------------------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << std::setw(18) << "Средний балл    |\n";
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
            std::cout << "Введите имя, которое хотите изменить:" << std::endl;
            std::getline(std::cin, name_poi);
            int poi = 0;
            for (auto& item : students)
            {
                pers = item.second;
                if (pers->getName() == name_poi)
                {
                    poi = 1;
                    std::string name_new;
                    std::cout << "Введите новое имя, которое будет у ученика:" << std::endl;
                    std::getline(std::cin, name_new);
                    pers->setName(name_new);
                    std::cout << "Имя изменено" << std::endl;
                    item.second = pers;
                    break;
                }
            }
            if (poi == 0)
            {
                std::cout << "Такого ученика нет" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 17:
        {
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Должность " << '|' << std::setw(9) << "Стаж работы  |\n";
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
            std::cout << "Введите имя, которое хотите изменить:" << std::endl;
            std::getline(std::cin, name_poi);
            int poi = 0;
            for (auto& item : teachers)
            {
                if (item->getName() == name_poi)
                {
                    std::string name_new;
                    poi = 1;
                    std::cout << "Введите новое имя, которое будет у преподавателя:" << std::endl;
                    std::getline(std::cin, name_new);
                    item->setName(name_new);
                    std::cout << "Имя изменено" << std::endl;
                    break;
                }
            }
            if (poi == 0)
            {
                std::cout << "Такого преподавателя нет" << std::endl;
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
            std::cout << "Введите название, которое хотите изменить:" << std::endl;
            std::getline(std::cin, name_poi);
            int poi = 0;
            for (auto& item : tests)
            {
                if (item->get_name() == name_poi)
                {
                    std::string name_new;
                    poi = 1;
                    std::cout << "Введите новое название, которое будет у теста:" << std::endl;
                    std::getline(std::cin, name_new);
                    item->setName(name_new);
                    std::cout << "Имя изменено" << std::endl;
                    break;
                }
            }
            if (poi == 0)
            {
                std::cout << "Такого теста нет" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 19:
            break;
        default:
            std::cout << "Неверный ввод" << std::endl;
        }
    } while (choice != 19);

    std::ofstream File;
    File.open(name_fil, std::ios::binary);
    if (File.is_open())
    {
        File<< "---------------------------------------------------------------------------\n";
        File << "|                             УЧЕНИКИ                                    |\n";
        File << "--------------------------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << std::setw(18) << "Средний балл    |\n";
        File << "---------------------------------------------------------------------------\n";
        for (auto& item : students)
        {
            pers = item.second;
            File << '|' << std::setw(20) << std::left << pers->getName() << '|' << std::setw(20)
                << pers->getAge() << '|' << std::setw(12) << pers->getYear() << " |" << std::setw(16) << item.first << "|" << std::endl;
            File << "---------------------------------------------------------------------------\n";
        }
        File <<  "---------------------------------------------------------\n";
        File << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
        File << "---------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(9) << "Стаж работы  |\n";
        File << "---------------------------------------------------------\n";
        for (auto& item : teachers)
        {
            File << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                << item->getAge() << '|' << std::setw(4) << item->getWork() << "         |" << std::endl;
            File << "---------------------------------------------------------\n";
        }
        std::cout << "Данные успешно записаны в файл\n";
    }
    else std::cout << "Ошибка открытия файла\n";
    File.close();

    std::ofstream File1;
    File1.open(name_fik_test, std::ios::binary);
    if (File1.is_open())
    {
        for (auto& item : tests)
        {
            File1 <<"Название теста:  "<< item->get_name();
            File1 << "\n";
            File1 << "Вопросы:\n";
            for (int j = 0; j < item->get_col_que(); j++)
            {
                File1 << item->get_quest(j);
                File1 << "\n";
            }
            File1 << "\n\n";
        }
    }
    else std::cout << "Ошибка открытия файла\n";
    File1.close();
    return 0;
}