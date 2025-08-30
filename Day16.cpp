#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long n, long long m) {
    long long g = gcd(n, m);
    return (n / g) * m;  
}

int main() {
    long long N, M;
    cin >> N >> M;

    cout << lcm(N, M) << endl;
    return 0;
}
