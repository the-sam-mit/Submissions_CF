
1271 F - Divide The Students.cpp GNU C++14 Accepted
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll n1, ll n2){if(n2!=0) return gcd(n2, n1%n2);else return n1;}
ll powerM(ll a,ll b){if(b==0) return 1;  if(b==1) return a%M; ll x=powerM(a,b/2)%M; if(b&1){return ((((a%M)*(x%M))%M)*(x%M))%M;}return ((x%M)*(x%M))%M;}
ll power(ll a,ll b){if(b==0) return 1;  if(b==1) return a; ll x=power(a,b/2); if(b&1){return ((((a)*(x)))*(x));}return ((x)*(x));}
 
const ll INF=1e18; 
const int SIZE = 5005;

vector<ll> adj[SIZE], insertV[SIZE];

multiset<ll> checkd;
int main(){
	// maths pro pe
	testcase(T){
		int a1,b1,c1,a2,b2,c2,d1,d2,d3,d4,d5,d6,d7;
		cin>>a1>>b1>>c1>>a2>>b2>>c2>>d1>>d2>>d3>>d4>>d5>>d6>>d7;
		int f1,f2,f3,f4,f5,f6,f7;
		bool flag=false;
		rep(i,0,d2){
			rep(j,0,d5){
				int ta1=a1,ta2=a2,tb1=b1,tb2=b2,tc1=c1,tc2=c2,td1=d1,td2=d2,td3=d3,td4=d4,td5=d5,td6=d6,td7=d7;
				ta1-=i;
				tb1-=i;
				tb1-=j;
				tc1-=j;
				ta2-=(td2-i);
				tb2-=(td2-i);
				tb2-=(td5-j);
				tc2-=(td5-j);
				if(ta1<0 || tb1<0 || ta2<0 || tb2<0 || tc1<0 || tc2<0 || td2<0 || td5<0) continue;
				int tt1=min(ta1,min(tb1,min(tc1,d1)));
				int tt2=min(ta2,min(tb2,min(tc2,d1-tt1)));
				if(tt1+tt2!=d1) continue;
				ta1-=tt1;
				tb1-=tt1;
				tc1-=tt1;
				ta2-=tt2;
				tb2-=tt2;
				tc2-=tt2;
				int td31=min(d3, min(ta1, tc1));
				int td32=min(d3-td31, min(ta2, tc2));
				ta1-=td31;
				ta2-=td32;
				tc1-=td31;
				tc2-=td32;
				if(td31+td32!=d3) continue;
				if((ta1+ta2)>=d4 && (tb1+tb2)>=d6 && (tc1+tc2)>=d7){
					f1=tt1;
					f2=i;
					f3=td31;
					f4=min(d4,ta1);
					f5=j;
					f6=min(d6,tb1);
					f7=min(d7,tc1);
					flag=true;
				}
			}
		}
		if(flag){
			cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<" "<<f5<<" "<<f6<<" "<<f7<<endl;
		}
		else cout<<"-1\n";
	}
}