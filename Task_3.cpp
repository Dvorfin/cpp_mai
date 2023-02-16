#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    
    float Max_High, Current_High, Current_V, Zero_V, delay, duration, Local_Time, Global_Time, maxV, g = 9.8;
    
    bool Up_Down = 1;
    
    cout << "Enter high: ";
    cin >> Max_High;
    
    cout << "Enter delay: ";
    cin >> delay;
    
    cout << "Enter duration: ";
    cin >> duration;

    Current_High = Max_High;
    
    while (Global_Time < duration) {  // условие прекарщения работы
        
        if (Up_Down == 1) {  // опреденяем движение вверх или вниз
            
            cout << endl << "DOWN" << endl << endl;
        
            while (Current_High > 0.1) {  // пока скорость больше минимума
            
                Local_Time = Local_Time + 0.001;   // вычисляем значения высоты и скорсоти
                Current_High = Max_High - g*pow(Local_Time,2)/2;
                Current_V = g*Local_Time;
            
                if ((fmod(Local_Time, delay) <= 0.001) && (Current_High > 0)) {  // если прошел период задержки, то выводим значения
                //    cout << "High: " << Current_High << "    " << "Velocity: " << Current_V << endl;
                    cout << "High: ";
                    printf("%7.3f", Current_High);
                    cout << "  |  Velocity: ";
                    printf("%7.3f", Current_V);
                    cout << "  |  Time of movement: " << Local_Time << endl;
                }
            }
        
        Up_Down = 0;  // пересчитываем значения для движения вверх
        Zero_V = sqrt(0.7*2*g*Max_High);
        Global_Time = Global_Time + Local_Time;
        Local_Time = 0;
        
        }
        
        
        if (Up_Down == 0) {
            
            cout << endl << "UP" << endl << endl;
            
            while (Current_V > 0.1) {         // то же, чтои для движения вниз, но немного другие формулы
                
                Local_Time = Local_Time + 0.001;
                Current_High = Zero_V*Local_Time - g*pow(Local_Time,2)/2;
                Current_V = Zero_V - g*Local_Time;
                
                if ((fmod(Local_Time, delay) <= 0.001) && (Current_V > 0)) {
                 //   cout << "High: " << Current_High << "    " << "Velocity: " << -Current_V << endl;
                    cout << "High: ";
                    printf("%7.3f", Current_High);
                    cout << "  |  Velocity: ";
                    printf("%7.3f", -Current_V);
                    cout << "  |  Time of movement: " << Local_Time << endl;
                }
            }
            
        Up_Down = 1; // пересчитываем значения для движения вниз
        Max_High = Zero_V*Local_Time - g*pow(Local_Time,2)/2;
        Global_Time = Global_Time + Local_Time;
        Local_Time = 0;
            
        }
        
    }

    cout << "Time: " << Global_Time;

    return 0;
}
