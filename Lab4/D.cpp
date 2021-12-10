#include <iostream>
using namespace std;

struct node{
    int val;
    node * right;
    node * left;
    node(int x) {
        val = x;
        right = NULL;
        left = NULL;
    }
};

struct bst{
    
private: 
    node * root;
    node * add(node * current, int x) {
        if(current == NULL) return new node(x);

        if(current->val < x) current->right = add(current->right, x);
        else if(current->val > x) current->left = add(current->left, x);

        return current;
    }

    void print(node * current) {
        if(current != NULL) {
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

public: 

    bst() {
        root = NULL;
    }

    void add(int x) {
        node * res = add(root, x);
        if(root == NULL) root = res;
    }

    void print() {
        print(root);
    }

};

int main(){
    int n;
    bst b;
    cin >> n;
    while(n != 0){
        b.add(n);
        cin >> n;
    }
    b.print();
}