/*Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following
activities and do it on the i-th day:
A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.
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

int n;
int dp[100001][3];
int a[100001][3];

int rec(int level, int prev){
   // Base case
   if (level >= n) return 0;

   // Memoization
   if(dp[level][prev] != -1)
      return dp[level][prev];

   // Transitions
   int temp=0;
   for(int i=0; i<3; i++){
      if(i != prev)
         temp = max(temp, rec(level+1, i)+a[level][i]);
   }

   return dp[level][prev] = temp;
}

void solve(){
   cin >> n;
   for(int i=0; i<n; i++){
      for(int j=0; j<3; j++){
         cin >> a[i][j];
      }
   }
   memset(dp, -1);
   cout << rec(0, 3)<<"\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}
