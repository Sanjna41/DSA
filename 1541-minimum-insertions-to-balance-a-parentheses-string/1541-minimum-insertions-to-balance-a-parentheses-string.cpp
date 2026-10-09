class Solution {
public:
    int minInsertions(string s) {
        int count =0;
        int a =0;
        for(char c: s){
             if(c == '('){
               if(count %2 ==1){
                   a++;
                   count--;
               } 
               count+=2;
             }
             else{
                if(count <= 0){
                    a++;
                    count+=2;
                }
                count--;
                
             }
             
        }
        return a+count;
    }
};