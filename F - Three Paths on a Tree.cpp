
1294 F - Three Paths on a Tree.cpp GNU C++14 Accepted
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
#define UNIQUE(x) x.resize(distance(x.begin(), unique(all(x))))
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
#define prll(x) printf("%lld",x)
#define nth_ele(v,n) nth_element(v.begin(), v.begin()+n ,v.end())//O(N)
#define DEBUG(x) cerr << (#x) << ": " << (x) << endl
#define DEBUGV(x) for(auto IT:x) cout<<IT<<" "; cout<<endl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2);else return n1;}
ll powerM(ll a,ll b){if(b==0) return 1;  if(b==1) return a%M; ll x=powerM(a,b/2)%M; if(b&1){return ((((a%M)*(x%M))%M)*(x%M))%M;}return ((x%M)*(x%M))%M;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return ((((a)*(x)))*(x));}return ((x)*(x));}
 
const ll INF=1e18; 
const int SIZE = 200005;
 
vector<int> v[SIZE];
int vis[SIZE], lvl[SIZE];
 
// int spcl[SIZE];
 
void dfs(int x){
    vis[x]=1;
    for(auto it:v[x]){
        if(!vis[it]){
            lvl[it] = lvl[x]+1;
            dfs(it);
        }
    }
}
 
int ans=0;
 
set<int> spt;
 
int parent[SIZE];

void DFS(int x, int y){
    vis[x]=1;
    if(x==y){
        vis[y]=1;
        // parent[y]=par;
        return;
    }
    for(auto it:v[x]){
        if(!vis[it]){
            parent[it]=x;            
            DFS(it, y);
        }
    }
}

void f_parent(int x){
    spt.in(x);
    while(parent[x]!=-1){
        spt.in(x);
        ans++;
        x = parent[x];
    }
}

int main(){
    int n, a, b, c;
    cin>>n;
    rep(i,1,n-1){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    mem(lvl, 0);
    mem(vis, 0);
    dfs(0);
    int mx=-1, ind=0;
    rep(i,0,n-1){
        if(mx<lvl[i]){
            mx = lvl[i];
            ind = i;
        }
    }
    a = ind;
    mem(vis, 0);
    mem(lvl, 0);
    dfs(a);
    mx=-1;
    ind=0;
    
    rep(i,0,n-1){
        if(mx<lvl[i]){
            mx = lvl[i];
            ind = i;
        }
    }
    b = ind;
    mem(vis, 0);
    mem(lvl, 0);
    mem(parent, 0);
    parent[a]=-1;
    parent[b]=-1;
    spt.in(a);
    spt.in(b);
    DFS(a, b);
    f_parent(b);
    queue<int> qq;
    mem(vis, 0);
    mem(lvl, 0);
    rep(i,0,n-1){
        if(spt.find(i)!=spt.end()){ 
            qq.push(i);
            vis[i]=1;
            lvl[i]=0;
            // cout<<i<<endl;
        }
    }
 
    while(!qq.empty()){
        int xx = qq.front();
        qq.pop();
        vis[xx]=1;
        for(auto itt:v[xx]){
            if(!vis[itt]){
                vis[itt]=1;
                qq.push(itt);
                lvl[itt]=lvl[xx]+1;
            }
        }
    }
// ll
    mx=-1;
    rep(i,0,n-1){
        // cout<<lvl[i]<<endl;
        if(i!=a && i!=b){
            if(mx<lvl[i]){
                mx = lvl[i];
                c=i;
            }
        }
    }
    // cout<<ans<<endl;
    cout<<ans+lvl[c]<<endl;
    cout<<a+1<<" "<<b+1<<" "<<c+1<<endl;
}