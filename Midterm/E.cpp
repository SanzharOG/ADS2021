#include <iostream>

using namespace std;

struct node {
    int v;
    node *less;
    node *more;
    node(int x) {
        v = x;
        less = NULL;
        more = NULL;
    }
};

int ans;

node* add(node *n, int v) {
    if (n == NULL) {
        n = new node(v);
        return new node(v);
    }
    if (v > n->v) {
        if (n->more == NULL) {
            n->more = add(n->more, v);
            return n->more;
        }
        else {
            return add(n->more, v);
        }
    }
    else {
        if (n->less == NULL) {
            n->less = add(n->less, v);
            return n->less;
        }
        else {
            return add(n->less, v);
        }
    }
}

void tri(node* n, int k) {

    if (n == NULL) return;

    node *left = n, *right = n;
    ans++;
    for (int i = 0; i < k; i++) {
        if (left->less == NULL || right->more == NULL) {
            ans--;
            break;
        }

        left = left->less;
        right = right->more;
    }

    tri(n->less, k);
    tri(n->more, k);
}

int main() {
    int n, v;

    cin >> n;

    node *heap = NULL;

    cin >> v;

    heap = add(heap, v);

    for (int i = 1; i < n; i++) {
        cin >> v;

        add(heap, v);
    }

    for (int i = 1; i < n; i++) {
        ans = 0;
        tri(heap, i);

        cout << ans << " ";
    }

    return 0;
}




