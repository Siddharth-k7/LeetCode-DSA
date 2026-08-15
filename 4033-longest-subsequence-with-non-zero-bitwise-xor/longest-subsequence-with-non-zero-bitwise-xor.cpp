class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        bool f=false;
        for(int x:nums){
            // TOtal not 0
            xr=xr^x;

            if(x!=0){
                    f=true; // this basiclly says me that if there is not even one 0 
            }
        }
        if(xr!=0){return n;}
        if(f){
            return n-1;
        }

        return 0;

        
        
    }
};