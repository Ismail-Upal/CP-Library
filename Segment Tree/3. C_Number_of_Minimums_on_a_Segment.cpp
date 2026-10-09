// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B%C3%A2%C2%81%C2%A3

#include<bits/stdc++.h>
using namespace std;

#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
#define endl '\n'

struct Node{
    ll mn;
    ll cnt;
};

class SegTree{
private:
    ll n;
    vector<ll> v;
    vector<Node> tree;

    Node merge(const Node &a, const Node &b){
        if(a.mn < b.mn) return a;
        if(a.mn > b.mn) return b;
        return {a.mn, a.cnt + b.cnt};
    }

    void build(ll node, ll l, ll r){
        if(l == r){
            tree[node] = {v[l], 1};
            return;
        }
        ll left = 2 * node, right = 2 * node + 1;
        ll mid = (l + r) / 2;

        build(left, l, mid);
        build(right, mid + 1, r);
        
        tree[node] = merge(tree[left], tree[right]);
    }

    Node query(ll node, ll l, ll r, ll ql, ll qr){
        if(qr < l || r < ql) return {INT_MAX, 0};
        if(ql <= l && r <= qr) return tree[node];

        ll left = 2 * node, right = 2 * node + 1;
        ll mid = (l + r) / 2;
        
        return merge(query(left, l, mid, ql, qr), query(right, mid + 1, r, ql, qr));
    }

    void update(ll node, ll l, ll r, ll i, ll x){
        if(i < l || r < i) return;
        if(l == r){
            v[i] = x;
            tree[node] = {x, 1};
            return;                       
        }
        ll left = 2 * node, right = 2 * node + 1;
        ll mid = (l + r) / 2;

        update(left, l, mid, i, x);
        update(right, mid + 1, r, i, x);

        tree[node] = merge(tree[left], tree[right]);
    }

public:
    SegTree(const vector<ll> &input){
        v = input;
        n = (ll)v.size() - 1;
        tree.resize(4 * n + 4);
        build(1, 1, n);
    }

    void update(ll i, ll x){ update(1, 1, n, i, x); }
    Node query(ll l, ll r)   { return query(1, 1, n, l, r); }   
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
            Node ans = st.query(l, r);
            cout << ans.mn << " " << ans.cnt << endl;
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