#include<iostream>
#include<vector>

using namespace std;

void SelectionSort() {
    int n = 8;
    std::vector<int> vec = std::vector<int>{ 5,4,1,8,7,2,6,3 };

    for (int i = 0; i < vec.size() - 1; i++) {
        int minLoc = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[minLoc] > vec[j]) {
                minLoc = j;
            }
            if (minLoc != i)
                std::swap(vec[minLoc], vec[i]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    SelectionSort();
    
    return 0;
}