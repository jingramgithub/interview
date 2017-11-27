/*
 * asm usage is not correct.
 * This file cann't compiled succussfully.
 * Just remember that volatile can bypass optimization of compiler to make sure reading variable from certain address every time.
 */

#include <iostream>

using namespace std;

int main()
{
    volatile int i = 10;
    int a = i;

    cout << "i = " << i << endl;

    asm (
        "mov dword [ebp-4], 20h"
    );

    int b = i;
    cout << "i = " << i << endl;

    return 0;
}
/*
int main()
{
    int i = 10;
    int a = i;

    cout << "i = " << i << endl;

    asm (
        "mov dword [ebp-4], 20h"
    );

    int b = i;
    cout << "i = " << i << endl;

    return 0;
}
*/
