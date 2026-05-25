class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1Size = word1.size()-1;
        int word2Size = word2.size()-1;
        int minSize = min(word1Size, word2Size);
        string output = "";
        for(int i = 0; i <= minSize; i++){
            output = output + word1[i] + word2[i];
        }
        if(word1Size > word2Size){
            int i = minSize +1;
            while(i <= word1Size){
                output = output + word1[i];
                i++;
            }
        }
        else{
            int i = minSize +1;
            while(i <= word2Size){
                output = output + word2[i];
                i++;
            }
        }
        return output;
    }
};