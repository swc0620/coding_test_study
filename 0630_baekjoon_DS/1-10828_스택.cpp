/* #include <iostream>
#include <string>
// using linked list

class Node {
public:
    int item;
    Node *next;
    Node(int _item) : item(_item), next(NULL) {}
    Node(int _item, Node *_next) : item(_item), next(_next) {}
    ~Node() {}
};

Node *head;
int num_items;

void push(int x) {
    head = new Node(x, head);
    num_items++;
}

void pop() {
    if (head == NULL) {
        std::cout << -1 << '\n';
    } else {
        Node* temp = head;
        head = head->next;
        std::cout << temp->item << '\n';
        num_items--;
        delete temp;
    }
}

void size() {
    std::cout << num_items << '\n';
}

void empty() {
    std::cout << (num_items == 0) ? 1 : 0 << '\n';
}

void top() {
    if (head == NULL) {
        std::cout << -1 << '\n';
    } else {
        std::cout << head->item << '\n';
    }
}

int main() {
    int N;
    std::cin >> N;

    head = NULL;
    num_items = 0;
    
    for (int i=0; i<N; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "push") {
            int x;
            std::cin >> x;
            push(x);
        } else if (command == "pop") {
            pop();
        } else if (command == "size") {
            size();
        } else if (command == "empty") {
            empty();
        } else {
            top();
        } 
    }
    
    /* while (head != NULL) {
        Node *temp = head;
        head = temp->next;
        delete temp;
    }

    return 0;
} */

#include <iostream>
#include <stack>

int main() {
    int N;
    std::cin >> N;

    std::stack<int> s;

    for (int i=0; i<N; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "push") {
            int x;
            std::cin >> x;
            s.push(x);

        } else if (command == "pop") {
            if (s.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << s.top() << '\n';
            s.pop();

        } else if (command == "size") {
            std::cout << s.size() << '\n';

        } else if (command == "empty") {
            std::cout << ((s.empty()) ? 1 : 0) << '\n';

        } else {
            if (s.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << s.top() << '\n';
        }
    }
    return 0;
}