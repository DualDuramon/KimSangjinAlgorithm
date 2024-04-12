#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 6��
* ���� C : wiggleSort
* �迭�� ������ ������ ������ �� �߾Ӱ����� ���� �κ��� high �κ�, ���� �κ��� low�κ��̶� �ϸ�
* low���� �ϳ�, high���� �ϳ� �����ؼ� ���ʴ�� �����. ������ �߾Ӱ��ʿ� �ߺ��� ���ڰ� ����������
* low���� �ߺ��� ���� ������ �ִ��� ������ �̰�, high���� �ߺ��� ���� ���� �� �ִ��� �ʰ� �̰� �ϱ� ����
* �� �� �� ������ ���������� �� �̱⸦ �����Ѵ�. �ߺ��� ���� low�������� ���κп�, high�������� ó�� �κп�
* �����Ǿ� �ֱ� �����̴�.
*/

void WiggleSort(std::vector<int>& vec) {

    std::vector<int> wiggle(vec);   //wiggle ����� �迭

    int left = (vec.size() - 1)/ 2; //���� ���ĵ� �迭�� �߾Ӻ��� ����
    int right = vec.size() - 1;     //���� ���ĵ� �迭�� ������ ����

    for (int i = 0; i < wiggle.size(); i++) {
        wiggle[i] = i % 2 == 0 ? vec[left--] : vec[right--];
    }

    std::cout << wiggle.size() << "\n";     //���
    for (int i : wiggle)
        std::cout << i << " ";
    std::cout << "\n";
}

void TestCase() {
    int n = 0;
    std::cin >> n;

    std::vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    WiggleSort(vec);
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