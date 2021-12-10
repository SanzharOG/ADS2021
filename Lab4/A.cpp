#include <iostream>
using namespace std;

int ans = 0;

struct node {
    int val;
    node * right;
    node * left;
    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst {
    private: 
        node * root;
        node * add(node * current, int x, int cnt) {
            if(cnt > ans) ans = cnt;
            if(current == NULL) return new node(x);
            if(current->val < x) current->right = add(current->right, x, ++cnt);
            else if(current->val > x) current->left = add(current->left, x, ++cnt);
            return current;
        }

    public: 

        bst() {
            root = NULL;
        }

        void add(int x) {
            node * res = add(root, x, 1);
            if(root == NULL) root = res;
        }
};

int main(){
    int n;
    bst bs;
    cin >> n;
    while(n != 0) {
        bs.add(n);
        cin >> n;
    }
    cout << ans;
}