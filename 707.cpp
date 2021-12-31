class MyLinkedList {
private: 
    struct myListNode {
        int val;
        myListNode * next;
        myListNode() :val(-1), next(nullptr) {};
        myListNode(int val) :val(val), next(nullptr) {};
    };
    int size;
    myListNode *head, *tail;
public:

    MyLinkedList() {
        head = new myListNode();
        size = 0;
        tail = head;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        else {
            int cnt = 0;
            myListNode *p = head->next;
            while (cnt < index) {
                cnt++;
                p = p->next;
            }
            return p->val;
        }
    }
    
    void addAtHead(int val) {
        myListNode *p = new myListNode(val);
        p->next = head->next;
        head->next = p;
        size++;
        if (p->next == nullptr) {
            tail = p;
        }
    }
    
    void addAtTail(int val) {
        myListNode *p = new myListNode(val);
        tail->next = p;
        tail = tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        myListNode *p = new myListNode(val);
        if (index < 0) {
            p->next = head->next;
            head->next = p;
        }
        else if (index == size) {
            tail->next = p;
            tail = tail->next;
        }
        else {
            int cnt = 0;
            myListNode *q = head;
            while (cnt++ < index) {
                q = q->next;
            }
            p->next = q->next;
            q ->next = p;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            myListNode *p = head;
            int cnt = 0;
            while (cnt++ < index) {
                p = p->next;
            }
            myListNode *t = p->next;
            p->next = t->next;
            if (p->next == nullptr) tail = p;
            delete(t);
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */