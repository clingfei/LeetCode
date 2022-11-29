/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */
#include <vector>
using namespace std;
// @lc code=start
class MyCircularDeque {
private:
    vector<int> v;
    int rear{}, front{};

    int prev(int pos)const { return (pos - 1 + v.size()) % v.size(); }
    int next(int pos)const { return (pos + 1) % v.size(); }
public:
    MyCircularDeque(int k) :v(k + 1) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        v[front = prev(front)] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        v[exchange(rear, next(rear))] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = next(front);
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = prev(rear);
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : v[front];
    }

    int getRear() {
        return isEmpty() ? -1 : v[prev(rear)];
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return next(rear) == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

