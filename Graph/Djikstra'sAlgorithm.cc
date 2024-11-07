//Time Complexity: Worst- O(V + E)log(V), Average- O(V + E)log(V), Best- O(Vlog(V) + Elog(V)) [V - Number of nodes, E - Number of edges]
//Space Complexity: O(V + E)

//Exaplanation: https://www.programiz.com/dsa/dijkstra-algorithm
//Code: https://www.geeksforgeeks.org/introduction-to-dijkstras-shortest-path-algorithm/


//Djikstra's Algorithm is used to find shortest path from one point to all.
//The priority queue is used here



#include <bits/stdc++.h>
using namespace std;

class Graph{

    public:
    vector<vector<pair<int, int>>> g;

    Graph(int n) {
        g.resize(n);
    }

    void insert(int u, int v, int w) {
        g[u].push_back({v, w});
        g[v].push_back({u, w});

        return;
    }

};

vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int a){


    vector<int> ans(g.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, a});
    ans[a] = 0;

    while (!pq.empty()) {

        pair<int, int> temp = pq.top();
        pq.pop();

        int curdist = temp.first;
        int curval = temp.second;

        for (auto &edge : g[curval]) {

            int temval = edge.first;
            int temdis = edge.second;

            if (ans[temval] > curdist + temdis){
                ans[temval] = curdist + temdis;
                pq.push({ans[temval], temval});
            }

        }

    }

    return ans;


}

int main(){

    Graph gra(7);
    gra.insert(0, 1, 2);
    gra.insert(0, 2, 4);
    gra.insert(0, 3, 8);
    gra.insert(3, 4, 1);
    gra.insert(2, 4, 6);
    gra.insert(4, 5, 4);
    gra.insert(5, 6, 2);
    gra.insert(0, 6, 3);

    vector<int> ans = dijkstra(gra.g, 0);

    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;

}
