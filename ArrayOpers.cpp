#include <iostream>

using namespace std;

static void BubbleSort(int unsorted[], int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(unsorted[j] < unsorted[i])
            {
                int tmp = unsorted[i];
                unsorted[i] = unsorted[j];
                unsorted[j] = tmp;
            }
        }
    }
}


int main()
{
    int unsorted[] = {0, 10, 2, 3, 1, 1};

    int len = sizeof(unsorted) / sizeof(unsorted[0]);

    BubbleSort(unsorted, len);

    for(int i = 0; i < len; i++)
    {
        cout << unsorted[i] << "\t";
    }
    cout << endl;

    return 0;
}
