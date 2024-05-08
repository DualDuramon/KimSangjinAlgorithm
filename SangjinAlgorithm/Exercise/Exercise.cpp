#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
/*
* �˰��� �� �ǽ� 02�й�
* 2019136003 ������
* 2024�⵵ 1�б� �˰���׽ǽ� 9��
* ���� A : ����ġ ������ �׷��� �ּҽ���Ʈ�� ���ϱ�
* �켱���� ť�� �̿��� Prim �˰��� �̿�
*
*/
typedef std::pair<int, int> edge; //tuple<������� , ����ġ>

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