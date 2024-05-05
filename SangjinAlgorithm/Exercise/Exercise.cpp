#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 8��
* ���� B : ���� ū �� �����
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