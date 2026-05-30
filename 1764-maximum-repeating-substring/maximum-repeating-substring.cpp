class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string curr = word;
        int ans = 0;

        while(sequence.find(curr) != string::npos){
            ans++;
            curr += word;
        }

        return ans;
    }
};