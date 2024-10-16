//Time Complexity: Worst- O(V + E)log(V), Average- O(V + E)log(V), Best- O(Vlog(V) + Elog(V))
//Space Complexity: O(V)
//[V - Number of nodes, E - Number of edges]

//Exaplanation: https://www.programiz.com/dsa/dijkstra-algorithm


//Djikstra's Algorithm is used to find shortest path from one point to all.
//The priority queue is used here
//So what we do is just the DFS or BFS, the only difference is that in them we use visited bool to not check the cur again if it is gone
//But here we will keep on adding in the priority queue if the current node is updates, if not updated then let it go without adding in queue
//But other optimizations like continue if statement after popping from queue is messy, and also priority queue holding both node value distance too
//But no problem, you know the algorithm now, just keep on updating the current node with minimum thus found, if it is updated that means we need to
//check other connected with that current again because it is just updated, so keep in priority queue



#include <bits/stdc++.h>
using namespace std;

//Just the class to create the graph, I just learned and it makes it easier when we do this so
class Graph {
public:
    int v;
    vector<vector<pair<int, int>>> gra;

    Graph(int size) {
        v = size;
        gra.resize(size);
    }

    void addedge(int u, int v, int w) {
        gra[u].push_back({v, w});
        gra[v].push_back({u, w});
    }
};



// Dijkstra's algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int source) {

    // Priority queue stores {distance, node}, and is a min-heap based on distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(graph.size(), INT_MAX);
    dist[source] = 0;
    pq.push({0, source});  // {distance, node}

    while (!pq.empty()) {

        //To chose only minimum of current node that's it, otherwise we could've just used normal queue. but we can't only store the distance, we have
        //to know the node correspondidng to it too right
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        //This will skip the current iteration, a part of continue keyword we don't know. but know now, everything after this will work as else
        if (cur_dist > dist[cur_node]) continue;  // Skip if this path is not optimal anymore

        // Process each neighbor of the current node
        for (auto& neighbor : graph[cur_node]) {

            int next_node = neighbor.first;
            int edge_weight = neighbor.second;

            // The step to update, if updated then add in priority queue
            if (dist[cur_node] + edge_weight < dist[next_node]) {
                dist[next_node] = dist[cur_node] + edge_weight;
                pq.push({dist[next_node], next_node});
            }

        }

    }

    return dist;

}




int main() {
    int n = 6;

    Graph g(n);
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 1);
    g.addedge(1, 4, 6);
    g.addedge(4, 5, 8);
    g.addedge(4, 3, 3);
    g.addedge(2, 3, 2);

    vector<int> ans = dijkstra(g.gra, 0);

    // Output shortest distances from source node 0
    for (int i = 0; i < ans.size(); i++) {
        cout << "0 -> " << i << " = " << ans[i] << endl;
    }

    return 0;
}
