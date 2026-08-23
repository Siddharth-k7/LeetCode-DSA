class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int lq=0;
        int rq=0;
        int ls=0;
        int rs=0;

        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){lq++;}
                else{ rq++;}
            }
            else{
                if(i<n/2){ls=ls+num[i]-'0';}
                else{rs=rs+num[i]-'0';}
            }
        }
        if(lq+rq % 2 ==1){return true;}
        int L= 2*ls+9*lq;
        int R= 2*rs+9*rq;

        if(L==R){return false;}
        return true;
        
    }
};