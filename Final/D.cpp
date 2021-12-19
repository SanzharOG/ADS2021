#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;

    Node(int v) {
        left = nullptr;
        right = nullptr;
        val = v;
    };
};

Node* add(Node* root, int v) {
    if (root == nullptr) {
        return new Node(v);
    }
    else if (v < root->val) {
        root->left = add(root->left, v);
    }
    else if (v > root->val) {
        root->right = add(root->right, v);
    }

    return root;
}

void print(Node* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }
}

int ans(Node* root, int &h) {
    if (root == nullptr)
        return 0;

    int hl = ans(root->left, h);
    int hr = ans(root->right, h);
    int hroot = max(hl, hr) + 1;

    if (hl + hr + 2 > h)
        h = hl + hr + 2;

    return hroot;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        root = add(root, v);
    }

    int maxdist = 0;
    ans(root, maxdist);

    cout << maxdist - 1;

    return 0;
}