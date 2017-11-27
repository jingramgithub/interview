/*
 * This file is to recall the basic knowledges of copy constructor function and override of operators.
 *
 */

#include <iostream>

using namespace std;

class NewString
{
    public:
        NewString(const char* str = nullptr);
        NewString(const NewString& other);
        NewString& operator=(const NewString& other);
        ~NewString();

        void Show();

    private:
        char* m_data;
};

NewString::NewString(const char* str)
{
    if(str == nullptr) {
        m_data = new char[1];
        m_data[0] = '\0';
    } else {
        int len = strlen(str);
        m_data = new char[len];
        strcpy(m_data, str);
    }
}

NewString::NewString(const NewString& other)
{
    if(m_data)
        delete [] m_data;

    size_t len = strlen(other.m_data);
    m_data = new char[len];
    strcpy(m_data, other.m_data);
}

NewString& NewString::operator=(const NewString& other)
{
    if(this == &other)
        return *this;

    if(m_data)
        delete [] m_data;

    size_t len = strlen(other.m_data);
    m_data = new char[len];
    strcpy(m_data, other.m_data);
    return *this;
}

NewString::~NewString()
{
    delete [] m_data;
}

void NewString::Show()
{
    cout << m_data;
}

int main()
{
    NewString ns = NewString("wjy");
    ns.Show();

    return 0;
}
