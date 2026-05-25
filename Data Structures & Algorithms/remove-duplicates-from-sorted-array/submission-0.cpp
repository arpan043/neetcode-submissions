class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> output;
        output.push_back(nums[0]);
        for(int i = 1;i < nums.size();i++){
            if(!(nums[i] == nums[i-1])){
                output.push_back(nums[i]);
            }
        }
        nums = output;
        return output.size();
    }
};