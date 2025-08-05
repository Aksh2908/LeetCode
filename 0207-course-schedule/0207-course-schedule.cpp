class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);

        for(auto it:prerequisites){
            indeg[it[0]]++;
        }

        queue<int> q;
        vector<int> visited(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!indeg[i]){
                visited[i]=1;
                q.push(i);
            } 
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:prerequisites){
                if(it[1]==node){
                    indeg[it[0]]--;
                    if(!indeg[it[0]]){
                        q.push(it[0]);
                        visited[it[0]]=1;
                    }
                }
            }
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};