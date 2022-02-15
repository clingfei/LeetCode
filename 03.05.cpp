#include <stack>

using namespace std;

class SortedStack {
private:
    stack<int> s1, s2;
public:
    SortedStack() {

    }
    
    void push(int val) {
        if (s1.empty()) {
            s1.push(val);
            return;
        }
        while (!s1.empty() && s1.top() <= val) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(val);
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if (s1.size() > 0) {
            s1.pop();
        }
    }
    
    int peek() {
        return s1.empty() ? -1 : s1.top();
    }
    
    bool isEmpty() {
        return s1.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */