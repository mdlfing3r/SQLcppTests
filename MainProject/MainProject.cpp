// MainProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "source/inc/sqlite3.h"
#include <fstream>
#include <strstream>

enum sex_t {
    male,
    female
};

enum nationality_t {
      Uzbek
    , Russian
    , English
    , American
    , Belarusian
    , Kazakh
    , Chinese
    , Finnish
    , Czech
};
typedef struct {
    const char* name;
    uint8_t age;
    sex_t sex;
    uint8_t weight;
    nationality_t nation;
} person_t;

int main()
{
    const char *DBname = "persons.db";
    sqlite3* db;    // указатель на базу данных
    std::cout << "Prepapare to database execution...\n";

    std::ifstream ifstr(DBname);
    
    if (!ifstr) {
        std::cout << "WARNING: file with name: " << DBname << " is not exist\n";
        return 1;
    }
    // открываем подключение к базе данных
    if (!sqlite3_open(DBname, &db)) {
        std::cout << "can`t open required database\n";
        return 2;
    }
    std::string 
          req = "SELECT * FROM PERSONS;"
        , resp
        , buff;
#if 0
    while (true) {
        std::cout << "Enter the sql request\n";
        while (resp.empty()) {
            std::cin >> buff;
            //SQLexec(buff);
            resp += buff;
        }
        std::cout << resp << "\n";
        resp.clear();
        buff.clear();
    }
#endif

    sqlite3_close(db);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
