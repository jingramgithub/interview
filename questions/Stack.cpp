/*
 * Question asked by Baidu devs.
 *
 * To define a stack which can return min value by O(1).
 *
 * 2017/11/19
 *
 */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
    public:
        void Pop();
        void Push(T);
        T GetMin();
        int Size() { return data.size(); }

    private:
        vector<T> data;
        vector<int> minIndexs;
};

template <class T>
void Stack<T>::Push(T t)
{
   data.push_back(t);
   if(minIndexs.empty() || t < data.at(minIndexs.back()))
   {
        minIndexs.push_back(data.size() - 1);
   }
}

template <class T>
void Stack<T>::Pop()
{
    if(data.size() == (minIndexs.back() + 1))
    {
        minIndexs.pop_back();
    }
    data.pop_back();
}

template <class T>
T Stack<T>::GetMin()
{
    return data.at(minIndexs.back());
}

int main()
{
    Stack<int> sData;

    int array[] = {3, 2, 6, 4, 8, 1, 3};
    int size = sizeof(array) / sizeof(int);
    for(int i = 0; i < size; i++)
    {
        sData.Push(array[i]);
        cout << array[i] << "\t";
    }
    cout << endl;

    while(sData.Size() != 0)
    {
        cout << "Min = " << sData.GetMin() << endl;
        
        sData.Pop();
    }
}
