#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 7장
* 문제 C : 최적의 변환 순서 찾기
* BFS를 사용하는 문제
*/

int compareTwoWord(string& str1, string& str2) {
    int counter = 0;
    for (size_t idx = 0; idx < str1.size() && counter < 2; idx++) {
        if (str1[idx] != str2[idx]) counter++;
    }

    return counter;
}

void findShortcutWord(std::vector<string>& dictionary, string& word, int destWordIdx) {
    std::vector<bool> visited(dictionary.size(), false);
    std::vector<int> dist(dictionary.size(), INT_MAX);
    std::queue<int> queue;

    queue.push(destWordIdx);
    dist[destWordIdx] = 0;
    visited[destWordIdx] = true;

    int counter = compareTwoWord(dictionary[destWordIdx], word);
    if (counter == 1) {
        std::cout << dist[destWordIdx] + 1 << "\n";
        return;
    }
    else if (counter == 0) {
        std::cout << dist[destWordIdx] << "\n";
        return;
    }


    while (!queue.empty()) {
        int nowNode = queue.front();
        queue.pop();

        for (size_t i = 0; i < dictionary.size(); i++) {
            if (!visited[i] && compareTwoWord(dictionary[nowNode], dictionary[i]) == 1) {

                dist[i] = dist[nowNode] + 1;

                int counter = compareTwoWord(dictionary[i], word);
                if (counter == 1) {
                    std::cout << dist[i] + 1 << "\n";
                    return;
                }
                else if (counter == 0) {
                    std::cout << dist[i] << "\n";
                    return;
                }

                visited[i] = true;
                queue.push(i);
            }
        }
    }

    std::cout << -1 << "\n";
}


void TestCase() {
    int dictSize = 0;
    string word = "", destWord = "";
    std::cin >> word >> destWord >> dictSize;

    std::vector<string>dictionary(dictSize);


    //단어배열 생성
    for (size_t i = 0; i < dictionary.size(); i++) {
        std::cin >> dictionary[i];
    }

    int destWordIdx = -1;
    for (size_t idx = 0; idx < dictionary.size(); idx++) {
        if (dictionary[idx] == destWord) {
            destWordIdx = idx;
            break;
        }
    }

    if (destWordIdx == -1) { //끝단어가 사전에 없을 경우
        std::cout << -1 << "\n";
        return;
    }


    findShortcutWord(dictionary, word, destWordIdx);
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