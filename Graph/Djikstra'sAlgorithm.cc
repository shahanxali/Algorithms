//Time Complexity: Worst- O(V + E)log(V), Average- O(V + E)log(V), Best- O(Vlog(V) + Elog(V)) [V - Number of nodes, E - Number of edges]
//Space Complexity: O(V + E)

//Exaplanation: https://www.programiz.com/dsa/dijkstra-algorithm


//Djikstra's Algorithm is used to find shortest path from one point to all.
//The priority queue is used here



#include<bits/stdc++.h>

using namespace std;


void Djikstra(vector<vector<int> graph, int target){




}













int main() {

    int n = 6; // Number of nodes
    vector<vector<int>> graph(n);

    graph[0] = {1, 2, 3, 4};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4, 5};
    graph[3] = {1, 0};
    graph[4] = {0, 1, 3, 5};
    graph[5] = {2, 4};


    int start = 0;
    djikstra(graph, start);

    cout << "\n";



    return 0;



}









