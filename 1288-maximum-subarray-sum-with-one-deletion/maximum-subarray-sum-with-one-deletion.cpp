class Solution {
public:
      int ms(vector<int>& arr){
        int n=arr.size();
        int MaxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum<0){sum=0;}
            MaxSum=max(MaxSum,sum);
            sum=sum+arr[i];
        } 
        return MaxSum;

       }  




    int maximumSum(vector<int>& arr) {
        int keep = arr[0];
        int del = 0;
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            del = max(keep, del + arr[i]);
            keep = max(arr[i], keep + arr[i]);
            ans = max(ans, max(keep, del));
        }

        return ans;



        
    }
};