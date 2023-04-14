using namespace std;
#include <iostream>
#include <limits>
#include "set.h"
#include "checking/inputCheck.h"
//31. Розробити клас ««Мультимножина» для представлення множини символів.
//Реалізувати для нього декілька конструкторів, геттери, метод визначення прина-
//лежності заданого елемента множині. Перевантажити оператори "+", "*" та "-"
//для знаходження об'єднання, перетину і різниці множин відповідно. Створити три
//множини (А, В, С), використовуючи різні конструктори. На їх основі побудувати
//множину Р-(АЧВУ СПВ.

void chooseSet(int arrLength, int* pt, string text , string errMsg){
    bool trigger;
    do{
        trigger = true;
        cout<<text<<endl;
        cin>>*pt;
        if(*pt<=0 || *pt>arrLength){
            cout<<errMsg<<endl;
            trigger= false;
        }
    } while (!trigger);
}


void app(){
    int option;
    int boolean;
    int arrLength = 2;
    Set* arr = new Set[arrLength];
    char* arr0 = new char[6];
    arr0[0] = 's';
    arr0[1] = '5';
    arr0[2] = 'h';
    arr0[3] = 'm';
    arr0[4] = '0';
    arr0[5] = '\0';
    char* arr1 = new char[6];
    arr1[0] = 's';
    arr1[1] = '5';
    arr1[2] = 'h';
    arr1[3] = 'm';
    arr1[4] = 'x';
    arr1[5] = '\0';
//    char* arr1 = new char[7];
//    arr1[0] = 'h';
//    arr1[1] = '2';
//    arr1[2] = '8';
//    arr1[3] = 's';
//    arr1[4] = 'm';
//    arr1[5] = 'r';
//    arr1[6] = '\0';
    arr[0] = Set(5, arr0);
    arr[1] = Set(5, arr1);
    printf("1 - create set\n");
    printf("2 - read all sets\n");
    printf("3 - set addition\n");
    printf("4 - set intersection\n");
    printf("5 - set deduction\n");
    printf("6 - finish program\n");
    do {
        printf("Choose option(from the menu above): \n");
        do {
            fflush(stdin);
            boolean = intInput(&option);
            if (!boolean) {
                printf("you have entered a symbol, try again\n");
            } else if (option < 1 || option > 6) {//9
                boolean = 0;
                printf("there is no such option, try again\n");
            }
        } while (!boolean);
        switch (option) {
            case 1: {
                int length;
                int boolean;
                do {
                    fflush(stdin);
                    cout << "Enter the number of elements: " << endl;
                    boolean = intInput(&length);
                    if (!boolean) {
                        printf("you have entered a symbol, try again\n");
                    }
                } while (!boolean);
                char *elements = new char [length+1];
                for(int i = 0; i < length; i++){
                    cout<<"Enter the "<<i+1<<"-th element"<<endl;
                    cin>>elements[i];
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                elements[length] = '\0';
                Set object(length, elements);
                object.showSet();
                Set* newArray = new Set[arrLength+1];
                for (int i = 0; i < arrLength; i++) {
                    newArray[i] = arr[i];
                }
                newArray[arrLength] = object;
                arrLength++;
                delete[] arr;
                arr = newArray;
                break;
            }

            case 2: {
                for(int i = 0; i<arrLength; i++){
                    arr[i].showSet();
                }
                break;
            }
            case 3: {
                int idx0, idx1;
                if(arrLength>=2){
                    chooseSet(arrLength, &idx0, "The first one:", "The set is out of bounds");
                    chooseSet(arrLength, &idx1, "The second one:", "The set is out of bounds");
                    Set object = arr[idx0-1]+arr[idx1-1];
                    object.showSet();
                    Set* newArray = new Set[arrLength+1];
                    for (int i = 0; i < arrLength; i++) {
                        newArray[i] = arr[i];
                    }
                    newArray[arrLength] = object;
                    arrLength++;
                    delete[] arr;
                    arr = newArray;
                    cout<<"Written to the end of list as the "<<object.getNum()<<"-th"<<endl;
                }else {
                    cout<<"Less than 2 sets, can't combine"<<endl;
                }
                break;
            }
            case 4: {
                int idx0, idx1;
                if(arrLength>=2){
                    cout<<"What two sets you want to intersect?"<<endl;
                    chooseSet(arrLength, &idx0, "The first one:", "The set is out of bounds");
                    chooseSet(arrLength, &idx1, "The second one:", "The set is out of bounds");
                    Set object = arr[idx0-1]*arr[idx1-1];
                    if(object.getSymbols()[0] != '\0'){
                        object.showSet();
                        Set* newArray = new Set[arrLength+1];
                        for (int i = 0; i < arrLength; i++) {
                            newArray[i] = arr[i];
                        }
                        newArray[arrLength] = object;
                        arrLength++;
                        delete[] arr;
                        arr = newArray;
                        cout<<"Written to the end of list as the "<<object.getNum()<<"-th"<<endl;
                    }
                }else {
                    cout<<"Less than 2 sets, can't combine"<<endl;
                }
                break;
            }
            case 5: {
                int idx0, idx1;
                if(arrLength>=2){
                    cout<<"What two sets you want to deduct?"<<endl;
                    chooseSet(arrLength, &idx0, "The first one(the one u deduct from):", "The set is out of bounds");
                    chooseSet(arrLength, &idx1, "The second one:", "The set is out of bounds");
                    Set object = arr[idx0-1]-arr[idx1-1];
                    if(object.getSymbols()[0] != '\0'){
                        object.showSet();
                        Set* newArray = new Set[arrLength+1];
                        for (int i = 0; i < arrLength; i++) {
                            newArray[i] = arr[i];
                        }
                        newArray[arrLength] = object;
                        arrLength++;
                        delete[] arr;
                        arr = newArray;
                        cout<<"Written to the end of list as the "<<object.getNum()<<"-th"<<endl;
                    }
                }else {
                    cout<<"Less than 2 sets, can't combine"<<endl;
                }
                break;
            }
            case 6: {
                delete[] arr;
                boolean = 0;
                break;
            }
            default: {
                cout << "Invalid option." << endl;
                break;
            }
        }

    } while (boolean == 1);
}

int main() {
    app();
    return 0;
}
