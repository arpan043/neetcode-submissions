class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(auto a = 0; a < s.size()-1;a++){
            cout << (int)s[a+1] << "---" << (int)s[a] << endl;
            int tempSum = ((int)((int)s[a+1]-(int)s[a]));
            sum += std::abs(tempSum);
        }
        return sum;
    }
};