class Solution {
public:
    
    bool checkValidString(string s) {
       
       int high =0;
       int low =0;
       for(char x:s){
        if(x=='(') {
            high++;
            low++;
        }
        else if(x == ')'){
            high--;
            low--;
        }
        else{
            high++;
            low--;
        }
        if(high<0) return false;
        low = max(low,0);
       }
       return low==0;
    }
};