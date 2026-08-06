class Solution {
public:
    int smallestNumber(int n, int t) {
        // 10  >=  x  and x dig product % t ==0
        int i=n;
        
        while(true){
            int p=1;
             int temp=i;
            while(temp>0){

                p=p*(temp % 10);
                temp=temp/10;
               
             
            }
            if(p% t==0){return i;}
            i++;

        }

  
        
    }
};