#include <iostream>

using namespace std;

template <class Type>

class SmartPoint
{

public:

	SmartPoint() : ptr(nullptr)
    {
        cout << "Smart pointer constructor" << endl;
    }

    ~SmartPoint()
    {
        cout << "Smart pointer destructor" << endl;
        void clean();
    }

	void clean() // метод удаления указателя
	{
		if (ptr != nullptr) // если не пустой
		{
			delete ptr; // то удалеям
		}
	}

    Type& operator* ()  // возвращаем значение, лежащее по указателю
	{
		return *(this->ptr); 
	}

	Type* operator-> ()  // возвращаем указатель
	{
		return this->ptr;
	}

	void MakeSmartPtr(Type *outsidePtr)
	{
		this->ptr = outsidePtr;
	}

	SmartPoint(const SmartPoint &object) = delete;  // удаление коснтруктора копирования и присваивания
	SmartPoint &operator=(const SmartPoint &object) = delete;

private:

    Type *ptr = nullptr;

};

template <class Type>

class SmartPoint<Type[]>
{

public:

    SmartPoint() : ptr(nullptr)
    {
        cout << "Smart pointer constructor" << endl;
    }

    ~SmartPoint()
    {
        cout << "Smart pointer destructor" << endl;
        void clean();
    }

	void clean() // метод удаления указателя
	{
		if (ptr != nullptr) // если не пустой
		{
			delete[] ptr; // то удалеям
		}
	}

    Type& operator* ()  // возвращаем значение, лежащее по указателю
	{
		return *(this->ptr); 
	}

	Type* operator-> ()  // возвращаем указатель
	{
		return this->ptr;
	}

	Type& operator[] (int index)
	{
		if (index < 0) 
		{
			cerr << "Index below zero!" << endl;
			exit(0);
		}

		return this->ptr[index];
	}

	void MakeSmartPtr(Type *outsidePtr)
	{
		this->ptr = outsidePtr;
	}

	SmartPoint(const SmartPoint &object) = delete;  // удаление коснтруктора копирования и присваивания
	SmartPoint &operator=(const SmartPoint &object) = delete;

private:

    Type *ptr = nullptr;

};

SmartPoint<int[]> pointer;  // создаем объект класса умного указателя типа int

class Image 
{
	int mx;

	int my;

	int counter = 0;
    
public:

	Image(int tmx, int tmy) 
    {       

		pointer.MakeSmartPtr(new int[tmx*tmy]());   // создание динамического массивыа под размеры пользователя
		cout << "IMAGE CONSTRUCTOR" << endl;
    
    }

    void makeImg()
    {
        for (int i = 0; i < mx*my; i++) 
        {
			pointer[i] = rand()%2;
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
			cout << pointer[i];
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
	
	cout << "pointer =  " << pointer[3] << endl;
	

	return 0;

}
