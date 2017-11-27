/*
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where 
 * different letters represent different tasks.Tasks could be done without original order. Each task 
 * could be done in one interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 *
 * Example 1:
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * Note:
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 * My Solution:
 *
 * 1. Count counts for each kind;
 * 2. Sort counts of all kinds;
 * 3. 先以数量最多的类型为挡板，每两个挡板之间有n个idle任务；
 * 4. 如果其它类型也有这么多（排序的前几位），则每两个挡板之间放一个，最后必然每种类型多出一个；
 * 5. 原则就是在挡板之间依次放每种类型（按类型的数量从大到小的顺序来），每两个挡板之间放一个，先把所有idle尽可能占满，然后就依然是在每两个挡板之间放。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:

        void sort(vector<int> &count)
        {
            for(int j = 0; j < count.size() - 1; ++j)
            {
                for(int i = 1; i < count.size(); ++i)
                {
                    if(count[i] > count[i-1]) 
                    {
                        int tmp = count[i];
                        count[i] = count[i-1];
                        count[i-1] = tmp;
                    }
                }
            }
        }
        
        void show(vector<int>& count)
        {
            for(vector<int>::iterator it = count.begin(); it != count.end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }

        int leastInterval(vector<char>& tasks, int n)
        {
            vector<char> kind;
            vector<int> count;
            bool knownKind = false;
            for(vector<char>::iterator it = tasks.begin(); it != tasks.end(); ++it)
            {
                knownKind = false;
                for(int i = 0; i < kind.size(); ++i)
                {
                    if(kind[i] == *it)
                    {
                        count[i]++;
                        knownKind = true;
                        break;
                    }
                }
                if(!knownKind)
                {
                    kind.push_back(*it);
                    count.push_back(1);
                }
            }
            sort(count);

            int totalIntvl = 0;
            if(count.size() > 0)
            {
                totalIntvl = n * count[0] - n + count[0];
                int maxCount = 0, otherSum = 0;
                for(int i = 1; i < count.size(); ++i)
                {
                    if(count[i] == count[0]) 
                        maxCount++;
                    else
                        otherSum += count[i];
                }
                if(maxCount >= n)
                {
                    totalIntvl += n + (maxCount - n) * count[0] + otherSum;
                }
                else
                {
                    totalIntvl += maxCount;
                    int idleCount = (n - maxCount) * (count[0] - 1);
                    totalIntvl += (idleCount > otherSum ? 0 : otherSum - idleCount);
                }
            }

            return totalIntvl;

        }
};

int main()
{
    Solution s;
    char cs[] = {'A', 'A', 'A', 'B', 'B', 'B'}; //, 'C', 'D', 'D'};
    vector<char> tasks (cs, cs + sizeof(cs)/sizeof(char) );
    int result = s.leastInterval(tasks, 2);
    cout << "Max interval count = " << result << endl;
}
