// https://cses.fi/problemset/task/1144/
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

    void update(int node, int l, int r, int i, int del){
        if(i < l or r < i) return;
        if(l == r and l == i){
            tree[node] += del;
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) >> 1;

        update(left, l, mid, i, del);
        update(right, mid + 1, r, i, del);

        tree[node] = tree[left] + tree[right]; 
    }

    int query(int node, int l, int r, int ql, int qr){ 
        if(qr < l or r < ql) return 0;
        if(ql <= l and r <= qr) return tree[node];

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (l + r) >> 1;

        return query(left, l, mid, ql, qr) + query(right, mid + 1, r, ql, qr);
    }

public:
    SegTree(int sz){
        n = sz;
        tree.assign(4 * n + 4, 0);
    }

    void add(int i, int del){
        update(1, 1, n, i, del);
    }

    int query(int l, int r){
        return query(1, 1, n, l, r);
    }
};

void Solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<tuple<char, int, int>> query;
    vector<int> val;

    for(int i = 1; i <= n; i++) val.push_back(v[i]);

    for(int i = 0; i < q; i++){
        char t; cin >> t;
        if(t == '!'){
            int k, x; cin >> k >> x;
            query.push_back({t, k, x});
            val.push_back(x);
        }
        else{
            int a, b; cin >> a >> b;
            query.push_back({t, a, b});
            val.push_back(a);
            val.push_back(b);
        }
    }


    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    auto getId = [&](int x){
        return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
    };


    int mxSz = sz(val);
    SegTree st(mxSz);

    for(int i = 1; i <= n; i++){
        int newId = getId(v[i]);
        st.add(newId, 1);
    }

    for(auto [t, a, b] : query){
        if(t == '!'){
            int k = a, x = b;
            
            int oldId = getId(v[k]);
            st.add(oldId, -1);

            int newId = getId(x);
            st.add(newId, 1);

            v[k] = x;
        }
        else{
            int l = getId(a);
            int r = getId(b);

            cout << st.query(l, r) << endl;
        }
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

// concept : 𝐜𝐨𝐨𝐫𝐝𝐢𝐧𝐚𝐭𝐞 𝐜𝐨𝐦𝐩𝐫𝐞𝐬𝐬𝐢𝐨𝐧 𝐰𝐢𝐭𝐡 𝐒𝐞𝐠𝐦𝐞𝐧𝐭 𝐓𝐫𝐞𝐞𝐬⁣
// using : map , vector + BS


