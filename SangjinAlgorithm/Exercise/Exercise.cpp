#include<iostream>
#include<vector>
#include<climits>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 6장
* 문제 B : 두번째로 큰 값 찾기
* 토너먼트 배열(이진 힙 구조, 트리구조)을 거꾸로 올라가며 만들어가는 형식
* 반대자 전략 - 토너먼트 구조를 이용 해서 2등을 찾는 것.
* 자식노드들을 비교해 부모노드의 값을 정하면서 루트 노드까지 올라감 -> 인덱스는 2단위로 감소
* 토너먼트를 진행하면서 2등의 값도 같이 저장하면서 진행.
*/

int FindSecondMax(std::vector<int>& vec) {

    std::vector<int> tourVec(2 * vec.size() - 1, 0);   //토너먼트 배열

    for (int i = vec.size() - 1; i >= 0; i--) { //토너먼트 배열 끝에 vec 붙이기
        tourVec[vec.size() - 1 + i] = vec[i];
    }

    int idx = tourVec.size() - 1;
    int secondMax = INT_MIN;
   
    while (0 < idx) {
        tourVec[(idx - 2) / 2] = std::max(tourVec[idx - 1], tourVec[idx]);
        if (tourVec[idx - 1] != tourVec[idx]) {//서로 비교하는 두 수가 같지 않을 경우에만 2등 찾기를 진행.
            if (tourVec[idx - 1] < tourVec[idx]) {
                secondMax = secondMax < tourVec[idx - 1] ? tourVec[idx - 1] : secondMax;
            }
            else {
                secondMax = secondMax < tourVec[idx] ? tourVec[idx] : secondMax;
            }
        }
        idx -= 2;
    }

    //2등이 정해지지 않으면 secondMax는 INT_MIN을 가지고 있게됨. 고로 1등 반환
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