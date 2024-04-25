#include<iostream>
#include<vector>
#include<unordered_set>
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
* 
*/
typedef std::pair<string, int> node; //pair <단어, 거리>

int findShortcutWord(std::unordered_set<string>& dictionary, string& word, string& destWord) {
    std::queue<node> queue;

    queue.push(std::make_pair(word, 0));
    dictionary.erase(word);


    while (!queue.empty()) {
        string nowWord = queue.front().first;
        int nowLength = queue.front().second;
        queue.pop();

        if (nowWord == destWord) { 
            return nowLength;
        }

        for (size_t idx = 0; idx < nowWord.size(); idx++) {
            char originCh = nowWord[idx];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                nowWord[idx] = ch;
                if (dictionary.find(nowWord) != dictionary.end()) {
                    dictionary.erase(nowWord);
                    queue.push(std::make_pair(nowWord, nowLength + 1));
                }
            }
            nowWord[idx] = originCh;
        }
    }
    return -1;
}


void TestCase() {
    int dictSize = 0;
    string word = "", destWord = "";
    std::cin >> word >> destWord >> dictSize;

    std::unordered_set<string> dictionary;

    //단어사전 생성(해쉬set)
    for (size_t i = 0; i < dictSize; i++) {
        string str;
        std::cin >> str;
        dictionary.insert(str);
    }

    if (dictionary.find(destWord) == dictionary.end()) {
        std::cout << "-1\n";
        return;
    }

    std::cout << findShortcutWord(dictionary, word, destWord) << "\n";
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