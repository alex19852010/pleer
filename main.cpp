#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

class Track
{
    public: 

    string name;
    tm creationdate;
    int duration;

};

int main()
{
 time_t t = time(NULL);
 tm local = *localtime(&t);
 cin >> get_time(&local, "%H:%M");
 cout << local.tm_hour << " and " << local.tm_min;
 cout << "a";
}