#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

//O(n^2) 곱셈 알고리즘
vector<int> multiply(const vector<int> &a, const vector<int> &b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}

//a += b*(10^k)
void addTo(vector<int> &a, const vector<int> &b, int k){
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

//a -= b
void subFrom(vector<int> &a, const vector<int> &b){
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b){
    int an = a.size(), bn = b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    //크기가 작은경우 카라츠바 알고리즘을 사용하지 않고 구한다.
    if (an <= 50)
        return multiply(a, b);

    /*카라츠바 알고리즘
    ∴ z0 + ( z1 * 10^half ) + ( z2 * 10^(half*2) )
        z0 = a0 * b0
        z2 = a1 * b1
        z1 = (a0 + b1) * (b0 + b1) - z0 - z2
        a0 = a 앞부분 절반 b0 = b 앞부분 절반
        a1 = a 뒷부분 절반 b1 = b 뒷부분 절반
    */

    //a와 b를 절반으로 나눈다.
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0, 0);
    addTo(res, z1, half);
    addTo(res, z2, half * 2);

    return res;
}

int hugs(const string &members, const string &fans){
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++)
        A[i] = (members[i] == 'M');
    for (int i = 0; i < M; i++)
        B[M-i-1] = (fans[i] == 'M');

    vector<int> C = karatsuba(A, B);
    int allHugs = 0;

    //모든 멤버들이 펜을 만나기 시작한 시점부터
    for (int i = N - 1; i < M; i++)
        if (C[i] == 0)
            allHugs++;

    return allHugs;
}

int main(){
    fastio;

    int _;
    cin >> _;
    while (_--){
        string members, fans;
        cin >> members >> fans;
        cout << hugs(members, fans) << endl;
    }
    return 0;
}