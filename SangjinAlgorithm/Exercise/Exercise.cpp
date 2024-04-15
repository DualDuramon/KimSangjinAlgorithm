#include<iostream>
#include<vector>


using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 7��
* ���� A : �ֱ� ã��
* 
*/

bool isCycleDFS(std::vector<std::vector<int>>& graph, int startNode, int thisNode, std::vector<bool>& visited) {
    visited[thisNode] = true;
    
    for (int i = 0; i < graph[thisNode].size(); i++) {
        int nextNode = graph[thisNode][i];
        if (startNode == nextNode) return true;
        
        if (!visited[nextNode] && isCycleDFS(graph, startNode, nextNode, visited)) {
            return true;
        }
    }
    return false;
}


void FindCycle(std::vector<std::vector<int>>& graph) {
    
    for (int i = 0; i < graph.size(); i++) {
        std::vector<bool>visited(graph.size(), false);
        if (isCycleDFS(graph, i, i, visited)) {
            std::cout << "true\n";
            return;
        }
    }
    std::cout << "false\n";
}

void TestCase() {
    int n = 0, e = 0;
    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n, std::vector<int>());

    for (int i = 0; i < e; i++) {
        int node1 = 0, node2 = 0;
        std::cin >> node1 >> node2;
        graph[node1].push_back(node2);
    }

    FindCycle(graph);

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