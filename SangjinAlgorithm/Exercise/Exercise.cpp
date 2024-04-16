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
* 문제 B : 최단거리 찾기
* 우선순위 큐를 이용한 다익스트라 구현
*/

typedef std::pair<int, int> edge;   //pair<가중치, 도착노드>

void Dijkstra(std::vector<std::vector<edge>>& graph, std::vector<int>& destVec, int startNode){

    std::vector<int> distance(graph.size(), INT_MAX);
    std::priority_queue<int> dijkQ;
    std::vector<bool> visited(graph.size(), false);
  
    dijkQ.push(startNode);
    distance[startNode] = 0;

    while (!dijkQ.empty()) {
        int nowNode = dijkQ.top();
        visited[nowNode] = true;
        dijkQ.pop();

        for (edge e : graph[nowNode]) {
            int nextNode = e.second;
            int nextCost = e.first;

            if (distance[nextNode] > distance[nowNode] + nextCost) {
                distance[nextNode] = distance[nowNode] + nextCost;
                dijkQ.push(e.second);
            }
        }
    }

    for (int i = 0; i < destVec.size(); i++) {
        std::cout << (distance[destVec[i]] == INT_MAX ? -1 : distance[destVec[i]]) << " ";
    }
    std::cout << "\n";
}


void TestCase() {
    int n = 0, e = 0, startNode = 0, arrNodeNum = 0;
    std::cin >> n >> e >> startNode >> arrNodeNum;

    std::vector<std::vector<edge>> graph(n, std::vector<edge>());   //가중치 그래프
    std::vector<int> destVec(arrNodeNum);       //목적지노드배열

    for (int i = 0; i < arrNodeNum; i++) {
        std::cin >> destVec[i];
    }

    for (int i = 0; i < e; i++) {
        int node1, node2, cost;
        std::cin >> node1 >> node2 >> cost;

        graph[node1].push_back({ cost,node2 });
    }

    Dijkstra(graph, destVec, startNode);
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