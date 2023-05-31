#pragma once
//31. Визначити клас Дата, атрибутами якого є день, місяць і рік, а одним із методів
//- функція, яка повертає за датою день тижня.Створити два об'єкти-дати і визна-
//чити, чи відповідають вони одному і тому ж дню тижня, У випадку задання неко-
//ректного дня або місяця, згенерувати відповідні виняткові ситуації та організувати :
// їх обробку.



#include <iostream>
#include <stdexcept>




bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;  // Рік, який ділиться на 400 без залишку
            }
            return false;  // Рік, який ділиться на 100 без залишку, але не ділиться на 400
        }
        return true;  // Рік, який ділиться на 4 без залишку, але не ділиться на 100
    }
    return false;  // Рік, який не ділиться на 4 без залишку
}

ref class Date {
private:
    int day;
    int month;
    int year;

public:
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 31)) {
            throw gcnew System::ArgumentOutOfRangeException("Цей місяць має 31 день і не більше");
        }
        else if (isLeapYear(y) && m == 2 && d > 29) {
            throw gcnew System::ArgumentOutOfRangeException("В лютому " + y.ToString() + " року тільки 29 днів і не більше");
        }
        else if (!isLeapYear(y) && m == 2 && d > 28) {
            throw gcnew System::ArgumentOutOfRangeException("В лютому " + y.ToString() + " року тільки 28 днів і не більше");
        }
        else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
            throw gcnew System::ArgumentOutOfRangeException("Цей місяць має 30 днів і не більше");
        }
        else if (m < 1 || m>12) {
            throw gcnew System::ArgumentOutOfRangeException("Місяців лише 12");
        }
    }
    Date(){}
    void display() {
        System::Console::WriteLine("Дата: {0}.{1}.{2}", day, month, year);
    }

    int getDayOfWeek() {
        int q = day;
        int m = month;
        int y = year;

        if (m < 3) {
            m += 12;
            y--;
        }

        int h = (q + 13 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        
        if (h == 0)
            return 6;  // Субота
        else if (h == 1) {
            return 7;
        }
        else
            return h - 1;  // Понеділок - п'ятниця
    }
};
