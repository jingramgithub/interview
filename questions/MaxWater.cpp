/*
 * Question asked in Jin Ri Tou Tiao.
 * 
 * Calculate how many water can be hold in a hist-like feature.
 *
 * 2017/11/23
 */

#include <iostream>
#include <algorithm>

using namespace std;

int GetSum(const int* stages, int len)
{
    int leftMax[len];
    int rightMax[len];
    fill_n(leftMax, len, 0);
    fill_n(rightMax, len, 0);

    for(int i = 1; i < len; i++)
    {
        leftMax[i] = (stages[i-1] > leftMax[i-1] ? stages[i-1] : leftMax[i-1]);
        rightMax[len-1-i] = (stages[len-i] > rightMax[len-i] ? stages[len-i] : rightMax[len-i]);
    }

    int total = 0;
    for(int i = 1; i < len-1; i++)
    {
        int waterHeight = (leftMax[i] > rightMax[i] ? rightMax[i] : leftMax[i]);
        total += (waterHeight > stages[i] ? (waterHeight - stages[i]) : 0);
    }

    return total;
}

int main()
{
    int array[] = {0, 1, 0, 2, 0, 3, 0, 1, 0, 2, 0, 1};
    cout << GetSum(array, sizeof(array)/sizeof(int));
}
