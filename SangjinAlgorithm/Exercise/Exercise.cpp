#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 9장
* 문제 A : 가중치 무방향 그래프 최소신장트리 구하기
* 우선순위 큐를 이용한 Prim 알고리즘 이용
*
*/
typedef std::pair<int, int> edge; //tuple<도착노드 , 가중치>

int prim(std::vector<std::vector<edge>> graph, int startNode, int nodeSize) {
    
    std::vector<bool> visited(nodeSize, false);
    std::vector<int> score(nodeSize, 100);  //100 = INT_MAX



    return 0;
}

void TestCase() {
    int n{ 0 }, e{ 0 };
    std::cin >> n >> e;

    std::vector<std::vector<edge>>graph(n, std::vector<edge>());

    for (int i = 0; i < e; i++) {
        int s, e, w;
        std::cin >> s >> e >> w;
        graph[s].push_back(std::make_pair(e, w));
    }

    int answer = prim(graph, 0, n);
    
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