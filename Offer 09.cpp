#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> s1, s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */