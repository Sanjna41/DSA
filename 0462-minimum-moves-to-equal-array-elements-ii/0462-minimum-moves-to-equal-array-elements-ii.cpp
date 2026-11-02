class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            moves += nums[r] - nums[l];
            l++;
            r--;
        }
        return moves;
    }
};