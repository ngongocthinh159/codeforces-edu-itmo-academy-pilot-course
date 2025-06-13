/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

#define nline '\n'
#define ll long long
#define MOD 1000000007
#define MOD1 998244353
#define LINF ((long long)1e18)
#define IINF ((int)1e9)
#define MASK(i) (1LL << (i))

template<class X, class Y>
bool minimize(X &x, const Y &y) {
    if (x > y) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void IN_OUT() {
#ifndef ONLINE_JUDGE
freopen("Input.txt", "r", stdin);
freopen("Output.txt", "w", stdout);
#endif
}
struct chash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}}; // https://codeforces.com/blog/entry/62393
struct chashp {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(pair<uint64_t,uint64_t> x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);}}; // https://codeforces.com/blog/entry/62393
/*--------------------------------------------------------------------------------------------------------------------------*/

/** Editorial
 * Apply binary search on answer to maintain variant on piece length: [TTTTFFFF] => find last true (l pointer)
 * For each piece length candidate count the number of pieces can be created across all ropes
 * If piece count >= k meaning we can use this piece length candidate, hence shrink search space by set l = m, otherwise r = m
 */
void pre_compute() {
    
}
void solve() {
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    double l = 0, r = 1e7 + 1;
    for (int i = 0; i < 100; i++) {
        double m = l + (r - l)/2;
        int cnt = 0;
        for (int j = 0; j < n; j++) cnt += a[j] / m;
        if (cnt >= k)
            l = m;
        else
            r = m;
    }
    printf("%.8f\n", l);
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