class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string ans = "";

        int nines = sum / 9;
        ans.append(nines, '9');
        int remainder = sum % 9;
        if (remainder > 0) {
            ans += to_string(remainder);
        }
        int zeros = num - ans.length();
        ans.append(zeros, '0');

        return ans;
    }
};