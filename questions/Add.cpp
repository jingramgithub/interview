/*
 * Question asked in Jin Ri Tou Tiao.
 *
 * A question to use one direction link to implement add of numbers.
 *
 * 2017/11/23
 *
 */

#include <iostream>

using namespace std;

class Node
{
    public:
        Node* next;

        Node(int digit)
        {
            if(digit < 0 || digit > 9)
            {
                cout << "Illegal digit for Node instance" << endl;
                mData = 0;
            }
            else
            {
                mData = digit;
            }
            next = nullptr;
        }

        int Data() { return mData; }
        void SetData(int d) { mData = d; }

        void Incr() { mData++; }

    private:
        int mData;
};

class DecimalNumber
{
    public:
        int size;

        DecimalNumber(int number);
        ~DecimalNumber();

        DecimalNumber operator+(const DecimalNumber& other);

        void Show();

    private:
        Node* head;
};

DecimalNumber::DecimalNumber(int number) : size(0)
{
    Node* digit = new Node(number % 10);
    head = digit;
    size++;

    int nextDigit = number / 10;
    while(nextDigit > 0)
    {
        Node* tmp = new Node(nextDigit % 10);
        tmp->next = head;
        head = tmp;
        nextDigit = nextDigit / 10;
        size++;
    }
}

DecimalNumber::~DecimalNumber()
{
    Node* p = head;
    while(p != nullptr)
    {
        Node* tmp = p->next;
        delete p;
        p = tmp;
    }
}

void DecimalNumber::Show()
{
    Node* p = head;
    while(p != nullptr)
    {
        cout << p->Data() << (p->next == nullptr ? "\n" : "-");
        p = p->next;
    }
}

DecimalNumber DecimalNumber::operator+(const DecimalNumber& other)
{
    // to lower the complexity, add from high postion to low position
    int longSize = 0, shortSize = 0;
    Node *p, *q;
    if(size > other.size)
    {
        longSize = size;
        shortSize = other.size;
        p = head;
        q = other.head;
    }
    else
    {
        longSize = other.size;
        shortSize = size;
        p = other.head;
        q = head;
    }

    // start with digit 0 to handle with numbers like 999
    DecimalNumber result = DecimalNumber(0);
    Node* pTo9Ahead = result.head;
    Node* pr = result.head;

    for(int i = 0; i < (longSize - shortSize); i++)
    {
        Node* nextDigit = new Node(p->Data());
        pr->next = nextDigit;
        pr = pr->next;

        if(p->Data() != 9)
        {
            pTo9Ahead = pr;
        }

        p = p->next;
    }

    for(int i = 0; i < shortSize; i++)
    {
        int digitSum = p->Data() + q->Data();
        if(digitSum > 9)
        {
            Node* nextDigit = new Node(digitSum % 10);
            pr->next = nextDigit;
            pr = pr->next;

            pTo9Ahead->Incr();
            pTo9Ahead = pTo9Ahead->next;
            while(pTo9Ahead->Data() == 9)
            {
                pTo9Ahead->SetData(0);
                pTo9Ahead = pTo9Ahead->next;
            }
        }
        else
        {
            Node* nextDigit = new Node(digitSum);
            pr->next = nextDigit;
            pr = pr->next;

            if(digitSum != 9)
            {
                pTo9Ahead = nextDigit;
            }
        }
        p = p->next;
        q = q->next;
    }

    // remove the first digit 0.
    if(result.head->Data() == 0)
    {
        Node* tmp = result.head;
        result.head = result.head->next;
        delete tmp;
    }

    return result;
}


int main()
{
    {
        DecimalNumber num1 = DecimalNumber(123405);
        num1.Show();
        DecimalNumber num2 = DecimalNumber(123405);
        num2.Show();

        DecimalNumber sum = num1 + num2;
        sum.Show();
        cout << endl;
    }
    {
        DecimalNumber num1 = DecimalNumber(99999);
        num1.Show();
        DecimalNumber num2 = DecimalNumber(999);
        num2.Show();

        DecimalNumber sum = num1 + num2;
        sum.Show();
        cout << endl;
    }
    {
        DecimalNumber num1 = DecimalNumber(1939405);
        num1.Show();
        DecimalNumber num2 = DecimalNumber(9405);
        num2.Show();

        DecimalNumber sum = num1 + num2;
        sum.Show();
        cout << endl;
    }
    {
        DecimalNumber num1 = DecimalNumber(99999);
        num1.Show();
        DecimalNumber num2 = DecimalNumber(0);
        num2.Show();

        DecimalNumber sum = num1 + num2;
        sum.Show();
        cout << endl;
    }
    return 0;
}
