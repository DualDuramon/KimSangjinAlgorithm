#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 8장
* 문제 A : 마감시간이 있는 최적의 스케쥴 짜기
* 
* 
*/

//typedef std::pair<int, int> work;   //work = pair<이득, 종료시간>

struct work {
    int id = 0;
    int benefit = 0;
    int endTime = 0;

    bool operator<(const work& w) {
        if (endTime == w.endTime)
            return id < w.id;
        else
            return endTime < w.endTime;
    }
};

bool isPossible(std::vector<work>& k) {
    std::sort(k.begin(), k.end());

    for (int idx = 0; idx < k.size() - 1; idx++) {
        if (k[idx].endTime >= k[idx + 1].endTime) return false;
    }

    return true;
}


void scheduling(std::vector<work>& vec) {
    std::vector<work> schedule;

    schedule.push_back(vec[0]);

    for (int i = 1; i < vec.size(); i++) {
        std::vector<work> k = schedule;
        k.push_back(vec[i]);
        if (isPossible(k)) schedule = k;
    }

    for (auto& k : schedule)
        std::cout << k.id << " ";
    std::cout << "\n";

}

void TestCase() {
    int n{ 0 };
    std::cin >> n;

    std::vector<work>vec(n);

    for (int i = 0; i < n; i++) {
        vec[i].id = i + 1;
        std::cin >> vec[i].endTime >> vec[i].benefit;
    }

    std::sort(vec.begin(), vec.end(), [](work a, work b) { return a.benefit > b.benefit; });


    scheduling(vec);

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