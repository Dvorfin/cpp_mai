#include <iostream>

using namespace std;

int main()
{
    int size, space, star;
    
    cout << "Enter size of triangle: ";
    cin >> size;

    if (size % 2 == 0) {  // если размер треугольника четный
        
        star = 2;
        space = size/2-1;
        
        for (int i = 0; i < size; i++) {  // идем по строкам 
            if (i % 2 == 0) {     // если четная, то пропускаем
                cout << endl;
            } else {
                for (int j = 0; j < space; j++) {  // иначе выводим пробелы
                    cout << " ";
                }
                
                space--;
                
                for (int j = 0; j < star; j++) { // и выводим звезды
                    cout << "*";
                }
                
                star = star+2;
                
            }
       
        }
        
    }
    
    
    if (size %2 != 0) {
        
        star = 1;
        space = size/2;
        
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < space; j++) {
                    cout << " ";
                }
                
                space--;
                
                for (int j = 0; j < star; j++) {
                    cout << "*";
                }
                
                star = star + 2;
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
