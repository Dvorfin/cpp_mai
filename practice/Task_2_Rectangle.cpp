#include <iostream>

using namespace std;

int main()
{
    int high, width;
    
    cout << "Enter high: ";
    cin >> high;
    
    cout << "Enter width: ";
    cin >> width;

    for (int i = 0; i < high; i++) {
        for (int j = 0; j < width; j++) {
            cout << "*";
        }
        
        cout << endl;
        
    }

    return 0;
}
