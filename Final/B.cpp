#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(Node* next) : val(0), next(next) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (head == nullptr) {
        head = node;
    }
    else if (p == 0) {
        node->next = head;
        head = node;
    }
    else {
        Node* cur = head, * next = nullptr;
        for (int i = 1; i < p; i++) {
            cur = cur->next;
        }

        if (cur != nullptr) {
            next = cur->next;
        }

        node->next = next;  // = cur -> next;
        cur->next = node;
    }

    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0)
        return head->next;

    Node* cur = head;

    for (int i = 1; i < p; i++) {
        cur = cur->next;   
    }

    cur->next = cur->next->next;

    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2)
        return head;

    Node * m = head;

    for (int i = 0; i < p1; i++) {
        m = m->next;
    }

    int v;
    v = m->val;

    head = remove(head, p1);
    head = insert(head, new Node(v), p2);

    return head;
}

Node* reverse(Node* head) {
    Node* ans = nullptr;

    while (head != nullptr) {
        ans = insert(ans, new Node(head->val), 0);
        head = head->next;
    }

    return ans;
}

void print(Node* head) {
    if (head == nullptr)
        cout << -1;

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;

}

Node* cyclic_left(Node* head, int x) {
    Node* cur = head;
    int l = 1;

    while (cur->next != nullptr) {
        cur = cur->next;
        l++;
    }

    cur->next = head;

    for (int i = x; i > 0; i--) {
        cur = cur->next;
    }

    head = cur->next;
    cur->next = nullptr;

    return head;
}

Node* cyclic_right(Node* head, int x) {
    Node* cur = head;
    int l = 1;

    while (cur->next != nullptr) {
        cur = cur->next;
        l++;
    }

    cur->next = head;

    for (int i = l - x; i > 0; i--) {
        cur = cur->next;
    }

    head = cur->next;
    cur->next = nullptr;

    return head;
}

int main() {
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0) {
            break;
        }
        else if (command == 1) {
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2) {
            int p; cin >> p;
            head = remove(head, p);
        }
        else if (command == 3) {
            print(head);
        }
        else if (command == 4) {
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5) {
            head = reverse(head);
        }
        else if (command == 6) {
            int x; cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7) {
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}