#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<regex> 
using namespace std;

class Train {
private:
    struct trainInfo {
        char flightNum[5];
        string destination;
        string time;
        int seatsAmount;
    } train[50];

public:
    void inputData() {
        ofstream TI;
        TI.open("info.txt", fstream::app);

        if (TI.is_open()) {
            system("cls");
            cout << "Файл открыт." << endl << endl;
            cout << "Введите количество рейсов: ";
            int amountOfFlights = 0;
            cin >> amountOfFlights;

            for (int i = 0; i < amountOfFlights; i++) {
                system("cls");
                cout << "Введите рейс номер " << i + 1 << endl;
                cout << "Введите номер поезда (5 цифр): ";
                cin >> train[i].flightNum;
                TI << "Номер рейса: " << train[i].flightNum << " - ";

                cout << "Введите пункт назначения поезда: ";
                cin >> train[i].destination;
                TI << "Пункт назначения: " << train[i].destination << " - ";

                cout << "Введите время отправления: ";
                cin >> train[i].time;
                TI << "Время отправки: " << train[i].time << " - ";

                cout << "Введите количество свободных мест в поезде: ";
                cin >> train[i].seatsAmount;
                TI << "Количество свободных мест: " << train[i].seatsAmount << endl;

                cout << "Рейс добавлен!" << endl;

                TI.close();
            }
        }
        else {
            cout << "Ошибка при открытии файла." << endl;
        }
    }

    void searchFlight() {
        string town;
        regex availableSeats("Количество свободных мест: 0");
        cout << "Введите город в который хотите поехать: ";
        cin >> town;
        regex searchTown(town);

        ifstream TI;
        TI.open("info.txt");
        if (TI.is_open()) {
            string str;
            while (!TI.eof()) {
                string str = "";
                getline(TI, str);
                if (regex_search(str, searchTown) && !regex_search(str, availableSeats)) {
                    cout << str << endl;
                }

            }

        }
        else {
            cout << "Ошибка при открытии файла." << endl;
        }
        
    }
};



int main()
{
    bool appendFlights;
    cout << "Вы хотите добавить новые рейсы? (1 - да, 0 - нет): ";
    cin >> appendFlights;
    Train first;
    if (appendFlights) {
        first.inputData();
    }
    first.searchFlight();
}


