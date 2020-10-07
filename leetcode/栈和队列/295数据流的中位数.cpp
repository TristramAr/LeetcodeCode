#include <queue>
using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }
// 维持最大堆和最小堆之间数量差最大为1；且最大堆的堆顶比最小堆堆顶小
    void addNum(int num)
    {
        if (big_queue.empty())
        {
            big_queue.push(num);
            return;
        }
        if (big_queue.size() == small_queue.size())
        {
            if (num < big_queue.top())
            {
                big_queue.push(num);
            }
            else
            {
                small_queue.push(num);
            }
        }
        else if (big_queue.size() > small_queue.size())
        {
            if (num > big_queue.top())
            {
                small_queue.push(num);
            }
            else
            {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        }
        else if(big_queue.size()<small_queue.size())
        {
            if(num<small_queue.top())
            {
                big_queue.push(num);
            }
            else
            {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }
    }

        double findMedian()
        {
            if(big_queue.size()==small_queue.size())
            {
                return (big_queue.top() + small_queue.top()) / 2.0;
            }
            else if(big_queue.size()>small_queue.size())
            {
                return big_queue.top();
            }
            return small_queue.top();
        }

    private:
        priority_queue<int> big_queue;
        priority_queue<int, vector<int>, greater<int>> small_queue;
    };