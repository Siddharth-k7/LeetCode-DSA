class Solution {
public:
        typedef long long ll;
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();

        vector<vector<int>> children(n); 
        // the idea is to make the each row depth and each row col same leveel 

        for(int i=1; i<n;i++){
            children[parent[i]].push_back(i);
        }

        // Now we do bfs
        queue<int> q;
        q.push(0);
        vector<int> depth(n);
        depth[0]=1;// this for root node 0
        int h=1;
        
        while(!q.empty()){
            int node=q.front();
                q.pop();

            for(int child : children[node]){
                // get it row by row
                depth[child]=depth[node]+1;\
                h=max(depth[child],h);
                q.push(child);
            }  
        }
            ll ans=0;
            int m=nums.size();
            for(int i=0;i<m;i++){
                ans=ans+ 1LL*nums[i]*(h-depth[i]+1);
            }
            return ans;
        
    }
};