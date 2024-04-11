#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 6장
* 문제 B : 두번째로 큰 값 찾기
* 토너먼트 배열(이진 힙 구조, 트리구조)을 거꾸로 올라가며 만들어가는 형식
* 반대자 전략 - 토너먼트 구조를 이용 해서 2등을 찾는 것.
* 자식노드들을 비교해 부모노드의 값을 정하면서 루트 노드까지 올라감 -> 인덱스는 2단위로 감소
* 루트노드(1등)이 정해지면 루트노드의 자식들을 비교해 루트노드 != 자식노드 인 값을 반환함.
*/

int FindSecondMax(std::vector<int>& vec) {

    std::vector<int> tourVec(2 * vec.size() - 1);   //토너먼트 배열

    for (int i = vec.size() - 1; i >= 0; i--) { //토너먼트 배열 끝에 vec 붙이기
        tourVec[vec.size() - 1 + i] = vec[i];
    }

    int idx = tourVec.size() - 1;
    int secondMax = INT_MIN;
   
    while (0 < idx) {
        tourVec[(idx - 2) / 2] = tourVec[idx - 1] < tourVec[idx] ? tourVec[idx] : tourVec[idx - 1];     //i번 인덱스의 자식 노드 : 2i+1, 2i+2
        
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