#include <iostream>
#include <queue>

using namespace std;

class Queue {
private:
    queue<int> q;

public:
    // Inserts a new element at the rear of the queue.
    void enqueue(int value) {
        q.push(value);
    }

    // Removes the front element of the queue and returns it.
    int dequeue() {
        if (!q.empty()) {
            int front = q.front();
            q.pop();
            return front;
        }
        else {
            cerr << "Queue is empty. Cannot dequeue." << endl;
            return -1; // You can choose to return a different value or throw an exception here.
        }
    }

    // Returns the front element present in the queue without removing it.
    int front() {
        if (!q.empty()) {
            return q.front();
        }
        else {
            cerr << "Queue is empty. No front element." << endl;
            return -1; // You can choose to return a different value or throw an exception here.
        }
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return q.empty();
    }

    // Returns the total number of elements present in the queue.
    int size() {
        return q.size();
    }
};

int main() {
    Queue Queue;

    Queue.enqueue(1);
    Queue.enqueue(2);
    Queue.enqueue(3);

    cout << "Front element: " << Queue.front() << endl;
    cout << "Dequeue: " << Queue.dequeue() << endl;
    cout << "Front element: " << Queue.front() << endl;
    cout << "Is empty? " << (Queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Queue size: " << Queue.size() << endl;

    return 0;
}
