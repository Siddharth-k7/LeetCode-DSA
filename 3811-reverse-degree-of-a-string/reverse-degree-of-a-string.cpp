class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            int x= 'z'- ch +1;  // z-a=
            int a=x*(i+1);
            sum=sum+a;
        }
        return sum;
        
    }
};