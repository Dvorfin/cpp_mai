#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

int mx = 100, my = 20, counter;
bool check = 0;
int gist[255]={0};


void Show(int *ptr) {   // выводим картинку 
    cout << "Image: " << endl;
    counter = 0;
		for (int i = 0; i < mx*my; i++) {

			cout << ptr[i] << " ";
			counter++;
			if (counter == mx) {
				cout << endl;
				counter = 0;
			}

		}
		counter = 0;
    cout << endl;
}

void Gist(int *ptr, int first, int second){    // функция заполнения массива гистограммы

  //  this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Number of thread: \t" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(1));
    int i =0;   
     for (first; i < second; i++) {
        gist [ptr [i]] = gist [ptr [i]] + 1;
    }
    i = 0;
        
}

void ShowGist() {   // вывод содержимого гистограммы
    cout << "Gist: " << endl;
    for (int i = 1; i < 256; i++) {
            cout << i << " ";
            for (int j = 0; j < gist[i]; j++){
                cout  << "*" << " ";
            }
            cout << endl;
        }
    cout << endl;
}

int main() {

    int *ptr;

    ptr = new int[mx*my];  // создаем динамический массив для картинки

    for (int i = 0; i < mx*my; i++) {   // заполняем картинку в оттенках серого
			ptr[i] = rand() % 256;
		}


  //  int thr0 = 200; // до какого элемента считает основной поток
  //  int thr = mx*my; //  до какого элемента считает следующий поток

    thread th1(Gist, std::ref(ptr), 100, 200); // от 100 элемнта на 200 и т.д.
    thread th2(Gist, std::ref(ptr), 200, 300);
    thread th3(Gist, std::ref(ptr), 300, 400);
    thread th4(Gist, std::ref(ptr), 400, 500);
    thread th5(Gist, std::ref(ptr), 500, 600);
    thread th6(Gist, std::ref(ptr), 600, 700);
    thread th7(Gist, std::ref(ptr), 700, 800);
    thread th8(Gist, std::ref(ptr), 800, 1000);
    thread th9(Gist, std::ref(ptr), 1002, 1500);
    thread th10(Gist, std::ref(ptr), 1500, 1700);
    thread th11(Gist, std::ref(ptr), 1700, 1800);
    thread th12(Gist, std::ref(ptr), 1800, 1850);
    thread th13(Gist, std::ref(ptr), 1850, 1900);
    thread th14(Gist, std::ref(ptr), 1900, 1950);
    thread th15(Gist, std::ref(ptr), 1950, 2000);

	//	Show(ptr);
    
    Gist(ptr, 0, 100); // от нулеового элемента до 100 

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();
    th11.join();
    th12.join();
    th13.join();
    th14.join();
    th15.join();

	ShowGist();


    delete[] ptr;

    cout << "runtime = " << clock()/1000.0 << endl; // время работы программы 

    return 0;
}

