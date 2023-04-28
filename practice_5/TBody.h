//
// Created by User on 24.04.2023.
//
//31, Створити клас TBody, який представляє просторову геометричну фігуру з ме-
//тодами обчислення площі її поверхні та об'єму. На основі цього класу створити
//класи-нащадки TParallelepiped та TBall. Створити певну кількість паралелепіпедів
//та куль, щоб їх сумарна кількість дорівнювала n. Для куль знайти сумарний об'єм,
//а для паралелепіпедів - суму площ поверхні.
#ifndef PRACTICE_5_TBODY_H
#define PRACTICE_5_TBODY_H
#include <cmath>
class TBody{
public:
    string name = "фігура";
    virtual double calc_surface_area() = 0;
    virtual double calc_volume() = 0;
    double getSurface_area(){
        return surface_area;
    };
    double getVolume(){
        return volume;
    };
protected:
    double surface_area;
    double volume;

};
class TParallelepiped : public TBody {
public:
    TParallelepiped(double a, double b, double c) : h(a), w(b), l(c) {
        name = "Паралелепіпед";
    }
    TParallelepiped(){}
    double calc_surface_area() {
        surface_area = 2 * (h*w + h * l + w * l);
    }
    double calc_volume() {
        volume = h * l * w;
    }
    double getH(){
        return h;
    }
    double getW(){
        return w;
    }
    double getL(){
        return l;
    }
private:
    double h, w, l;
};

class TBall : public TBody {
public:
    TBall(double r) : m_r(r) {
        name = "Куля";
    }
    TBall(){}
    double calc_surface_area() {
        surface_area = 4 * M_PI * pow(m_r, 2);
    }
    double calc_volume() {
        volume = (4.0 / 3.0) * M_PI * pow(m_r, 3);
    }
    double getRadius(){
        return m_r;
    }
private:
    double m_r;
};





#endif //PRACTICE_5_TBODY_H
