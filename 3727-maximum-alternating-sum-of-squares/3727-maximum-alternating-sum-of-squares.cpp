class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        vector<int> newa(n);
        for(int i=0;i<n;i++){
            newa[i] = 1LL*nums[i]*nums[i];
        }
        sort(newa.begin(),newa.end());
        long long score =0;
        int neg = n/2;
        for(int i=0;i<neg;i++){
            score-=newa[i];
        }
        for(int i = neg;i<n;i++){
            score+=newa[i];
        }
        return score;
    }
};