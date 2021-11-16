/*There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.
If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. 
Here, a cost of ∣hi−hj∣ is incurred, where j is the stone to land on.
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

int n, k;
int a[100001];
int dp[100001];

int rec(int level){
   int temp = 1e9;
   if(level == 0) return 0;
   else if(level < k){     
      for(int i=1; i <= level; i++){
         temp = min(temp, rec(level-i)+abs(a[level]-a[level-i]));
      }
   }
   else{
      for(int i=1; i<=k; i++){
         temp = min(temp, rec(level-i)+abs(a[level]-a[level-i]));
      }
   }
   return dp[level]= temp;
}

void solve(){
   cin >> n >> k;
   for(int i=0; i<n; i++){
      cin >> a[i];
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
