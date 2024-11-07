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

int callback(void* notUsed, int colCount, char** columns, char** colNames);


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
    int rc = sqlite3_open(DBname, &db);
    if (rc != SQLITE_OK) {
        std::cout << "can`t open required database\n";
        return 2;
    }
    char* err_msg = 0;
    std::string Shapka =
        " ________________________________________________________\n| ID  |  Name   |   Sex   | Age | Weight |  Nationality  |\n_________________________________________________________\n";
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

    int sqlite3_exec(
        sqlite3*,                                  /* подключение к бд */
        const char* sql,                           /* код инструкций SQL */
        int (*callback)(void*, int, char**, char**),  /* функция обратного вызова */
        void*,                                    /* аргумент для функции обратного вызова */
        char** errmsg                              /* сообщение об ошибке */
    );
#endif
    std::cout << Shapka;

    sqlite3_exec(db, req.c_str(), callback, 0, &err_msg);
 
    sqlite3_close(db);
}

int callback(void* notUsed, int colCount, char** columns, char** colNames)
{
    //for (int i = 0; i < colCount; i++)
    //{
        //printf("%s = %s\n", colNames[i], columns[i] ? columns[i] : "NULL");
        std::string ouput = 
         "|  " + std::string(columns[0]) + "  | " + std::string(columns[1]) + " | " + std::string(columns[2]) + "  | " + std::string(columns[3]) + "  |  " + std::string(columns[4]) + "    |    "+ std::string(columns[5]) + "   | \n" +
          "_________________________________________________________\n";

        std::cout << ouput;
    //}
    printf("\n");
    return 0;
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
