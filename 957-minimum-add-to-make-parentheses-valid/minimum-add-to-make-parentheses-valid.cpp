class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> t;
        if(s.size()==0){return 0;}
        int c=0;
        

        for(auto ch : s){
           if (!t.empty() && ch == ')' && t.back() == '(') {
            t.pop_back();
           } else {
            t.push_back(ch);
           }
        }
        return t.size();
        
    }
};