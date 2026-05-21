class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indMap;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(indMap.find(diff) != indMap.end()){
                return {indMap[diff], i};
            }    
            indMap.insert({nums[i],i});
        }
        return {};
    }
};
