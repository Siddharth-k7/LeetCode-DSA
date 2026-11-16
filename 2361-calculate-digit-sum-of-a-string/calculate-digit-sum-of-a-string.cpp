class Solution {
public:
    
    string fun(string s, int k){
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i=i+k){
                int sum=0;

            for(int j=i;j<min(i+k,n);j++){
                int x=s[j]-'0';  // convert char to intger 
                sum=sum+x;         //add in x

            }
            string t=to_string(sum);   // convert sum intergert to string ...
            ans=ans+t;// push in global ans string 
        }

        return ans;

    }

    string digitSum(string s, int k) {
        
        int n =s.size();
        if(n<=k){return s;}
        string Gans=fun(s,k);
        if(Gans.size()>k){return digitSum(Gans,k);}

        return Gans;   
    }
};