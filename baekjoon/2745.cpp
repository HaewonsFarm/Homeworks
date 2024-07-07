#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string n;  // b���� �� n
    int b, sum = 0;
    cin >> n >> b;

    for (int i = 0; i < n.length(); i++) {

        char digit = n[n.length() - 1 - i];
        // ���ڿ��� �������� ó�� -> �� ��Ű�� 9���� ���Ͽ��� ���� ���� �߻�


        if (digit >= '0' && digit <= '9') {
            sum += (digit - '0') * pow(b, i);
        } else {
            sum += (digit - 'A' + 10) * pow(b, i);
        }
    }

    cout << sum;

    return 0;
}