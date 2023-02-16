#include <iostream>

using namespace std;

int main()
{
    int variants, num, method;
    char name, surname;
    
    cout << "Enter method 1, 2 or 3: ";  // выбираем вариант расчета варианта
    cin >> method;
    
    switch (method) {
        
        case (1):
        
            cout << "Enter variants: ";
            cin >> variants;
    
            cout << "Enter number of student: ";
            cin >> num;
    
            num = num%variants+1;
    
            cout << "Variant: " << num;
            
            break;
            
        case (2):
            
            cout << "Enter variants: ";
            cin >> variants;
            
            cout << "Enter name: ";
            cin >> name;
            
            cout << "Varian: " << name%variants+1;
        
        break;

        case (3):
        
            cout << "Enter variants: ";
            cin >> variants;
        
            cout << "Enter surname: ";
            cin >> surname;
            
            cout << "Varian: " << surname%variants+1;
        
        break;
        
        default:
            
            cout << "Incorrect";
            
        break;

    }

    return 0;
}
