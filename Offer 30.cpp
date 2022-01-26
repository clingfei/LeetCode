#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> minstack, help;    
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        minstack.push(x);
        if (help.empty() || x <= help.top()) {
            help.push(x);
        }
        else help.push(help.top());
    }
    
    void pop() {
        help.pop();
        minstack.pop();
    }
    
    int top() {
        return minstack.top();
    }
    
    int min() {
        return help.top();
    }
};
