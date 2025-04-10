#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <numeric>
#include <functional>
using namespace std;
double X = 0;
void EnterNumberX() {
    double X;
    cout << "Введите натуральное число: ";cin >> X;
    if (X == int(X) && X > 0) {
        cout << "Число " << X << " натуральное!\n";
    }
    else {
        cout << "Число " << X << " не натуральное.\n";
    }
    cout << endl;
}
void EnterCalcNumber() {
    int X, Z;
    cout << "Введите натуральное число: "; cin >> X;
    if (X == int(X) && X > 0) {
        int chislo = 0;
        int count = 0;
        while (X) {
            Z = X % 10;
            if (count == 0)
                chislo = Z;
            count++;
            X /= 10;
        }
        if (chislo == Z) cout << "Начальная и конечная цифры в числе одинаковые" << endl;
        else {
            cout << "Начальная и конечная цифры в числе разные" << endl;
        }
    }
    else {
        cout << "Число " << X << " не натуральное.\n";
    }
}
void EnterNumberKonec() {
}
bool UserInputDbl(string input) {
    //если строка пустая - ввод некорректен
    if (input.empty()) return false;
    //попытаться
    try {
        //преобразование введенного значения в тип double
        double number = stod(input);
        if (number < 0) return false;
    }
    catch (...) //если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}
//вспомогательная функция для ввода целых чисел
function<void()> EnterDouble(double& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);
        while (!UserInputDbl(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stod(raw_input);
        };
}
bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        //преобразование введенного значения в тип int
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) //если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}
//вспомогательная функция для ввода целых чисел
function<void()> EnterNumber(int& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);
        while (!UserInput(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input);
        };
}
function<void()> EnterString(string& varLink, string label) {
    return [&varLink, label]() {
        cout << label << " = ";
        getline(cin, varLink);
        };
}
struct MenuItem {
    string title;             //Название пункта меню
    function<void()> action;  //Действие,выполняемое при выборе пункта
};
int main() {
    //Создание меню с использованием map
    map<int, MenuItem> menu = {
    {1, {"Введите натуральное число X", EnterNumberX}},
    {2, {"Начинается ли оно и заканчивается одной и той же цифрой?", EnterCalcNumber}},
    {3, {"Заканчивается ли оно нечетной цифрой?",EnterNumberKonec }},
};
    int choice = 0;
    // Основной цикл программы
    setlocale(LC_ALL, "RU");
    std::cout << "Меню: " << endl;
    // Вывод всех пунктов меню
    for (const auto& item : menu) {
        cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Выход" << endl; // пункт для выхода из программы

    while (true) {
        // Ввод выбора пользователя
        EnterNumber(choice, "Введите номер пункта: ");
        cin >> choice;
        // Выход из программы, если выбран пункт 0
        if (choice == 0) {
            cout << "2025 FirstName LastName" << endl;
            break;
        }
        cout << endl;
        // Проверка существует ли выбранный пункт меню
        if (menu.find(choice) != menu.end()) {
            menu[choice].action(); // Выполнение действия, связанного с пунктом меню
        }
        else {
            cout << "Некорректный ввод. "; // сообщение об ошибке, если пункт не найден
        }
        cout << endl << endl;
    }
    return 0;
}