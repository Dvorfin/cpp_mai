#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

vector <int> vct(50);

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

    cout << "\t\t\t\tvector value " << i << "  " << vct.at(i) << endl;

    //vct.at(i) = vct.at(i) - 5;

    

    mut.unlock();

}


int main() {

    

    for (int i = 0; i < 50; i++) 
    {
         thread th1(increase, std::ref(i));

         thread th2(decrease, std::ref(i));

         th1.join();

         th2.join();
    }
   

   
   


}
