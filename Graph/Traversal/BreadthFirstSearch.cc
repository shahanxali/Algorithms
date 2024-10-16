//Time Complexity: Worst- O(V + E), Average- O(V + E), Best- O(V + E) [V - Number of nodes, E - Number of edges]
//Space Complexity: O(V)

//Exaplanation: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/


//There will be a queue to store all the elements using bfs, and a vector or map as visited to store if the element is visited so we dont repeat
//to go to it again in future yk, so that loop doesnt form of 1 wants to find 2 and 2 wants to find 1, no we will not go back to 1 as it will
//be marked as visited. now one by one use your brain and see what to do, keep the element in queue say a, mark as visited, then visit all elements of that 
//a, marking them as visited, completely visited the childrens of a? no pop a from the queue and start doing for first child of a and so on till all visited 
//PS: THIS IF FOR A UNDIRECTED GRAPH

//Implemented graph in 2d vector for now, and using bfs in this 2d vector denoting graph

#include<bits/stdc++.h>
using namespace std;


void bfs(unordered_map<int, vector<int>> graph){

    queue<int> q;
    unordered_map<int, bool> visited;

    auto it = graph.begin();
    q.push(it -> first);
    visited[it -> first] = true;

    //Printing first element
    while(!q.empty()){

        int a = q.front();
        q.pop();
        cout << a << " ";

        if(graph.find(a) != graph.end()){
            for(int i = 0; i < graph[a].size(); i++){
                
                if(!visited[graph[a][i]]){
                    q.push(graph[a][i]);
                    visited[graph[a][i]] = true;
                    
                }
            }
        }
    }

    return;

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

    bfs(graph);

    cout << "\n";

    return 0;


}
