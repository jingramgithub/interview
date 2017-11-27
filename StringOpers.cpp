#include <iostream>
#include <cassert>

using namespace std;

char* strcpy(char* strDst, char* strSrc)
{
    assert((strDst != nullptr) && (strSrc != nullptr));
    
    char* address = strDst;
    
    while((*strDst++ = *strSrc++) != '\0') {}

    return address;
}

int main()
{
    char str[] = "hi, c++";
    char* copy = new char[strlen(str)];
    copy = strcpy(copy, str);
    cout << copy;
    return 0;
}
