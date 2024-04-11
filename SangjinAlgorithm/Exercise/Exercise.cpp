#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 6��
* ���� B : �ι�°�� ū �� ã��
* ��ʸ�Ʈ �迭(���� �� ����, Ʈ������)�� �Ųٷ� �ö󰡸� ������ ����
* �ݴ��� ���� - ��ʸ�Ʈ ������ �̿� �ؼ� 2���� ã�� ��.
* �ڽĳ����� ���� �θ����� ���� ���ϸ鼭 ��Ʈ ������ �ö� -> �ε����� 2������ ����
* ��Ʈ���(1��)�� �������� ��Ʈ����� �ڽĵ��� ���� ��Ʈ��� != �ڽĳ�� �� ���� ��ȯ��.
*/

int FindSecondMax(std::vector<int>& vec) {

    std::vector<int> tourVec(2 * vec.size() - 1);   //��ʸ�Ʈ �迭

    for (int i = vec.size() - 1; i >= 0; i--) { //��ʸ�Ʈ �迭 ���� vec ���̱�
        tourVec[vec.size() - 1 + i] = vec[i];
    }

    int idx = tourVec.size() - 1;
    int secondMax = INT_MIN;
   
    while (0 < idx) {
        tourVec[(idx - 2) / 2] = tourVec[idx - 1] < tourVec[idx] ? tourVec[idx] : tourVec[idx - 1];     //i�� �ε����� �ڽ� ��� : 2i+1, 2i+2
        
        idx -= 2;
    }


    

    return tourVec[0];
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