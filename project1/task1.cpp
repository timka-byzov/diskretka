#include <bits/stdc++.h>

#define pii pair<int, int>
#define veci vector<int>
#define vecb vector<bool>
#define vecll vector<long long>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main() {

    int n; cin >> n;

    vecll one_dists(n + 1, 0), two_dists(n + 1, 0);

    one_dists[0] = 1;
    for (int i = 1; i <= n; i++){
        two_dists[i] += two_dists[i - 1];
        two_dists[i] += one_dists[i - 1];
        one_dists[i] += two_dists[i - 1];

    }

    cout << two_dists[n];

    return 0;
}
