class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int src, int color){
        visited[src]=color;
        for(auto it:graph[src]){
            if(visited[it]==-1){
                if(!dfs(graph,visited,it,!color)) return false;
            }
            else if(visited[it]==color) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!dfs(graph,visited,i,0)) return false;
            } 
        }
        return true;
    }
};