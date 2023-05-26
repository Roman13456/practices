#include <iostream>
using namespace std;
//31. Спроектувати АТД "Асоціативний масив на базі hash-таблиці"
//що містить дані довільного типу. Інтерфейс АТД включає такі операції:
//
//-- визначення розміру масиву,
//- пошук пари з максимальним значенням ключа,
//
//- додавання пари,
//
//- очищення масиву,
//
//ітератор для доступу до елементів масиву з операціями:
//
//1) встановлення на початок масиву,
//2) перевірка кінця масиву,
//
//3) доступ до значення поточного елемента масиву,
//4) перехід до наступного елемента масиву.

#include "checking/inputCheck.h"
#include "AssociativeArray.h"
void app(){
    int option;
    int boolean;
    int arrLength;
//    int arrLen;
    cout<<"Введіть розмір ассоціативного масиву:"<<endl;
    cin>>arrLength;
//    arrLength+=arrLen;
    AssociativeArray<int, std::string> array(arrLength);
    AssociativeArray<int, std::string>::Iterator iterator = array.begin();
//    array.addPair(1, "One");
//    array.addPair(5, "Five");
//    array.addPair(3, "Three");
//    array.addPair(7, "Seven");
    printf("1 - add pair instance\n");
    printf("2 - find the biggest key value\n");
    printf("3 - clear the Associative Array\n");
    printf("4 - set the iterator to the start of the array\n");
    printf("5 - check if the end of the array is reached\n");
    printf("6 - read current element\n");
    printf("7 - go to the next element\n");
    printf("8 - finish program\n");
    do {
        printf("Choose option(from the menu above): \n");
        do {
            fflush(stdin);
            boolean = intInput(&option);
            if (!boolean) {
                printf("you have entered a symbol, try again\n");
            } else if (option < 1 || option > 8) {//9
                boolean = 0;
                printf("there is no such option, try again\n");
            }
        } while (!boolean);
        switch (option) {
            case 1: {
                int key;
                string value;
                cout<<"Enter the key"<<endl;
                cin>>key;
                cin.ignore();
                cout<<"Enter the value"<<endl;
                getline(cin, value);
                array.addPair(key, value);
                break;
            }
            case 2: {
                Pair<int, std::string> maxPair = array.findMaxPair();
                cout << "Max Pair: Key = " << maxPair.key << ", Value = " << maxPair.value << endl;
                break;
            }
            case 3: {
                array.clear();
                break;
            }
            case 4: {
                iterator = array.begin();
                break;
            }
            case 5: {
                if(iterator.atEnd()){
                    cout<<"The end of the array is reached"<<endl;
                } else{
                    cout<<"The end of the array isn't reached"<<endl;
                }

                break;
            }
            case 6: {
                Node<int , std::string>* x = iterator.getValue();
                if (x != nullptr) {
                    cout << "Current Pair: key = " << x->key << ", Value = " << x->value << endl;
                } else {
                    cout << "Iterator is pointing to nullptr" << endl;
                }
                break;
            }
            case 7: {
                if(iterator.atEnd()){
                    cout<<"The end of the array is reached"<<endl;
                } else {
                    iterator.next();
                    Node<int, std::string> *x = iterator.getValue();
                    if (x != nullptr) {
                        cout << "Current Pair: key = " << x->key << ", Value = " << x->value << endl;
                    } else {
                        cout << "Iterator is pointing to nullptr" << endl;
                    }
                }
                break;
            }
            case 8: {
                boolean = 0;
                break;
            }
        }

    } while (boolean == 1);
}


int main() {

    app();
    return 0;
}

