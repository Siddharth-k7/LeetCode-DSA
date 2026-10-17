class Solution {
public:

        int getds(int n1){
            int sum=0;
            while(n1!=0){
                sum=sum+(n1%10);
                n1=n1/10;
            }
            return sum;
        }
        void swap(int &a,int &b){
            int temp= a;
            a=b;
            b=temp;
            return;
        }

    int minSwaps(vector<int>& nums) {
        // use Custom Sort

        vector<int> ads=nums; // after digit sort
         auto lamda=[this](int num1,int num2){
            int ds1=getds(num1);
            int ds2=getds(num2);
          if(ds1!=ds2){  return ds1<ds2;}
          return num1<num2;
        };
        sort(begin(ads),end(ads),lamda);
     
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;  // val -> index
        }
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(ads[i]==nums[i]){continue;}
            
            int index=m[nums[i]];
            //    int temp=nums[i]; 
            //     nums[i]=nums[index];
            //     nums[index]=temp;
            //     m[nums[i]]=i;
            //     m[nums[index]]=index;

                  int j = m[ads[i]];       // where the right value sits now
                     m[nums[i]] = j;          // wrong value moves to j
                     m[ads[i]]  = i;          // right value moves to i
                swap(nums[i], nums[j]);
                

            s++;
        }
        return s;               
    }
};