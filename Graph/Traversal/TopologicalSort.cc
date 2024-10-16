//Time: Best - O(V), Average - O(V + E), Worst - O(V + E)
//Space: O(V)

#include <iostream>
#include <vector>
using namespace std;

void dfs(int num, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& ans) {

    vector<int> stack;
    stack.push_back(num);
    visited[num] = true;

    while(!stack.empty()) {

        int cur = stack.back();
        stack.pop_back();
        ans.push_back(cur);

        for (int i = 0; i < graph[cur].size(); i++) {

            int neighbor = graph[cur][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push_back(neighbor);
            }

        }

    }

}

vector<int> topologicalsort(const vector<vector<int>>& graph){

    vector<int> ans;
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {

        if (!visited[i]) {
            dfs(i, graph, visited, ans);
        }

    }

    return ans;

}

int main() {

    int n = 10;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2, 9};
    graph[1] = {6, 7};
    graph[2] = {3};
    graph[3] = {4, 5};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {};
    graph[7] = {6};
    graph[8] = {6};
    graph[9] = {};

    vector<int> ans = topologicalsort(graph);

    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;


}
