#include <iostream>
using namespace std;

struct node {
    int val;
    node * right;
    node * left;
    node(int x){
        val = x;
        right = NULL;
        left = NULL;
    } 
};

struct bst {
private : 

    node * root;
    node * add(node * current, int x){
        if(current == NULL) return new node(x);

        if(current->val > x) current->left = add(current->left, x);
        else if (current->val < x) current->right = add(current->right, x);

        return current;
    }

    int is_balanced(node * current, int len) {
        int l = 0, r = 0;
        if(current != NULL) {
            l = is_balanced(current->left, 0);
            r = is_balanced(current->right, 0);
            if(abs(l - r) > 1) {
                cout << "NO";
                exit(0);
            }
            len += max(l, r);
            if(current != root) len++;
        }  
        if(current == root) return abs(l - r);
        return len;
    }

public:       

    bst() {
        root = NULL;
    }

    void add(int x) {
        node * res = add(root, x);
        if(root == NULL) root = res;
    }

    int is_balanced() {
        return is_balanced(root, 0);
    }
};

int main(){
    int n;
    cin >> n;
    bst b;
    while(n != 0) {
        b.add(n);
        cin >> n;
    }
    cout << (b.is_balanced() < 2 ? "YES":"NO");
}