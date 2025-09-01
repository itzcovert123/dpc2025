#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int n) {
    int count = 0;
    int sqrtN = sqrt(n);

    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            if (i * i == n) count++;   
            else count += 2;         
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}
