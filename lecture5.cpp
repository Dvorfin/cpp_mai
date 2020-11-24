#include <iostream>

using namespace std;

template <typename Type>

class SmartPoint
{

public:

    SmartPoint()
    {
        cout << "Smart pointer constructor" << endl;
    }

    ~SmartPoint()
    {
        cout << "Smart pointer destructor" << endl;
        delete ptr;
    }

    MakeSmartPtr(Type *outsidePtr)  // передаем указатель 
    {
        ptr = outsidePtr;
    }

    Type GetValue(int i) // получаем данные из массива
    {
        return ptr[i];
    }

    void PutValue(int i, Type data) // помещаем данные в массив 
    {
        ptr[i] = data;
    }

private:

    Type *ptr;

};

SmartPoint<int> pointer;  // создаем объект класса умного указателя типа int

class Image 
{
	int mx;

	int my;

	int counter = 0;
    
public:

	Image(int tmx, int tmy) 
    {       

		pointer.MakeSmartPtr(new int[tmx*tmy]());   // создание динамического массива под размеры пользователя
		cout << "IMAGE CONSTRUCTOR" << endl;
    
    }

    void makeImg()
    {
        for (int i = 0; i < mx*my; i++) 
        {
			pointer.PutValue(i, rand()%2);  // вводим значения в массив
		}

	}

	int getMx(int max_x) 
    {

		mx = max_x;

		return mx;

	}

    int getMy(int max_y) 
    {

		my = max_y;

		return my;

	}

	void show() 
    {                  
		
		for (int i = 0; i < mx*my; i++) 
        {
			cout << pointer.GetValue(i); // выводим значения массива
			counter++;

			if (counter == mx) 
            {
				cout << endl;
				counter = 0;
			}

		}
	
	}

	~Image() 
    {
		cout << "IMAGE DESTRUCTOR" << endl;
	}
    
};


int size_mx, size_my;
bool check = 0;


int main() {

	cout << endl;
	cout << "Enter mx: ";
	cin >> size_mx;
	cout << "Enter my: ";
	cin >> size_my;

	Image a(size_mx, size_my);

  a.getMx(size_mx);
	a.getMy(size_my);

  a.makeImg();
	
	a.show();
	
	return 0;

}
