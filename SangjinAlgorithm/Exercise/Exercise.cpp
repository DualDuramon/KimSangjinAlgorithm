#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 8장
* 문제 B : 가장 큰 수 만들기
* 
*/
std::string MaxNumber(std::vector<string>& nums) {
    string ans = "";
    
    for (auto str : nums) {
        ans += str;
    }

    return ans;
}



void TestCase() {
    int n = 0;
    std::cin >> n;

    std::vector<string> nums(n);

    for (int i = 0; i < n; i++) 
        std::cin >> nums[i];

    std::sort(nums.begin(), nums.end());

    //std::cout << MaxNumber(nums) << "\n";
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