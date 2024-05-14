#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 10��
* ���� C : ���� ���� ���� ã��
* �׺淹�̼����� Ǯ���
*   - �־��� ���� ���� ���� ���� ������ �Ǵ����� �˻��ϸ� ��.
*   - ���� Ȧ���̸� ������ �Ǵ� ���� ���� �� ����.
*/


bool FindSub(std::vector<int>& vec, int targetNum) {
    std::vector<bool> table(targetNum + 1, false);
    table[0] = true;

    for (int i = 0; i < targetNum; i++) {
        if (table[i]) {
            for (int x : vec) {
                if (i + x <= targetNum) table[i + x] = true;
            }
        }
    }

    return table[targetNum];
}


void TestCase() {
    int n{ 0 }, m{ 0 };
    std::cin >> n;


    std::vector<int> vec(n, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
        m += vec[i];
    }

    if (m % 2 == 1) {
        std::cout << "false\n";
        return;
    }

    std::cout << std::boolalpha << FindSub(vec, m / 2) << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t{ 0 };
    std::cin >> t;
    for (int i = 0; i < t; i++)
        TestCase();

    return 0;
}