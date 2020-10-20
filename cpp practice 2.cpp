#include <iostream>
#include <fstream>

using namespace std;

template <class Type> 
class Image {

	int mx;

	int my;

	bool color = 0;

	int counter = 0;

public:

	Type *ptr;

public:

	Image(int tmx, int tmy) {      // Должен инициализировать изображение 0   

		ptr = new Type[tmx*tmy]();   // создание динамического массива под размеры пользователя
		for (int i = 0; i < tmx*tmy; i++) {
				ptr[i] = rand() % 2;
			}
		cout << "CONSTRUCTOR CHECK " << this << endl;

	}

	Image(const Image & image2) {  // конструктор копирования

		cout << "CONSTRUCTOR COPY CHECK " << this;

		this->mx = image2.mx;
		this->my = image2.my;
		this->ptr = new Type[mx*my];

		for (int i = 0; i < mx*my; i++) {

			this->ptr[i] = image2.ptr[i];

		}

	}

	bool operator ==(const Image & image2) { // передаем адрес второй картинки 
											// перегрузка оператора ==
		bool res = 1;

		for (int i = 0; i < mx*my; i++) {    // сравниваем значения динамических массивов изображений

			if (ptr[i] != image2.ptr[i]) {
				res = 0;
			}

		}

		return res;

	}

	Image & operator =(const Image & image1) { // перегрузка оператора присваивания

		delete[] this->ptr;

		this->ptr = new Type[mx*my];

		for (int i = 0; i < mx*my; i++) {

			this->ptr[i] = image1.ptr[i];

		}

		return *this;  // возвращаем значение картинки а

	 }  

	int getMx(int max_x) {

		mx = max_x;

		return mx;

	}

	int getMy(int max_y) {

		my = max_y;

		return my;

	}

	void show() {                   // Должен выдавать на экран изображение при помощи printf или       std::cout
		
		counter = 0;
		for (int i = 0; i < mx*my; i++) {


			cout << ptr[i];
			counter++;
			if (counter == mx) {
				cout << endl;
				counter = 0;
			}

		}
		counter = 0;
	}

	int get(int x, int y) {

		if (x*y > mx*my) {    // обработка просмотра данных за пределами массива 
			throw "OUT OF MASSIVE"; 
		} else {
			cout << "PIXEL IS: " << ptr[x + mx * (y - 1) - 1];
		}

		return 0;

	}

	void set(int x, int y, int color) {

		if (x*y > mx*my) {   // обработка исключения при попытки записи за пределы массива
			throw "ERROR WRITING";
		} else {
			ptr[x + mx * (y - 1) - 1] = color;
		}

	}

	void save() {
		ofstream file("kartinka.pnm");
		if (color == 0) {
			file << "P1" << endl << mx << " " << my << endl;
			for (int i = 0; i < mx*my; i++) {

				file << ptr[i];
				counter++;
				if (counter == mx) {
					file << endl;
					counter = 0;
				}

			}
			counter = 0;
			file.close(); // закрываем файл
		}
		else {

			file << "P3" << endl << mx << " " << my << endl;
			for (int i = 0; i < mx*my; i++) {

				file << ptr[i] << " ";
				counter++;
				if (counter == mx) {
					file << endl;
					counter = 0;
				}

			}
			counter = 0;
			file.close(); // закрываем файл
		}
		
	}

	~Image() {  // деструктор
		cout << "DESTRUCTOR CHECK " << this << endl;
		delete[] ptr;
	}

	
};


int size_mx, size_my, color_set, x, y;
bool check = 0;


int main() {

	cout << endl;
	cout << "Enter mx: ";
	cin >> size_mx;
	cout << "Enter my: ";
	cin >> size_my;

	Image <int> a(size_mx, size_my);   //создаем объекты класса image

	a.getMx(size_mx);
	a.getMy(size_my);

	try
	{
		cout << endl << "Chose color: "; // попытка вызова исключения
		cin >> color_set; 
		cout << endl << "Chose position: ";
		cin >> x >> y;
		a.set(x, y, color_set);

		cout << endl << "Chose pixel to check: ";
		cin >> x >> y;
		a.get(x, y);  

		cout << endl << "Successfully" << endl;
		
	}

	catch(const char *e) // передаем указатель на сообщение, кидаемое throw
	{
		cout << e << endl; 
	}

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		a.show();
		check = 0;
	}

	Image <int> b(a);  // конструктор копирования 

	bool result = a == b;  // присваиваем переменной result значение сравнения двух изображений с помощью перегруженного оператора ==

	if (result) {
		cout << endl << "Pictures are equal" << endl << endl;
	} else {
		cout << endl << "Pictures are not equal" << endl << endl;
	}

//	b = a;
	cout << "Picture 1 :" << endl;
	a.show();
	cout << endl;
	cout << "Picture 2 :" << endl;
	b.show();
	a.save();

	return 0;

}
