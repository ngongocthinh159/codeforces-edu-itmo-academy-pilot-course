/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
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
 * For each index i of second array, we need to find right most an index j that a[0..j] < b[i] strictly
 * Suppose we have found j for b[i], then for b[i + 1] we just need to check from j (not from 0)
 * because two arrays are sorted
 */

int n, m;
const int mxn = 1e5 + 5;
int a[mxn];
int b[mxn];
void pre_compute() {
 
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<int> ans(m);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && a[j] < b[i]) j++;
        ans[i] = j;
    }
    for (auto x : ans) cout << x << " ";
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