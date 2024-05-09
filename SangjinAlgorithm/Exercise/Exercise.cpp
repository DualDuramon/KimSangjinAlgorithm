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
struct edge {
    int node1 = 0;
    int node2 = 0;
    int weight = 0;
};

struct cmp {
    bool operator() (edge& e1, edge& e2) {
        return e1.weight > e2.weight;
    }
};

int prim(std::vector<std::vector<edge>> graph, int startNode, int nodeSize) {
    std::vector<bool> visited(nodeSize, false);
    visited[startNode] = true;
    std::vector<int> score(nodeSize, 100);    //100 = INTMAX
    std::vector<edge> tree;

    std::priority_queue<edge, std::vector<edge>, cmp> pq;

    for (edge& e : graph[startNode]) {
        score[e.node2] = e.weight;
        pq.push(e);
    }

    while (!pq.empty()) {
        edge nowEdge = pq.top();
        pq.pop();

        if (!visited[nowEdge.node2])tree.push_back(nowEdge);
        visited[nowEdge.node2] = true;

        for (auto& nextEdge : graph[nowEdge.node2]) {
            if (!visited[nextEdge.node2]) {
                if (nextEdge.weight < score[nextEdge.node2]) {
                    score[nextEdge.node2] = nextEdge.weight;
                    pq.push(nextEdge);
                }
            }
        }

    }

    int ans = 0;
    for (auto& e : tree)
        ans += e.weight;

    return ans;
}

void TestCase() {
    int n{ 0 }, e{ 0 };
    std::cin >> n >> e;

    std::vector<std::vector<edge>>graph(n, std::vector<edge>());

    for (int i = 0; i < e; i++) {
        int s, e, w;
        std::cin >> s >> e >> w;
        graph[s].push_back(edge{ s,e,w });
        graph[e].push_back(edge{ e,s,w });
    }

    int answer = prim(graph, 0, n);
    std::cout << answer << "\n";
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