/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */
#include <vector>
using namespace std;    

// @lc code=start
class MyCircularQueue {
private:
    int front, back;
    int len;
    vector<int> que;
public:
    MyCircularQueue(int k) {
        que.resize(k + 1);
        front = 0;
        back = 0;
        len = k + 1;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        que[back] = value;
        back = (back + 1) % len;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) 
            return false;
        front = (front + 1) % len;
        return true;
    }
    
    int Front() {
        if (!isEmpty())
            return que[front];
        else 
            return -1;
    }
    
    int Rear() {
        if (!isEmpty())
            return que[(back - 1 + len) % len];
        else 
            return -1;
    }
    
    bool isEmpty() {
        return front == back;
    }
    
    bool isFull() {
        return (back + 1) % len == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

