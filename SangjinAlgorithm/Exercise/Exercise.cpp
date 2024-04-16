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
* ���� B : �ִܰŸ� ã��
* �켱���� ť�� �̿��� ���ͽ�Ʈ�� ����
*/

typedef std::pair<int, int> edge;   //pair<����ġ, �������>

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

    std::vector<std::vector<edge>> graph(n, std::vector<edge>());   //����ġ �׷���
    std::vector<int> destVec(arrNodeNum);       //���������迭

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