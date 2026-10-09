#include<bits/stdc++.h>
using namespace std;

#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
#define endl '\n'

class SegTree{
private:
    ll n;
    vector<ll> v, tree;

    void build(ll node, ll l, ll r){
        if(l == r){
            tree[node] = v[l];
            return;
        }
        ll left = 2 * node, right = 2 * node + 1;
        ll mid = (l + r) / 2;
        build(left, l, mid);
        build(right, mid + 1, r);
        tree[node] = tree[left] + tree[right];
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];
        ll left = 2 * node, right = 2 * node + 1;
        ll mid = (l + r) / 2;
        return query(left, l, mid, ql, qr) + query(right, mid + 1, r, ql, qr);
    }

    void update(ll node, ll l, ll r, ll i, ll x){
        if(i < l || r < i) return;
        if(l == r){
            v[i] = x;
            tree[node] = x;
            return;                   
        }
        ll left = 2 * node, right = 2 * node + 1;
        ll mid = (l + r) / 2;
        update(left, l, mid, i, x);
        update(right, mid + 1, r, i, x);
        tree[node] = tree[left] + tree[right];
    }

public:
    SegTree(const vector<ll> &input){
        v = input;
        n = (ll)v.size() - 1;
        tree.assign(4 * n + 4, 0);
        build(1, 1, n);
    }

    void update(ll i, ll x){ update(1, 1, n, i, x); }
    ll query(ll l, ll r)   { return query(1, 1, n, l, r); }  
};

void Solve(){
    ll n, m; cin >> n >> m;
    vector<ll> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    SegTree st(v);

    while(m--){
        int q; cin >> q;
        if(q == 1){
            ll i, x; cin >> i >> x;
            i++;
            st.update(i, x);
        }
        else{
            ll l, r; cin >> l >> r;
            l++;
            cout << st.query(l, r) << endl;
        }
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) Solve();
    return 0;
}