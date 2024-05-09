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
    int startNode = 0;
    int endNode = 0;
    int weight = 0;
};

struct cmp {
    bool operator() (edge& e1, edge& e2) {
        return e1.weight > e2.weight;
    }
};

int prim(std::vector<std::vector<edge>> graph, int startNode, int nodeSize) {
    
    std::vector<bool> visited(nodeSize, false);
    std::vector<int> score(nodeSize, 100);  //100 = INT_MAX

    std::priority_queue < edge, std::vector<edge>, cmp> pq;

    for (auto e : graph[startNode]) {
        score[e.endNode] = e.weight;
        pq.push(e);
    }

    while (!pq.empty()) {
        auto [nowNode, nextNode, w] = pq.top();
        pq.pop();

        visited[nextNode] = true;

        for (edge nextEdge : graph[nextNode]) {
            if (!visited[nextEdge.endNode]) {
                if (nextEdge.weight < score[nextEdge.endNode]) {
                    score[nextEdge.endNode] = nextEdge.weight;
                    pq.push(edge{ nextEdge.startNode,nextEdge.endNode,score[nextEdge.endNode] });
                }
            }
        }
    }
    
    int ans = 0;
    for (auto i : score) {
        if (i == 100) continue;
        ans += i;
    }

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