#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, sum = 0;
    cin >> n;

    for (int i = 2; i <= n; sum++) {
        i += 6*sum;
    }

    if (n == 1)
        sum = 1;


    cout << sum << endl;

    return 0;
}