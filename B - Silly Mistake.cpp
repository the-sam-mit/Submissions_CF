
1253 B - Silly Mistake.cpp GNU C++14 Accepted
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


int main(){
    // testcase(T){
        int n;
        cin>>n;
        int a[n];
        inp0(a,n)
        set<int> st;
        map<int,int> mp;
        int cnt=0;
        vector<int> v;
        bool yes=true;
        rep(i,0,n-1){
            if(a[i]<0 && mp[-a[i]]!=1){
                yes=false;
                break;
            }
            if(a[i]>0 && mp[a[i]]!=0){
                if((sz(st)==0 && mp[a[i]]==2)){
                    if(cnt!=0) v.pb(cnt);
                    cnt=1;
                    st.in(a[i]);
                    mp.clear();
                    mp[a[i]]=1;
                }
                else{
                    yes=false;
                    break;
                }
            }
            if(a[i]>0 && mp[a[i]]==0){
                mp[a[i]]=1;
                // cout<<a[i]<<endl;
                st.in(a[i]);
                cnt++;
                // continue;
            }
            if(a[i]<0 && mp[-a[i]]==1){
                mp[-a[i]]=2;
                st.erase(-a[i]);
                cnt++;
                // continue;
            }
            if(sz(st)==0){
                mp.clear();
                if(cnt!=0) v.pb(cnt);
                cnt=0;
            }
        }
        if(sz(st)!=0) yes=false;
        else if(cnt!=0) v.pb(cnt);
        if(yes) {
            cout<<sz(v)<<endl;
            for(auto it:v) cout<<it<<" ";
        }
        else cout<<"-1\n";
    // }
}