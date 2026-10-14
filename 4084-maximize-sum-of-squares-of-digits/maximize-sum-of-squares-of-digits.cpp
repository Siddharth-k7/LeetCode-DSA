class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9){
            
            return "";}
        int a=sum/9;  // this basically gives us number  of 9 nines 
        int b=sum%9;  // this give us rest number 
        string ans="";
        
            for(int i=0;i<a;i++){
                ans.push_back('9'); // 9 added 
            }
           if(num-ans.size()>0) ans.push_back(b+'0');

        while(ans.size()<num){
                ans.push_back('0');
         }
         return ans;



        
    }
};