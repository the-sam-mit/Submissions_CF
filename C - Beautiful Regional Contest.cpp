
1265 C - Beautiful Regional Contest.cpp GNU C++14 Accepted
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
#define M 998244353
#define sz(a) (int)a.size()
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
#define prll(x) printf("%lld",x)
#define nth_ele(v,n) nth_element(v.begin(), v.begin()+n ,v.end())//O(N)
#define DEBUG(x) cerr << (#x) << ": " << (x) << endl
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2);else return n1;}
ll powerM(ll a,ll b){if(b==0) return 1;  if(b==1) return a%M; ll x=powerM(a,b/2)%M; if(b&1){return ((((a%M)*(x%M))%M)*(x%M))%M;}return ((x%M)*(x%M))%M;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return ((((a)*(x)))*(x));}return ((x)*(x));}
 
const ll INF=1e18; 
const int SIZE = 200005;

int main(){
	testcase(T){
		int n;
		cin>>n;
		int a[n+1];
		inp1(a,n)
		map<int,int> cnt;
		rep(i,1,n){
			cnt[a[i]]++;
		}
// 		cout<<"N="<<n<<endl;
		vector<int> tot,aa;
		for(auto it:cnt){
		  //  if(cnt.count(it)){
			tot.pb(it.ss);
			aa.pb(it.ss);
		  //  }
		  //cout<<it.ff<<" "<<it.ss<<endl;
		}
		reverse(all(tot));
		reverse(all(aa));
		int nn = sz(tot);
		rep(i,1,nn-1){
			tot[i]+=tot[i-1];
// 			cout<<tot[i]<<endl;
		}
		int r=0;
		rep(i,0,nn-1){
			if(tot[i]<=n/2) r=i;
		}
		// cout<<r<<endl;
		int g=0,s=0,b=0;
		// nrep(i,0,r){
		int i=r;
			int bb=0, jj=i;
			while(aa[0]>=bb && jj>1){
				bb+=aa[jj];
				jj--;
			}
			if(aa[0]<tot[i]-aa[0]-bb    && aa[0]<bb && tot[i]<=(n/2)){
				g=aa[0];
				s=tot[i]-aa[0]-bb;
				b=bb;
				// break;
			}
		// }
		cout<<g<<" "<<s<<" "<<b<<endl;
	}
}