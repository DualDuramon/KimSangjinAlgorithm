#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 7��
* ���� C : ������ ��ȯ ���� ã��
* BFS�� ����ϴ� ����
*/

void findShortcutWord(std::vector<std::vector<bool>>& graph, std::vector<string>& dictionary, int startIdx, string word, string destWord) {

    std::vector<bool> visited(dictionary.size(), false);
    std::vector<int> dist(dictionary.size(), INT_MAX);
    std::queue<int> queue;
    queue.push(startIdx);
    dist[startIdx] = 0;

    while (!queue.empty()) {
        int nowNode = queue.front();
        visited[nowNode] = true;
        queue.pop();

        for (int i = 0; i < graph[nowNode].size(); i++) {
            if (graph[nowNode][i] && !visited[i]) {
                if (dist[i] > dist[nowNode] + 1) {
                    dist[i] = dist[nowNode] + 1;
                    visited[i] = false;
                }
                queue.push(i);
            }
        }
    }

}

int compareTwoWord(string str1, string str2) {
    int counter = 0;
    for (int idx = 0; idx < str1.size(); idx++) {
        if (str1[idx] != str2[idx]) counter++;
    }

    return counter;
}

void TestCase() {
    bool notInclude = true;
    int dictSize = 0;
    string word = "", destWord = "";
    std::cin >> word >> destWord >> dictSize;

    std::vector<string>dictionary(dictSize + 1);
    dictionary[0] = word;

    //�ܾ�迭 ����
    for (int i = 1; i < dictionary.size(); i++) {
        std::cin >> dictionary[i];
        if (notInclude && dictionary[i] == destWord) 
            notInclude = false;
    }

    if (notInclude) { //���ܾ ������ ���� ���
        std::cout << -1 << "\n";
        return;
    }

    //������ġ ����
    int startIdx = 0;
    for (int i = 0; i < dictionary.size(); i++) {
        int count = compareTwoWord(destWord, dictionary[i]);
        if (count == 0 || 1) {
            startIdx = i;
            break;
        }
    }

    //�׷��� �ʱ�ȭ
    std::vector<std::vector<bool>>graph(dictSize + 1, std::vector<bool>(dictSize + 1, false));

    for (int i = 0; i < graph.size(); i++) {
        for (int j = i; j < graph[i].size(); j++) {
            if (compareTwoWord(dictionary[i], dictionary[j]) == 1) {
                graph[i][j] = graph[j][i] = true;
            }
        }
    }


    //findShortcutWord(graph, dictionary, startIdx, word, destWord);
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