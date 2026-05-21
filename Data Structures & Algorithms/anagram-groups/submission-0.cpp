class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string>> strToAnagramMap;
        vector<string> anagrams;
        for(auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            strToAnagramMap[temp].push_back(str);
            
        }
        vector<vector<string>> result;
        for (auto& pair : strToAnagramMap) {
            result.push_back(pair.second);
        }
        return result;

    }
};
