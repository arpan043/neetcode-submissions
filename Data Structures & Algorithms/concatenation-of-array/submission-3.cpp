class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        int i = 0;
        for(auto num : nums){
            ans[i] = ans[i + n] = nums[i];
            i++;
        }
        return ans;
    }
};