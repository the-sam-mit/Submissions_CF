
339 D - Xenia and Bit Operations.cpp GNU C++17 Accepted
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
                      cerr << "\n\n" << "Time elapsed: " << \
                      (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
                      return 0
#define testcase(t) int t;cin>>t;while(t--)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define PI 3.14159265358979323846
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 1000000007
#define sz(a) (int)a.size()
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
#define prll(x) printf("%lld",x)
#define nth_ele(v,n) nth_element(v.begin(), v.begin()+n ,v.end())//O(N)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2); else return n1;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return a*x*x;}return x*x;}
 
 
const ll INF=1e9; 
const int SIZE = 1e6+2;

void build(int tl, int tr, int tree[], int node, int a[], int x){
    // cout<<tl<<" "<<tr<<" "<<node<<" "<<x<<endl;
    if(tl==tr){
        tree[node] = a[tl];
        return;
    }
    int mid = (tl+tr)/2;
    build(tl, mid, tree, node*2, a, x+1);
    build(mid+1, tr, tree, (node*2)+1, a, x+1);
    if(x%2==0){
        tree[node] = tree[2*node] ^ tree[2*node+1];
    }
    else{
        tree[node] = tree[2*node] | tree[2*node+1];
    }
}

int query(int tree[]){
    return tree[1];
}

void update(int tree[], int tl, int tr, int pos, int new_val, int node, int x) {
    if (tl==tr) {
        tree[node] = new_val;
    }
    else{
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(tree, tl, tm, pos, new_val, node*2, x+1);
        else 
            update(tree, tm+1, tr, pos, new_val, node*2+1, x+1);
        if(x%2==0){
            tree[node] = tree[2*node] | tree[2*node+1];
        }
        else{
            tree[node] = tree[2*node] ^ tree[2*node+1];
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int szs=1<<n;
    int a[szs+1], tree[SIZE];
    mem(tree,0);
    rep(i,0,szs-1){
        cin>>a[i];
    }
    if(n%2==0) build(0,szs-1,tree,1,a,0);
    else       build(0,szs-1,tree,1,a,1); 
    
    rep(i,1,m){
        int p,b;
        cin>>p>>b;
        if(n%2==0) update(tree, 0, szs-1, p-1, b, 1, 1);
        else       update(tree, 0, szs-1, p-1, b, 1, 0);
        
        cout<<query(tree)<<endl;
        
    }
}