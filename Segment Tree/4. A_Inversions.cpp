#include<bits/stdc++.h>
using namespace std;

#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
#define endl '\n'
#define sz(x) (ll)(x).size()

class SegTree{
private:
    int n;
    vector<int> v, tree;

    int query(int node, int l, int r, int ql, int qr){
        if(qr < l or r < ql) return 0;
        if(ql <= l and r <= qr){
            return tree[node];
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) / 2;

        return query(left, l, mid, ql, qr) + query(right, mid + 1, r, ql, qr);
    }
    void update(int node, int l, int r, int i, int x){
        if(i < l or r < i) return;
        if(l == r and l == i){
            v[i] = x;
            tree[node] = x;
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) / 2;

        update(left, l, mid, i, x);
        update(right, mid + 1, r, i, x);

        tree[node] = tree[left] + tree[right];
    }

public:
    SegTree(int Size){
        n = Size - 1;
        v.assign(Size, 0);
        tree.assign(4 * n + 3, 0);
    }

    void add(int i){
        update(1, 1, n, i, 1);
    }
    int get(int l, int r){
        return query(1, 1, n, l, r);
    }
};

void Solve(){
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    SegTree st(n + 1);

    for(int i = 1; i <= n; i++){
        cout << st.get(v[i] + 1, n) << " ";
        st.add(v[i]);
    }
}

int main()
{   
    fast;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        Solve();
    }
    
    return 0;
}


// dynamic queries
