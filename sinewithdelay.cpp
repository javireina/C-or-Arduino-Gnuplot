#include <iostream>
#include <unistd.h>
#include <cmath>
#include <fstream>
using namespace std;

int main ()
{
    ofstream write;
    write.open("sine.csv");
    float x=0;
    while(x<1000)
        {
            write << x/100 << "," << sin(x/100) << "," << sin(x/100)+1 << "," << sin(x/100)*sin(x/100) << endl;
            usleep(10000);
            x++;
        }
    write.close();
    cout << "finished";
    return 0;
}
