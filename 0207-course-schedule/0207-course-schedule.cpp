class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indeg(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(!indeg[i]) q.push(i); 
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                indeg[it]--;
                if(!indeg[it]) q.push(it);
            }
        }

        for(auto it:indeg){
            if(it) return false;
        }
        return true;
    }
};