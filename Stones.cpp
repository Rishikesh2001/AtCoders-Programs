/*There is a set A={a1,a2,…,aN} consisting of N positive integers. Taro and Jiro
will play the following game against each other.

Initially, we have a pile consisting of K stones. The two players perform the following
operation alternately, starting from Taro:
   ==>Choose an element x in A, and remove exactly x stones from the pile.

A player loses when he becomes unable to play. Assuming that both players play optimally,
determine the winner.   
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define memset(x, value) memset(x, value, sizeof(x))
#define mod 1000000007
typedef long long int ll;
typedef long double ld;
using namespace std;

int n, k;
int a[101];
int dp[100100][101];

int recur(int k, int p){
   // Pruning
   if (n == 1){
      if(k%(a[0]+1) == 0) return 0;
      else return 1;
   }

   // Base case
   if(k == 0 || k < a[0]){
      if(p == 1) return 0;
      else return 1;
   } 

   // Memoization
   if(dp[k][p] != -1) return dp[k][p];

   // Transitions
   for(int i=0; i<n; i++){
      if(k >= a[i]){
         if(recur(k-a[i], !p) == p){
            return dp[k][p] = p;
         }
      }
   }
   return dp[k][p] = !p;
}

void solve(){
   cin >> n >> k;
   for(int i=0; i<n; i++){
      cin >> a[i];
   }

   memset(dp, -1);
   recur(k, 1) ? cout << "First\n": cout << "Second\n"; 
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}
