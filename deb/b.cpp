#include<iostream>
#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define sort(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define uniq(v) sort(v); v.resize(unique(v.begin(), v.end())-v.begin());
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<int,int>>
#define mod 1000000007
const int huge = 1e17;
               
                
int max(int a,int b){ if(a>b) return a; return b; }
int min(int a,int b){ if(a<b) return a; return b; }
int abbs(int a,int b){   if(a-b < 0) return b-a; return a-b; }
 
 
int lowerB(vi &v, int val){
int ind=v.size(),l=0,r=v.size(),mid;while(l<=r){mid=(l+r)/2;if(v[mid]>=val){ind=mid;r=mid-1;}else l=mid+1;}return ind;
}
 
 
 
void solve(){
  int x; cin>>x;
  vp v = {{0, 1}, {1, 2}, {2, 1}};
  vi ans(3);
  int ind = 0;
  for(int bit = 0; bit<=40; bit++) {
      if((1ll << bit) >= (x + 10)) break; 
      if(x & (1ll << bit)) {
          // 2 1s
        if(ind >= 3) ind = 0;
        int fr = v[ind].first, sc = v[ind].second; 
        ans[fr]+=(1ll << bit); ans[sc]+=(1ll << bit); 
        ind++; 
      }
      else{
          //2 0's
        if(ind >= 3) ind = 0;
        int fr = v[ind].first, sc = v[ind].second; 
        foo(k, 3) {
            if(k!=fr && k!=sc) {
                ans[k]+=(1ll << bit);
            }
        }
        ind++;
      }
  }
  int verify = (ans[0]|ans[1]) & (ans[1] | ans[2]) & (ans[2] | ans[0]);
  //cout<<verify<<"...\n";
  cout<<3;
  cout<<'\n';
} 
      
      
signed main(){
   ok
   int t;
   t = 1;
   cin>>t;
     while(t--){
      solve();
    }
}