#include <iostream>
#include <fstream>

using namespace std;


class Image {

	int mx;

	int my;

	bool color = 0;

	int counter = 0;

	int data[100000];

public:

	Image(int tmx, int tmy) {      // заполняем массив нулями 

		for (int i = 0; i < 10000; i++)

		//data[i] = rand() % 2;
		 data[i] = 0;

		cout << "CONSTRUCTOR CHECK";

	}

	int format(bool clr) {  // выбираем цветное заполнение или монохромное

		color = clr;

		if (color == 1) {
			for (int i = 0; i < mx*my; i++) {
				data[i] = rand() % 255;
			}
		}
		else {
			for (int i = 0; i < mx*my; i++) {
				data[i] = rand() % 2;
			}
		}

		return color;
	}

	int getMx(int max_x) {  // размер изображения по иксу

		mx = max_x;

		return mx;

	}

	int getMy(int max_y) {  // размер изображения по игреку

		my = max_y;

		return my;

	}

	void show() {                   // выводим изображение 
		counter = 0;
		for (int i = 0; i < mx*my; i++) {


			cout << data[i];
			counter++;
			if (counter == mx) {
				cout << endl;
				counter = 0;
			}

		}
		counter = 0;
	}


	void line(int y) {      // рисуем горизонтальную линию 
		counter = mx * (y - 1);
		for (int i = 0; i < mx; i++)
		{
			data[counter] = 1;
			counter++;
		}

	}

	void row(int x) {        // рисуем вертикальную линию
		counter = 0;
		for (int i = 0; i < my; i++)
		{
			data[x + mx * (counter - 1) - 1] = 1;
			counter++;
		}

	}


	int get(int x, int y) {      // узнаем цвет пикселя

		cout << "PIXEL IS: " << data[x + mx * (y - 1) - 1];

		return 0;

	}

	void set(int x, int y, int color) {    // устанавливаем цвет пикселя

		data[x + mx * (y - 1) - 1] = color;

	}

	void save() {          // сохранение картинки
		ofstream file("image.pnm");
		if (color == 0) {      // вариант для монохромного изображения
			file << "P1" << endl << mx << " " << my << endl;
			for (int i = 0; i < mx*my; i++) {

				file << data[i];
				counter++;
				if (counter == mx) {
					file << endl;
					counter = 0;
				}

			}
			counter = 0;
			file.close(); // закрываем файл
		}
		else {   // вариант для сохранения цветного изображения

			file << "P3" << endl << mx << " " << my << endl;
			for (int i = 0; i < mx*my; i++) {

				file << data[i] << " ";
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

};

Image a(10, 10);

int size_mx, size_my, color_set, x, y, line, row;
bool check = 0, picColor = 0;


int main() {


	cout << endl;
	cout << "Enter mx: ";
	cin >> size_mx;
	cout << "Enter my: ";
	cin >> size_my;

	a.getMx(size_mx);
	a.getMy(size_my);

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		a.show();
		check = 0;
	}

	cout << "Choose PBM or PPM [1/0]: ";  // цветное или монохромное изображение
	cin >> picColor;
	a.format(picColor);
	if (picColor == 1) {
		cout << "Your picrture will be colored" << endl;
	}
	else {
		cout << "Your picture will be black and white" << endl;
	}

	cout << endl << "Chose color: ";
	cin >> color_set;
	cout << endl << "Chose position: ";
	cin >> x >> y;
	a.set(x, y, color_set);

	cout << endl << "Chose pixel to check: ";
	cin >> x >> y;
	a.get(x, y);

	cout << endl << "Choose line: ";
	cin >> line;
	a.line(line);

	cout << endl;

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		a.show();
		check = 0;
	}

	cout << "Choose row: ";
	cin >> row;
	a.row(row);

	cout << endl << endl;

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		a.show();
		check = 0;
	}

	a.save();

	return 0;

}
