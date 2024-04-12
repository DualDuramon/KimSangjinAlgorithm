#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 6장
* 문제 C : wiggleSort
* 배열을 오름차 순으로 정렬한 후 중앙값보다 높은 부분을 high 부분, 낮은 부분을 low부분이라 하면
* low에서 하나, high에서 하나 선택해서 차례대로 출력함. 하지만 중앙값쪽에 중복된 숫자가 몰려있으면
* low에서 중복된 수를 뽑을땐 최대한 빠르게 뽑고, high에서 중복된 수를 뽑을 땐 최대한 늦게 뽑게 하기 위해
* 둘 다 각 영역의 끝에서부터 수 뽑기를 진행한다. 중복된 수가 low영역에선 끝부분에, high영역에선 처음 부분에
* 분포되어 있기 때문이다.
*/

void WiggleSort(std::vector<int>& vec) {

    std::vector<int> wiggle(vec);   //wiggle 만드는 배열

    int left = (vec.size() - 1)/ 2; //기존 정렬된 배열의 중앙부터 시작
    int right = vec.size() - 1;     //기존 정렬된 배열의 끝부터 시작

    for (int i = 0; i < wiggle.size(); i++) {
        wiggle[i] = i % 2 == 0 ? vec[left--] : vec[right--];
    }

    std::cout << wiggle.size() << "\n";     //출력
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