#include <iostream>

using namespace std;

int arr[100][100];  // ���� ����: �迭�� �ڵ� 0���� �ʱ�ȭ
int main() {
    ios_base::sync_with_stdio(false);

    int n, x, y, count = 0;
    cin >> n;

    while(n--) {
        cin >> x >> y;

        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                if (!arr[i][j]) {
                    count++;
                    arr[i][j] = 1;
                }
            }
        }
    }

    cout << count;

    return 0;
}