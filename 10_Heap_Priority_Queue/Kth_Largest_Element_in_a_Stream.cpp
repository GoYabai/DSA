#include <queue>
using namespace std;


/*
erm thì bài này max heap cũng dc th nhưng lâu vcl nên leetcode sẽ sai nên ta biến bài code thành
dạng tìm số lớn thứ k của maxheap thành tìm số nhỏ nhất của min heap có k phần tử
*/
//max heap
class KthLargest {
public:
    priority_queue<int> maxHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++)
        {
            maxHeap.push(nums[i]);
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        priority_queue<int> temp(maxHeap);
        for (int i = 0; i < k - 1; i++)
        {
            temp.pop();
        }
        return temp.top();
    }
};

//min heap
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};