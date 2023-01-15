#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>

using namespace std;

class TopologicalSort {
    public:
        static vector<int> sort(int vertices, const vector<vector<int>> &edges)
        {
            vector<int> sortedOrder;

            if (vertices <= 0) {
                return sortedOrder;
            }

            // a. Initialize the graph
            unordered_map<int,int> inDegree;
            unordered_map<int,vector<int>> graph;

            for (int i = 0; i < vertices; i++) {
                inDegree[i] = 0;
                graph[i] = vector<int>();
            }

            // b. Build the graph
            for (int i = 0; i < edges.size(); i++) {
                int parent = edges[i][0], child = edges[i][1];
                graph[parent].push_back(child);
                inDegree[child]++;
            }

            // c. Find all sources
            queue<int> sources;
            for (auto entry : inDegree) {
                if (entry.second == 0) {
                    sources.push(entry.first);
                }
            }

            // 
            while (!sources.empty()) {
                int vertex = sources.front();
                sources.pop();

                sortedOrder.push_back(vertex);
                vector<int> children = graph[vertex];

                for (auto child:children) {
                    inDegree[child]--;
                    if (inDegree[child] == 0) {
                        sources.push(child);
                    }
                }
            }

            if (sortedOrder.size() != vertices) {
                return vector<int>();
            }

            return sortedOrder;


        }

};

int main(int argc, char **argv)
{
    vector<int> result = TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3,2},vector<int>{3,0},vector<int>{2,0},vector<int>{2,1}});

    for (auto num: result) {
        cout << num << " ";
    }
    cout << endl;
}