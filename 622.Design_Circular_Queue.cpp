#include <iostream>
#include <exception>
#define DEFAULT_VALUE -1

using namespace std;

struct queueBlock {
    int value;
    queueBlock* next;
};

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        
        head = new queueBlock();
        head->value = DEFAULT_VALUE;
        if(k == 1) {
            head->next = head;
            tail = head;
            return;
        }
        queueBlock* tmp;
        tmp = head;
        for(int i = 2; i < k; ++i) {
            queueBlock* cur = new queueBlock();
            cur->value = DEFAULT_VALUE;
            tmp->next = cur;
            tmp = cur;
        }
        queueBlock* cur = new queueBlock();
        tmp->next = cur;
        cur->value = DEFAULT_VALUE;
        cur->next = head;
        tail = head;
    }
    
    bool enQueue(int v) {
        if(isFull()) {
            return false;
        }
        try {
            tail->value = v;
            tailVal = v;
            tail = tail->next;
        } catch(exception &e) {
            cout << "Error: " << e.what() << endl;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        try {
            head->value = DEFAULT_VALUE;
            head = head->next;
        } catch(exception &e) {
            cout << "Error: " << e.what() << endl;
        }
        return true;
    }
    
    int Front() {
        return head->value; 
    }
    
    int Rear() {
        return isEmpty() ? -1 : tailVal;
    }
    
    bool isEmpty() {
        if(head == tail && head->value == DEFAULT_VALUE)
            return true;
        return false;
    }
    
    bool isFull() {
        if(head == tail && head->value != DEFAULT_VALUE)
            return true;
        return false;
    }
private:
    queueBlock* head;
    queueBlock* tail;
    int tailVal;
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
