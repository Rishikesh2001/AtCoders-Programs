/*There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.
If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi−hj|
is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define mod 1000000007
typedef long long int ll;
typedef long double ld;
using namespace std;

int n;
int h[100001];
int dp[100001];

int rec(int level){
   if(level == 0) return 0;
   if(level == 1) return abs(h[level] - h[level-1]);

   return dp[level]min(rec(level-1)+abs(h[level]-h[level-1]), rec(level-2)+abs(h[level]-h[level-2]));;
}

void solve(){
   cin >> n;
   for(int i=0; i<n; i++){
      cin >> h[i];
   }
   memset(dp, 0, sizeof(dp));
   cout << rec(n-1) <<"\n";
   // for(int i=0; i<n; i++){
   //    cout << dp[i] <<" ";
   // }
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}
