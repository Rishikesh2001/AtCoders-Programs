/*Taro and Jiro will play the following game against each other.

Initially, they are given a sequence a=(a1,a2,…,aN). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:

Remove the element at the beginning or the end of a. The player earns x points, where x is the removed element.
Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize X−Y, while Jiro tries to minimize X−Y.

Assuming that the two players play optimally, find the resulting value of X−Y.*/
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

int n;
ll a[1001];
ll dp[1001][1001];

ll rec(int l, int r){
   if (l == r) return a[l];

   if(dp[l][r] != -1)
      return dp[l][r];

   ll ans = max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));
   return dp[l][r] = ans;
}

void solve(){
   cin >> n;
   for(int i=0; i<n; i++){
      cin >> a[i];
   }
   memset(dp, -1);
   cout << rec(0, n-1)<< "\n";
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
