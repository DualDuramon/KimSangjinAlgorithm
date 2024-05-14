#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 10장
* 문제 C : 합이 같은 분할 찾기
* 테뷸레이션으로 풀어보기
*   - 주어진 수를 전부 합한 값의 절반이 되는지를 검사하면 됨.
*   - 합이 홀수이면 절반이 되는 값을 만들 수 없음.
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