#pragma once
//31. ��������� ���� ����, ���������� ����� � ����, ����� � ��, � ����� �� ������
//- �������, ��� ������� �� ����� ���� �����.�������� ��� ��'����-���� � �����-
//����, �� ���������� ���� ������ � ���� � ��� �����, � ������� ������� ����-
//�������� ��� ��� �����, ����������� ������� �������� �������� �� ����������� :
// �� �������.



#include <iostream>
#include <stdexcept>




bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;  // г�, ���� ������� �� 400 ��� �������
            }
            return false;  // г�, ���� ������� �� 100 ��� �������, ��� �� ������� �� 400
        }
        return true;  // г�, ���� ������� �� 4 ��� �������, ��� �� ������� �� 100
    }
    return false;  // г�, ���� �� ������� �� 4 ��� �������
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
            throw gcnew System::ArgumentOutOfRangeException("��� ����� �� 31 ���� � �� �����");
        }
        else if (isLeapYear(y) && m == 2 && d > 29) {
            throw gcnew System::ArgumentOutOfRangeException("� ������ " + y.ToString() + " ���� ����� 29 ��� � �� �����");
        }
        else if (!isLeapYear(y) && m == 2 && d > 28) {
            throw gcnew System::ArgumentOutOfRangeException("� ������ " + y.ToString() + " ���� ����� 28 ��� � �� �����");
        }
        else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
            throw gcnew System::ArgumentOutOfRangeException("��� ����� �� 30 ��� � �� �����");
        }
        else if (m < 1 || m>12) {
            throw gcnew System::ArgumentOutOfRangeException("̳����� ���� 12");
        }
    }
    Date(){}
    void display() {
        System::Console::WriteLine("����: {0}.{1}.{2}", day, month, year);
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
            return 6;  // ������
        else if (h == 1) {
            return 7;
        }
        else
            return h - 1;  // �������� - �'������
    }
};
