#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    // �Ž������� �׻� $5.00 ����
    // �մ��� �޴� ������ ������ �ּ�ȭ
    // e.g. $1.24 -> 4*0.25 + 2*0.10 + 0*0.05 + 4*0.01

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int change;
        cin >> change;

        cout << change/25 << " " << (change%25)/10
        << " " << ((change%25)%10)/5 << " " << change%5 << endl;
    }

    return 0;
}