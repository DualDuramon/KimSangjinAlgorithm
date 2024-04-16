#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
/*
* 알고리즘 및 실습 02분반
* 2019136003 강윤민
* 2024년도 1학기 알고리즘및실습 7장
* 문제 B : 최소거리 찾기
*
*/
typedef std::pair<int, int> edge;   //edge<가중치 값, 도착노드>

int Dijkstra(std::vector<std::vector<edge>>& graph, int distNode) {



    return 0;
}

void FindShortestWay(std::vector<std::vector<edge>>& graph, std::vector<int>& dist) {

    for (int i = 0; dist.size(); i++) {
        std::vector<bool> visited(graph.size());

    }

}

void TestCase() {
    int n = 0, e = 0, startNode = 0;
    std::cin >> n >> e >> startNode;

    std::vector<std::vector<edge>> graph(n, std::vector<edge>(e));
    
    int targets = 0;
    std::cin >> targets;
    std::vector<int> dist(targets);

    for (int i = 0; i < targets; i++)
        std::cin >> dist[i];


    for (int i = 0; i < e; i++) {
        int node = 0, val = 0;
        std::cin >> node >> val;
        graph[i].push_back({ val,node });
    }

    FindShortestWay(graph, dist);
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