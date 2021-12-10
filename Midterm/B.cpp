#include <iostream>

using namespace std;

void swap(long* a, long f, long s) {
    int t = a[f];
    a[f] = a[s];
    a[s] = t;
}


long long sift_down(long* heap, long key, long n) {
    long long l = key * 2, r = key * 2 + 1;

    if (l > n) l = key;
    if (r > n) r = key;

    while (key < n && (heap[key] > heap[l] || heap[key] > heap[r])) {
        long long c = l;

        if (heap[l] > heap[r]) {
            c = r;
        }

        swap(heap, key, c);

        key = c;

        l = key * 2;
        r = key * 2 + 1;

        if (l > n) l = key;
        if (r > n) r = key;
    }

    return key;
}

void build_heap2(long* heap, long heap_size) {
    for (long long i = heap_size / 2; i > 0; i--) {
        sift_down(heap, i, heap_size);
    }
}

int main() {
    int n, heap_size;

    cin >> n;
    heap_size = n;
    
    long* heap = new long[n + 1];

    for (int i = 1; i < n + 1; i++)
        cin >> heap[i];

    build_heap2(heap, heap_size);


    long long ans = 0;
    while (heap_size > 1) {

    int min_ind = 2;
    if (heap_size > 2 && heap[3] < heap[min_ind]) min_ind = 3;

    heap[1] = heap[1] + heap[min_ind];
    ans += heap[1];

    if (min_ind != heap_size) {
heap[min_ind] = heap[heap_size];
}
else {
min_ind = 2;
}

heap_size--;
sift_down(heap, 1, heap_size);
sift_down(heap, min_ind, heap_size);
sift_down(heap, 1, heap_size);
}

cout << ans;

return 0;
}