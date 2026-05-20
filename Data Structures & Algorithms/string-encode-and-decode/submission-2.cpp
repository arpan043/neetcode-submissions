class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(auto str : strs){
            output = output + str + "-";
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        std::stringstream ss(s);
        std::string token;

        // Loop through the stream using ',' as a delimiter
        while (std::getline(ss, token, '-')) {
            output.push_back(token);
        }
        return output;
    }
};
