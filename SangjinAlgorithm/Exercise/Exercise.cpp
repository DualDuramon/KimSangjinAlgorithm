#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 10��
* ���� D : 0/1 �賶����
* �׺淹�̼����� Ǯ���
* 
*/
typedef std::pair<int, int> item;   // <��ġ, ũ��>

int Knapsack(std::vector<item>& items, int maxWeight) {

    std::vector<std::vector<int>>table(items.size() + 1, std::vector<int>(maxWeight + 1, 0));

    for (int i = 0; i < items.size(); i++) {
        for (int x = 1; x <= maxWeight; x++) {
            if (items[i].second > x) table[i + 1][x] = table[i][x];
            else {
                table[i+1][x] = std::max(table[i][x], table[i][x - items[i].second] + items[i].first);
            }
        }
    }

    return table[items.size()][maxWeight];
}


void TestCase() {
    int w{ 0 }, n{ 0 };
    std::cin >> w >> n;

    std::vector<item> items(n);

    for (int i = 0; i < n; i++) {
        auto& [val, weight] = items[i];
        std::cin >> val >> weight;
    }

    int ans = Knapsack(items, w);
    std::cout << ans << "\n";
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