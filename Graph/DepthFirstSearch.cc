//Time Complexity: Worst- O(V + E), Average- O(V + E), Best- O(V + E) [V - Number of nodes, E - Number of edges]
//Space Complexity: O(V + E)

//Exaplanation: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/


//Just same as BFS but the difference is taht is uses stack. and everything is same, just think about it, and see the BFS and implement using stack
//Which have only one way to go in and out.




#include<bits/stdc++.h>

using namespace std;


void dfs(unordered_map<int, vector<int>> graph){

    unordered_map<int, bool> visited;
    vector<int> stack;
    vector<int> ans;

    auto f = graph.begin();
    stack.push_back(f -> first);
    visited[f -> first] = true;

    while(!stack.empty()){

        int a = stack[stack.size() - 1];
        
        cout << a << " ";

        stack.pop_back();

        if(graph.find(a) != graph.end()){
            for(int i = 0; i < graph[a].size(); i++){
                
                if(!visited[graph[a][i]]){
                    stack.push_back(graph[a][i]);
                    visited[graph[a][i]] = true;
                }

            }
        }


    }



}




int main(){

    //Stores int value with vector with values of all nodes that first value is connected to
    //For example {1, (2,3,4)} means 1 is connected to 2, 3, 4
    unordered_map<int, vector<int>> graph;

    graph[1] = {2, 3, 4, 5};
    graph[2] = {1, 4, 5};
    graph[3] = {1, 5, 8};
    graph[4] = {2, 1};
    graph[5] = {1, 2, 4, 8};
    graph[8] = {3, 5};

    dfs(graph);

    cout << "\n";

    return 0;


}


