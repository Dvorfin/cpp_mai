#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

vector <int> vct(20);

mutex mut;

int increase(int i) 
{
    mut.lock();

    cout << "increase value from  " << i; 

    vct.at(i) = i*10;

    cout << "  to " << vct.at(i) << endl;

    mut.unlock();

}

int decrease(int i)
{
    mut.lock();

    cout << "decrease value from  " << vct.at(i);

    vct.at(i) = vct.at(i) - 5;

    cout << "  to " << vct.at(i) << endl;

    mut.unlock();

}


int main() {

    

    for (int i = 0; i < 20; i++) 
    {
         thread th1(increase, std::ref(i));

         thread th2(decrease, std::ref(i));

         th1.join();

         th2.join();
    }
   

    for (int j = 0; j < 20; j++)
    {
        cout << vct.at(j) << endl;
    }

   


}
