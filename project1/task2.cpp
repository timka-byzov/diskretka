#include <bits/stdc++.h>

#define pii pair<int, int>
#define veci vector<int>
#define vecb vector<bool>
#define vecll vector<long long>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;


map<int, vector<vecll>> pow_cache;


vector<vecll > mMult(vector<vecll > &a, vector<vecll > &b, ll p) {
    vector<vecll > temp_result = vector<vecll >(2, vecll(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l < 2; l++) {
                temp_result[i][j] += (a[i][l] * b[l][j]) % p;
                temp_result[i][j] %= p;
            }
        }
    }
    return temp_result;

}

vector<vecll > mPow(vector<vecll > &m, ll pow, ll p) {
    if (pow == 1) {
        return m;
    }
    if (pow % 2 == 0) {
        auto t = mPow(m, pow / 2, p);
        return mMult(t, t, p);
    } else {
        auto t = mPow(m, pow - 1, p);
        return mMult(t, m, p);
    }

}


void solve() {
    ll n, p;
    cin >> n >> p;

    vector<vecll > m(2, vecll(2, 0));
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 1;

    auto t = mPow(m, n, p);

//    for (auto el1: t) {
//        for (auto el2: el1) {
//            cout << el2 << " ";
//        }
//        cout << endl;
//    }

    cout << t[0][1] % p << endl;
}

int main() {
    solve();
    return 0;

}

