class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<vector<int>> revGraph(v,vector<int>());
        vector<int> indeg(v,0);
        queue<int> q;
        vector<int> visited(v,0);
        vector<int> ans;
        
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                indeg[i]++;
                revGraph[it].push_back(i);
            }
        }
        
        for(int i=0;i<v;i++){
            if(!indeg[i]){
                q.push(i);
                visited[i]=1;
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it:revGraph[node]){
                indeg[it]--;
                if(!indeg[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};