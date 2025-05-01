/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
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
/*----------------------------------------------- ---------------------------------------------------------------------------*/

/** Editorial
 * The solution is the same as the merging step of merge sort algorithm
 * Keep two pointer i and j in first and second array (a and b)
 * When the element a[i] <= b[j] move a[i] to result array otherwise move b[j]
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
    vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) c[k] = a[i], k++, i++;
        else c[k] = b[j], k++, j++;
    }
    while (i < n) c[k] = a[i], i++, k++;
    while (j < m) c[k] = b[j], j++, k++;
    for (auto x : c) cout << x << " ";
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
