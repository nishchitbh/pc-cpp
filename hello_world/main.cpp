#include <iostream>
#include <thread>

using namespace std;

void hello_world(string name, int i) { cout << "Hello, " << name << " from thread " << i << endl; }

int main() {
    string name;
    int numThr;
    cout << "Enter your name:: ";
    cin >> name;
    cout << endl << "Enter the number of threads:: ";
    cin >> numThr;
    thread* thr[numThr];
    for (int i = 0; i < numThr; i++) {
        thr[i] = new thread(hello_world, name, i);
    }
    for (int i = 0; i < numThr; i++) {
        thr[i]->join();
        delete thr[i];
    }
    cout << "Hello, " << name << endl;
    return 0;
}
