class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int c=0;
        int m=0;
        unordered_set<int> st(begin(nums),end(nums));
         s=s+nums[0];
        for(int i=1;i<n;i++){
           
                if(nums[i]==nums[i-1]+1){
                    
                   s=s+nums[i];                    
                    }
                else{break;}               
        }
        while(st.find(s)!=st.end()){
            s++;
        }
        
        return s;
        
    }
};