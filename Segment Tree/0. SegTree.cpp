#include<bits/stdc++.h>
using namespace std;

class SegTree{
private:
    int n;
    vector<int> tree, v;

    void build(int node, int l, int r){ // O(n)
        if(l == r){
            tree[node] = v[l];
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) >> 1;

        build(left, l, mid);
        build(right, mid + 1, r);

        tree[node] = max(tree[left], tree[right]); // change this
    }

    void update(int node, int l, int r, int i, int x){ // O(log n)
        if(i < l or r < i) return;
        if(l == r and l == i){
            v[i] = x;
            tree[node] = x; // update
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) >> 1;

        update(left, l, mid, i, x);
        update(right, mid + 1, r, i, x);

        tree[node] = max(tree[left], tree[right]); // change this
    }

    int query(int node, int l, int r, int ql, int qr){ // O(log n)
        if(qr < l or r < ql) return INT_MIN; // return appropriate value
        if(ql <= l and r <= qr) return tree[node];

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) >> 1;

        return max(query(left, l, mid, ql, qr), query(right, mid + 1, r, ql, qr)); // change this
    }

public:
    SegTree(const vector<int> &input){
        v = input;
        n = (int)v.size() - 1;
        tree.assign(4 * n + 5, 0);
        build(1, 1, n); 
    }

    void update(int i, int x){ 
        update(1, 1, n, i, x); 
    }
    int query(int l, int r){ 
        return query(1, 1, n, l, r); 
    }
};


int main()
{   
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    SegTree st(v);

    st.update(2, 10); // assigning : a[2] = 10 , O(log n)
    cout << st.query(1, 5) << endl; // range max query on segment [1, 5] , O(log n) 

    return 0;
}
