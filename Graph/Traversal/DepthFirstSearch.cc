//Time Complexity: Worst- O(V + E), Average- O(V + E), Best- O(V + E) [V - Number of nodes, E - Number of edges]
//Space Complexity: O(V + E)

//Exaplanation: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/


//Just same as BFS but the difference is taht is uses stack. and everything is same, just think about it, and see the BFS and implement using stack
//Which have only one way to go in and out.




#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph) {

    vector<bool> visited(graph.size(), false);
    vector<int> stack;

    stack.push_back(0);  // Start DFS from node 0
    visited[0] = true;

    while (!stack.empty()) {

        int a = stack.back();
        
        cout << a << " ";
        stack.pop_back();

        for (int i = 0; i < graph[a].size(); i++){

            if (!visited[graph[a][i]]) {

                stack.push_back(graph[a][i]);
                visited[graph[a][i]] = true;

            }

        }

    }


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


    dfs(graph);

    cout << "\n";



    return 0;



}



