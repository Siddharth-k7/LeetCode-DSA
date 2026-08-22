class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int x;
        int nn=n;
        while(n>0){
            x=n%10;
            n=n/10;
            s=s+x;
            p=p*x;
        }
        if(nn%(s+p)==0){return true;}
        return false;        
    }
};