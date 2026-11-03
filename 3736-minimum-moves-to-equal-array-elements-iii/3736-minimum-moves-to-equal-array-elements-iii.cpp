class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        for(auto it: nums){
            moves+=(maxi-it);
        }
        return moves;
    }
};