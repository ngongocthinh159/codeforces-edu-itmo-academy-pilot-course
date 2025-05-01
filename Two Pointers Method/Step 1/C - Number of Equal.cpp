/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
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
 * For each X existed in both first and second array, find two indice i and j
 * that are the first occurence of X in two arrays
 * Call cnt1 and cnt2 are occurence times of X in two arrays respectively
 * Then X will contribute cnt1*cnt2 to final answer
 */

const int mxN = 1e5 + 5;
int n, m;
int a[mxN];
int b[mxN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    ll ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else {
            int cnt1 = 0, cnt2 = 0, cur = a[i];
            while (i < n && a[i] == cur) {
                cnt1++;
                i++; 
            }
            while (j < m && b[j] == cur) {
                cnt2++;
                j++; 
            }
            ans += 1LL*cnt1*cnt2;
        }
    }
    cout << ans << "\n";
}

int main() {
    fastio();
    IN_OUT();
    int T = 1;
    // cin >> T;
    for (int cases = 1; cases <= T; cases++) {

        solve();
    }
    return 0;
}