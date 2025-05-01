/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

#define nline '\n'
#define ll long long
#define MOD 1000000007
#define MOD1 998244353
#define LINF ((long long)1e18)
#define IINF ((int)1e9)

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void IN_OUT() {
#ifndef ONLINE_JUDGE
freopen("Input.txt", "r", stdin);
freopen("Output.txt", "w", stdout);
#endif
}
/*--------------------------------------------------------------------------------------------------------------------------*/

/** Editorial
 * Use sliding window technique with two pointers l and r
 * Maintaining the sum of current window [l..r], if add new element r to the window
 * make the sum exceeds threshold, then shrink the window by remove the l element
 * For current fixed r, find the left most l satisfy sum of segment [l..r] <= threshold
 * then all left pointers from l -> r will also satisfy the threshold
 * 
 * Suppose we already know optimal l for r, then with r + 1 we only need to search from l (not from 0)
 * this is due to the monotone of the sum (larger segment has larger sum)
 * => suppose l is invalid for r + 1, then try to increase l until valid again
 */

ll n, s;
const int mxn = 1e5 + 5;
ll a[mxn];
void pre_compute() {
 
}
void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    int ans = 0;
    for (int r = 0, l = 0; r < n; r++) {
        sum += a[r];
 
        while (sum > s) {
            sum -= a[l++];
        }

        ans = max(ans, r - l + 1);
    }
    cout << ans << nline;
}

int main() {
    fastio();
    IN_OUT();
    int T = 1;
    // cin >> T;
    pre_compute();
    for (int cases = 1; cases <= T; cases++) {

        solve();
    }
    return 0;
}