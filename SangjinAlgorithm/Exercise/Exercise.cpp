#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 10장
* 문제 D : 0/1 배낭문제
* 테뷸레이션으로 풀어보기
* 
*/
typedef std::pair<int, int> item;   // <가치, 크기>

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