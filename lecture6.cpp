#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


using namespace std;

vector <int> vct(50);

mutex mut;

void increaseVector() 
{
   mut.lock();

    cout << "THREAD ID: " << this_thread::get_id() << endl;

    for (int i = 0; i < 50; i++) 
    {
        cout << "increase value from  " << i; 
        vct.at(i) = i*10;
        cout << "  to " << vct.at(i) << endl;

    }
   
   mut.unlock();

}

void showVector()
{
    mut.lock();

    cout << "\t\t\t\tTHREAD ID: " << this_thread::get_id() << endl;

    for(int i = 0; i < 50; i++) 
    {
        cout << "\t\t\t\tvector value " << i << "  " << vct.at(i) << endl;
    }
  
    mut.unlock();

}


int main() {
    
    thread th1(increaseVector);

    thread th2(showVector);

    th1.join();

    th2.join();

    cout << "UI ID: " << this_thread::get_id << endl;
   

}
