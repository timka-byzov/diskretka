#include <bits/stdc++.h>

#define pii pair<int, int>
#define veci vector<int>
#define vecb vector<bool>
#define vecll vector<long long>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

vector<vecll> mPow(vector<vecll>& m, ll pow, ll p){
    int n = (int)m.size();
    int k = (int)m[0].size();
    pow--;

    vector<vecll> result = m;

    while(pow--){
        vector<vecll> temp_result = vector<vecll>(n, vecll(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int l = 0; l < k; l++){
                    temp_result[i][j] += (result[i][l] * m[l][j]) % p;
                    temp_result[i][j] %= p;
                }
            }
        }
        result = temp_result;
    }

    return result;

}

void solve(int n, int p){
    //ll n, p; cin >> n >> p;

    vector<vecll> m(2, vecll(2, 0));
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 1;

    auto t = mPow(m, n, p);

//    for (auto el1: t){
//        for (auto el2: el1){
//            cout << el2 << " ";
//        } cout << endl;
//    }

    cout << t[0][1] << endl;
}

int main() {

    for (int n = 1; n <= 1000; n++){
        solve(n, 1000);
    }

}

