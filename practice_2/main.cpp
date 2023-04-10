#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <limits>
#include <regex>
#include "helpers/createFile.h"
#include "checking/inputCheck.h"
#include "helpers/deleteFile.h"
//Вимоги до програми
//
//        Використання власних бібліотек (модульний підхід).
//Реалізація роботи з файлами з використанням файлових потоків.
//Можливість доповнення файлу даних.
//
//Інформативний інтерфейс для демонстрації завдання, який обов'язково пови-
//нен містити виведення усіх вхідних, проміжних і вихідних даних.


//31. Створити файл із розкладом руху приміських поїздів декількома напрямками
//(по кожному напрямку по 3-5 рейсів протягом дня): номер рейсу, напрямок руху,
//в час відправлення, час прибуття в кінцевий пункт. Зі складеного розкладу сфор-
//мувати зимовий розклад (новий файл), в якому мають бути лише ранкові (до
//10:00) та вечірні (після 18:00) рейси.

//Напрямок: Київ - Ірпінь
//

//        Рейс № 101: Київ - Ірпінь, відправлення о 6:00, прибуття о 6:40.
//Рейс № 103: Київ - Ірпінь, відправлення о 9:15, прибуття о 9:55.
//Рейс № 105: Київ - Ірпінь, відправлення о 13:30, прибуття о 14:10.
//Рейс № 107: Київ - Ірпінь, відправлення о 17:45, прибуття о 18:25.
//Рейс № 109: Київ - Ірпінь, відправлення о 21:00, прибуття о 21:40.
//Напрямок: Київ - Васильків
//
//        Рейс № 201: Київ - Васильків, відправлення о 7:00, прибуття о 8:15.
//Рейс № 203: , відправлення о 10:30, прибуття о 11:45.
//Рейс № 205: Київ - Васильків, відправлення о 14:00, прибуття о 15:15.
//Рейс № 207: Київ - Васильків, відправлення о 17:30, прибуття о 18:45.
//Рейс № 209: Київ - Васильків, відправлення о 20:00, прибуття о 21:15.
//Напрямок: Київ - Біла Церква
//
//Рейс № 301: Київ - Біла Церква, відправлення о 6:30, прибуття о 7:30.
//Рейс № 303: Київ - Біла Церква, відправлення о 9:45, прибуття о 10:45.
//Рейс № 305: Київ - Біла Церква, відправлення о 12:15, прибуття о 13:15.
//Рейс № 307: Київ - Біла Церква, відправлення о 15:30, прибуття о 16:30.
//Рейс № 309: Київ - Біла Церква, відправлення о 19:00, прибуття о 20:00.

class race {
public:
    int num;
    string direction;
    int depHour;
    int depMin;
    int arrHour;
    int arrMin;

    void save(ofstream& out) const {
        out.write(reinterpret_cast<const char*>(&num), sizeof(num));
        int len = direction.length();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(direction.c_str(), len);
        out.write(reinterpret_cast<const char*>(&depHour), sizeof(depHour));
        out.write(reinterpret_cast<const char*>(&depMin), sizeof(depMin));
        out.write(reinterpret_cast<const char*>(&arrHour), sizeof(arrHour));
        out.write(reinterpret_cast<const char*>(&arrMin), sizeof(arrMin));
    }

    bool load(ifstream& in) {
        in.read(reinterpret_cast<char*>(&num), sizeof(num));
        int len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        // Read the string from the file
        char buffer[len+1];
        in.read(buffer,len);
        buffer[len] = '\0';
        direction = buffer;
        in.read(reinterpret_cast<char*>(&depHour), sizeof(depHour));
        in.read(reinterpret_cast<char*>(&depMin), sizeof(depMin));
        in.read(reinterpret_cast<char*>(&arrHour), sizeof(arrHour));
        in.read(reinterpret_cast<char*>(&arrMin), sizeof(arrMin));
        return in.good();
    }

    race() : num(0), direction(""), depHour(0), depMin(0), arrHour(0), arrMin(0) {}

    race(int num, string direction, int depHour, int depMin, int arrHour, int arrMin)
            : num(num), direction(direction), depHour(depHour), depMin(depMin), arrHour(arrHour), arrMin(arrMin) {}

    void outputInfo() const {
        cout << "Рейс № " << num << ": " << direction << " відправлення о " << depHour << ":" << depMin << ", прибуття о " << arrHour << ":" << arrMin << "." << endl;
    }
};


void validateInt(int* address, string msg) {
//    bool validInput = false;
//    do {
//        cout << msg << endl;
    cin >> *address;
//        if (cin.fail()) {
//            cin.clear(); // Clear the error flag
////            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
//            cout << "Invalid input, please try again." << endl;
//        } else {
//            validInput = true;
//        }
//    } while (!validInput);
//    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
}
void validateStringLine(string* address, string msg) {
    cout << msg << endl;
    getline(cin, *address);
}

void appendRecord(const string& filename, race &recordToAppend) {
    // Open the file in append mode
    ofstream outFile(filename, ios::app | ios::binary);

    // Check if the file was successfully opened
    if (!outFile) {
        cerr << "Error: Failed to open file \"" << filename << "\" for appending." << endl;
        return;
    }
    // Write the record to the end of the file
    recordToAppend.save(outFile);
//    outFile.write(reinterpret_cast<const char*>(&recordToAppend),sizeof (race));
    // Close the file
    outFile.close();
}
race createRecord(){
    race record;
    cout<<"Введіть номер рейсу"<<endl;
    cin>>record.num;
    cout << "Введіть назву рейсу(напрямок)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, record.direction);
    cout<<"Введіть годину відправлення"<<endl;
    cin>>record.depHour;
    cout<<"Введіть хвилину відправлення"<<endl;
    cin>>record.depMin;
    cout<<"Введіть годину прибуття"<<endl;
    cin>>record.arrHour;
    cout<<"Введіть хвилину прибуття"<<endl;
    cin>>record.arrMin;
//    record.outputInfo();
    return record;
    // Write the record to the end of the file
}
void sortRecords(const std::string& filename) {
    ofstream outFile("newFile.txt",  ios::binary);
    // Open the file in binary mode
    ifstream inFile(filename, ios::binary);
    bool val = false;
    // Check if the file was successfully opened
    if (!inFile && !outFile) {
        cerr << "Error: Failed to open file \"" << filename << "\" for reading." << endl;
        return;
    }

    // Read the records from the file
    race record;
    while (record.load(inFile)) {
        if(record.depHour<10 || record.depHour>18){
//            records.push_back(record);
            val = true;
            record.outputInfo();
            record.save(outFile);
        }
    }
    if(val){
        cout<<"The morning and evening races have been written to the file(newFile.txt)"<<endl;
    }
    // Close the file
    inFile.close();
    outFile.close();
}

void readRecords(string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file or the file doesn't exist" << endl;
        return ;
    }
    race record;
    while (record.load(inFile)) {
        record.outputInfo();
    }

    inFile.close();
}
void fileNameFuncStream(string& fileName){
    printf("Enter file name: ");
    cin>>fileName;
}
void app(bool val, string fileName){
    int option;
    int boolean;
    int trigger = 1;//0
    if(val){
        trigger=1;
    }
    printf("Menu: \nFile mode:        Records mode: \n");
    printf("0 - create file   2 - append record: \n");
    printf("1 - read file     3 - delete file\n");
    printf("4 - sort morning and evening races\n");
    printf("5 - open file written by this app\n");
    printf("6 - finish program\n");
    do {
        printf("Choose option(from the menu above): \n");
        do {
            fflush(stdin);
            boolean = intInput(&option);
            if (!boolean) {
                printf("you have entered a symbol, try again\n");
            } else if (option < 0 || option > 6) {//9
                boolean = 0;
                printf("there is no such option, try again\n");
            }
        } while (!boolean);
        switch (option) {
            case 0:
                fileNameFuncStream(fileName);
                createFileStream(fileName, &trigger);
                break;
            case 1:
                if (trigger) {
                    readRecords(fileName);
                } else {
                    cout<<"Currently there is no opened file\n";
                }
                break;
            case 2:
                if (trigger) {
                    race record = createRecord();
                    appendRecord(fileName,record);
                } else {
                    cout<<"Currently there is no opened file\n";
                }
                break;
            case 3:
                if (trigger) {
                    deleteFile(fileName, &trigger);
                } else {
                    cout<<"Currently there is no opened file\n";
                }
                break;
            case 4:
                if (trigger) {
                    sortRecords(fileName);
                } else {
                    cout<<"Currently there is no opened file\n";
                }
                break;
            case 5:
                if (trigger) {
                    string fileName;
                    cout<<"Enter filename:"<<endl;
                    cin>>fileName;
                    readRecords(fileName);
                } else {
                    cout<<"Currently there is no opened file\n";
                }
                break;
            case 6:
                boolean = 0;
                break;

        }
    } while (boolean == 1);
}

int main(int argc, char* argv[]) {
//    string fileName = "races.txt";
//    race race3(101, "car", 6,7, 8,40);
//    race race2(104, "Київ ", 6,7, 8,40);
//    appendRecord(fileName, race3);
//    readRecords(fileName);
//createRecord();

//    readRecords("filename.txt");
    if(argc==2){
        ifstream infile(argv[1]);
        if(infile.good()){
            cout<<"-appending to existing file("<<argv[1]<<")"<<endl;
            app(true,argv[1]);
        }else {
            cout<<"the file entered as command prompt arg doesn't exist"<<endl;
            app(false,"");
        }
    } else if(argc==1){
        app(false,"");
    }
    return 0;
}