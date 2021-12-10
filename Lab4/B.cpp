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
        node * add(node * current, int x) {
            if(current == NULL) return new node(x);
            if(current->val < x) current->right = add(current->right, x);
            else if(current->val > x) current->left = add(current->left, x);
            return current;
        }

        void cnt(node * current) {
            if(current != NULL) {
                cnt(current->left);
                ans++;
                cnt(current->right);
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

        void count() {
            cnt(root);
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
    bs.count();
    cout << ans;
}