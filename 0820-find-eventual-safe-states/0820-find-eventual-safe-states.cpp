class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited,vector<int>& path, vector<int>& safe, int src){
        visited[src]=1;
        path[src]=1;

        for(auto it:graph[src]){
            if(!visited[it]){
                if(dfs(graph,visited,path,safe,it)) return true;
            }
            else if(path[it]){
                return true;
            }
        }
        path[src]=0;
        safe.push_back(src);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<int>visited(v,0);
        vector<int>path(v,0);
        vector<int> safe;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs(graph,visited,path,safe,i)) continue;
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};