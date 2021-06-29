

/* implement by circular linked list*/
/* class Node {
public:
    int item;
    Node *next;
    Node(int _item) : item(_item), next(NULL) {}
    Node(int _item, Node *_next) : item(_item), next(_next) {}
    ~Node() {}
};

class Queue {
private:
    Node *head;
    Node *tail;
    int num_items{ 0 };

public:
    Queue() : tail(NULL) {}
    ~Queue() {}

    void push(int x);
    void pop();
    void size();
    void empty();
    void front();
    void back();
};

void Queue::push(int x) {
    Node *newNode = new Node(x);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    /* if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    ++num_items;
}

void Queue::pop() {
    if (tail == NULL) {
        std::cout << "-1" << '\n';
    } else {

        int tmp = tail->next->item;
        if (tail->next == tail) {
            tail = NULL;
        } else {
            tail->next = tail->next->next;
        }
        --num_items;
        std::cout << tmp << '\n';
    }
}

void Queue::size() {
    std::cout << num_items << '\n';
}

void Queue::empty() {
    std::cout << ((tail = NULL) ? 1 : 0) << '\n';
}

void Queue::front() {
    if (tail == NULL) {
        std::cout << "-1" << '\n';
    } else {
        std::cout << tail->next->item << '\n';
    }
}

void Queue::back() {
    if (tail == NULL) {
        std::cout << "-1" << '\n';
    } else {
        std::cout << tail->item << '\n';
    }
} */

#include <iostream>
#include <queue>

int main() {
    int N;
    std::cin >> N;

    //Queue q;
    std::queue<int> q;

    for (int i=0; i<N; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "push") {
            int x;
            std::cin >> x;
            q.push(x);

        } else if (command == "pop") {
            if (q.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << q.front() << '\n';
            q.pop();

        } else if (command == "size") {
            std::cout << q.size() << '\n';

        } else if (command == "empty") {
            std::cout << ((q.empty()) ? 1 : 0) << '\n';

        } else if (command == "front") {
            if (q.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << q.front() << '\n';

        } else {
            if (q.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << q.back() << '\n';
        }
    }
    return 0;
}