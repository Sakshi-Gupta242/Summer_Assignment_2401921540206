#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    // Constructor
    MyQueue() {
    }

    // Push element to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Return front element
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Remove front element
    int pop() {
        int front = peek();
        output.pop();
        return front;
    }

    // Check if queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);

    cout << "Front Element : " << q.peek() << endl;
    cout << "Popped Element: " << q.pop() << endl;

    q.push(3);

    cout << "Front Element : " << q.peek() << endl;

    if (q.empty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is Not Empty" << endl;

    return 0;
}