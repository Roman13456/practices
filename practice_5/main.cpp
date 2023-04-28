#include <iostream>
using namespace std;
#include "checking/inputCheck.h"
#include "TBody.h"

//31, Створити клас TBody, який представляє просторову геометричну фігуру з ме-
//тодами обчислення площі її поверхні та об'єму. На основі цього класу створити
//класи-нащадки TParallelepiped та TBall. Створити певну кількість паралелепіпедів
//та куль, щоб їх сумарна кількість дорівнювала n. Для куль знайти сумарний об'єм,
//а для паралелепіпедів - суму площ поверхні.
void app(){
    int option;
    int boolean;
    int arrLength = 2;
    int arrLength1 = 3;
    TBall* arr = new TBall[arrLength];
    TBall sphere0(5);
    sphere0.calc_surface_area();
    sphere0.calc_volume();
    TBall sphere1(10);
    sphere1.calc_surface_area();
    sphere1.calc_volume();
    TParallelepiped square0(5, 4, 7);
    square0.calc_surface_area();
    square0.calc_volume();
    TParallelepiped square1(6, 8, 9);
    square1.calc_surface_area();
    square1.calc_volume();
    TParallelepiped square2(10, 14, 17);
    square2.calc_surface_area();
    square2.calc_volume();
    arr[0] = sphere0;
    arr[1] = sphere1;

    TParallelepiped* arr1 = new TParallelepiped[arrLength1];
    arr1[0] = square0;
    arr1[1] = square1;
    arr1[2] = square2;
    printf("1 - create TBall instance\n");
    printf("2 - create TParallelepiped instance\n");
    printf("3 - calculate summary volume of all TBall instances\n");
    printf("4 - calculate summary surface area of all TParallelepiped instances\n");
    printf("5 - show all objects\n");
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
                double r;
                cout<<"Enter the radius"<<endl;
                cin>>r;
                TBall object(r);
                object.calc_volume();
                object.calc_surface_area();
                TBall* newArray = new TBall[arrLength+1];
                for (int i = 0; i < arrLength; i++) {
                    newArray[i] = arr[i];
                }
                newArray[arrLength] = object;
                arrLength++;
                delete[] arr;
                arr = newArray;
                cout<<"Written to the end of list"<<endl;
                break;
            }

            case 2: {
                double h,w,l;
                cout<<"Enter the height"<<endl;
                cin>>h;
                cout<<"Enter the width"<<endl;
                cin>>w;
                cout<<"Enter the length"<<endl;
                cin>>l;
                TParallelepiped object(h,w,l);
                object.calc_volume();
                object.calc_surface_area();
                TParallelepiped* newArray = new TParallelepiped[arrLength+1];
                for (int i = 0; i < arrLength1; i++) {
                    newArray[i] = arr1[i];
                }
                newArray[arrLength1] = object;
                arrLength1++;
                delete[] arr1;
                arr1 = newArray;
                cout<<"Written to the end of list"<<endl;
                break;
            }
            case 3: {
                double sum;
                for(int i = 0; i < arrLength; i++){
                    sum+=arr[i].getVolume();
                }
                cout<<"summary volume of all TBall instances is "<<sum<<endl;
                break;
            }
            case 4: {
                double sum;
                for(int i = 0; i < arrLength1; i++){
                    sum+=arr1[i].getSurface_area();
                }
                cout<<"summary surface area of all TParallelepiped instances is "<<sum<<endl;
                break;
            }
            case 5: {
                if(arrLength){
                    cout<<"Spheres:"<<endl;
                    for(int i = 0; i < arrLength; i++){
                        cout<<i+1<<")Surface area is "<<arr[i].getSurface_area()<<endl;
                        cout<<"Volume is "<<arr[i].getVolume()<<endl;
                        cout<<"Radius is "<<arr[i].getRadius()<<endl;
                        cout<<endl;
                    }
                } else{
                    cout<<"No spheres"<<endl;
                }
                if(arrLength1){
                    cout<<"Parallelepipeds:"<<endl;
                    for(int i = 0; i < arrLength1; i++){
                        cout<<i+1<<")Surface area is "<<arr1[i].getSurface_area()<<endl;
                        cout<<"Volume is "<<arr1[i].getVolume()<<endl;
                        cout<<"Height is "<<arr1[i].getH()<<endl;
                        cout<<"Width is "<<arr1[i].getW()<<endl;
                        cout<<"Length is "<<arr1[i].getL()<<endl;
                        cout<<endl;
                    }
                } else{
                    cout<<"No parallelepipeds"<<endl;
                }

                break;
            }
            case 6: {
                delete[] arr;
                delete[] arr1;
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
