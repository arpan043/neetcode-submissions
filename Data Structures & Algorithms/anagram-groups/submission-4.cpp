class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string>> strToAnagramMap;
        
        for(const auto& str : strs){
            vector<int> count(26,0);
            for(char c : str){
                count[c-'a']++;
            }
            std::string key = "";
    for (int c : count) {
        key += std::to_string(c) + "#"; // Delimiter used to prevent ambiguity
    }

    strToAnagramMap[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& pair : strToAnagramMap) {
            result.push_back(pair.second);
        }
        return result;

    }
};
