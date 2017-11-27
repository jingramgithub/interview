#include <iostream>

using namespace std;

class abc
{
    public:
        abc() {
            cout << "abc constructed" << endl;
        }

        ~abc() {
            cout << "abc destructed" << endl;
        }
};

void del(abc *pobj)
{
    delete pobj;
}

int main()
{
    abc* p = new abc;
    del(p);
}
