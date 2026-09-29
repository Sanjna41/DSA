class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans;
        for(int i =0;i<n;i++){
            int cnt =0;
            for(auto it: matrix[i]){
                 if(it == 1) cnt++;
                 else continue;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};