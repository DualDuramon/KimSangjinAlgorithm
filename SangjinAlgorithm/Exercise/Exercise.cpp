#include<iostream>
#include<vector>
#include<climits>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 6��
* ���� B : �ι�°�� ū �� ã��
* ��ʸ�Ʈ �迭(���� �� ����, Ʈ������)�� �Ųٷ� �ö󰡸� ������ ����
* �ݴ��� ���� - ��ʸ�Ʈ ������ �̿� �ؼ� 2���� ã�� ��.
* �ڽĳ����� ���� �θ����� ���� ���ϸ鼭 ��Ʈ ������ �ö� -> �ε����� 2������ ����
* ��ʸ�Ʈ�� �����ϸ鼭 2���� ���� ���� �����ϸ鼭 ����.
*/

int FindSecondMax(std::vector<int>& vec) {

    std::vector<int> tourVec(2 * vec.size() - 1, 0);   //��ʸ�Ʈ �迭

    for (int i = vec.size() - 1; i >= 0; i--) { //��ʸ�Ʈ �迭 ���� vec ���̱�
        tourVec[vec.size() - 1 + i] = vec[i];
    }

    int idx = tourVec.size() - 1;
    int secondMax = INT_MIN;
   
    while (0 < idx) {
        tourVec[(idx - 2) / 2] = std::max(tourVec[idx - 1], tourVec[idx]);
        if (tourVec[idx - 1] != tourVec[idx]) {//���� ���ϴ� �� ���� ���� ���� ��쿡�� 2�� ã�⸦ ����.
            if (tourVec[idx - 1] < tourVec[idx]) {
                secondMax = secondMax < tourVec[idx - 1] ? tourVec[idx - 1] : secondMax;
            }
            else {
                secondMax = secondMax < tourVec[idx] ? tourVec[idx] : secondMax;
            }
        }
        idx -= 2;
    }

    //2���� �������� ������ secondMax�� INT_MIN�� ������ �ְԵ�. ��� 1�� ��ȯ
    return secondMax == INT_MIN ? tourVec[0] : secondMax;
}

void TestCase() {
    int n = 0;
    std::cin >> n;

    std::vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    std::cout << FindSecondMax(vec) << "\n";

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