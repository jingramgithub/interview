#include <iostream>

using namespace std;

template <class T>
class MaxHeap
{
    private:
        T* heap;
        int CurSize;
        int MaxSize;

    public:
        MaxHeap(int maxsize=10)
        {
            MaxSize = maxsize;
            heap = new T[MaxSize+1];
            CurSize = 0;
        }

        ~MaxHeap()
        {
            delete [] heap;
        }

        T GetMax()
        {
            if(CurSize == 0)
            {
                cout << "This heap is empty now" << endl;
                return -9999;
            }
            else
            {
                return heap[1];
            }
        }

        MaxHeap<T> &Insert(const T& x)
        {
            if(CurSize == MaxSize)
            {
                cout << "This heap is full" << endl;
                return *this;
            }

            int i = ++CurSize;
            while(i != 1 && x > heap[i/2])
            {
                heap[i] = heap[i/2];
                i /= 2;
            }
            heap[i] = x;
            cout << "Inserted " << x << "Successfully" << endl;
            return *this;
        }

        MaxHeap<T> &DeleteMax(T& x)
        {
            if(CurSize == 0)
            {
                cout << "This heap is empty, nothing to delete" << endl;
                return *this;
            }

            x = heap[1];
            heap[0] = heap[CurSize--];

            int i = 1;
            int largerChild = 2;

            while(largerChild <= CurSize)
            {
                if(heap[largerChild] < heap[largerChild + 1])
                    largerChild += 1;

                if(heap[0] < heap[largerChild])

        }
};
