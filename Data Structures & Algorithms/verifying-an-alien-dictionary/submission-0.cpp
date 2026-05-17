class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderIndex(26);

        for(int i = 0;i < order.size(); ++i){
            orderIndex[order[i]] = i; 
        }

        auto compare = [&](const string &a, const string &b){
            for(int i = 0;i < min(a.size(), b.size()); ++i){
                if(a[i] != b[i])
                    return orderIndex[a[i]] < orderIndex[b[i]];
            }
            return a.size() < b.size();
        };        
        return is_sorted(words.begin(), words.end(), compare);
    }
};