#include "CustomJNICppImpl.h"
#include <iostream>

using namespace std;

int sayHello(int num, const char *name)
{
    string userName = name;
    try
    {
        if (num < 0)
        {
            throw invalid_argument("C++: num should be positive");
        }

        cout << "Hello World from " << num << "-" << name << "!" << endl;
        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }
}