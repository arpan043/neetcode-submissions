class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest_streak = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int current_num = num;
                int current_streak = 1;

                while (st.find(current_num + 1) != st.end()) {
                    current_num++;
                    current_streak++;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }
        return longest_streak;
    }
};
