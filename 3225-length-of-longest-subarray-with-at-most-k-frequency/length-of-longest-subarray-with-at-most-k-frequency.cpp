class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();

            int ans=0;
            int j=0;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            while(m[nums[i]]>k){
                m[nums[j]]--;
                j++;                
                }
            ans=max(ans,i-j+1);   

            
        }
        
        
        return ans;

        // int i=0;
        // int j=0;
        // int s=0;
        // while(i<n || j<n){

        // }



    }
};