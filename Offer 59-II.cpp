#include <queue>

using namespace std;

class MaxQueue {
private:
    queue<int> que;
    deque<int> que2;
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if (que2.empty()) return -1;
        return que2.front();
    }
    
    void push_back(int value) {
        que.push(value);
        if (que2.empty() || que2.back() > value) {
            que2.push_back(value);
        } else {
            while (!que2.empty() && que2.back() < value)
                que2.pop_back();
            que2.push_back(value);
        }
    } 
    
    int pop_front() {
        if (!que2.empty() && que.front() == que2.front()) que2.pop_front();
        if (que.empty()) return -1;
        else {
            int t = que.front();
            que.pop();
            return t;
        }

    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */