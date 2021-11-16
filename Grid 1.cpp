/*There is a grid with H horizontal rows and W vertical columns.Let (i,j) denote
the square at the i-th row from the top and the j-th column from the left.

For each i and j (1≤i≤H, 1≤j≤W), Square(i,j) is described by a character a(i,j).
If a(i,j) ​is ".", Square (i,j) is an empty square; if a(i,j) is "#", Square (i,j)
is a wall square.It is guaranteed that Squares (1,1) and (H,W) are empty squares.

Taro will start from Square (1,1) and reach (H,W) by repeatedly moving right or down
to an adjacent empty square.
Find the number of Taro's paths from Square (1,1) to (H,W). As the answer can be
extremely large, find the count modulo 10^9+7.
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

int r, c;
char a[1001][1001];
int dp[1001][1001];

int recur(int i, int j){
   //Base case
   if(i ==0 && j == 0){
      return 1;
   }

   // Memoization
   if(dp[i][j] != -1) return dp[i][j];

   // Transitions
   if(a[i][j] == '#'){
      return dp[i][j] = 0;
   } else {
      if(i ==0){
         return dp[i][j] = recur(i, j-1);
      } else if(j == 0){
         return dp[i][j] = recur(i-1, j);
      } else{
         return dp[i][j] = recur(i-1, j) + recur(i, j-1);
      }
   } 
}

void solve(){
   cin >> r >> c;
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
         cin >> a[i][j];
      }
   }
   memset(dp, -1);
   cout << recur(r-1, c-1) << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}
