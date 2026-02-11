class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";

        for(int i=0;i<n;i++){
            // Odd length palindrome
            int st=i,end=i;
            while(st>=0&&end<n&&s[st]==s[end]){
                st--;
                end++;
            }
            string temp=s.substr(st+1,end-st-1);
            if(temp.size()>res.size())res=temp;

            // Even length palindrome
            st=i;
            end=i+1;
            while(st>=0&&end<n&&s[st]==s[end]){
                st--;
                end++;
            }
            temp=s.substr(st+1,end-st-1);
            if(temp.size()>res.size())res=temp;
        }

        return res;
    }
};
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int l = 0, r = s.size() - 1;
//         while (l < r) {
//             if (s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         string ans ="";
//         int len = 0;
//         int n = s.size();
//         for(int i = 0;i<n;i++){
            
//             for(int j = i;j<n;j++){
                
//                 string a = s.substr(i, j-i+1);
//                 if(isPalindrome(a)){
//                     if(j-i+1>len){
//                         len = j-i+1;
//                         ans = a;
//                     }
//                 }

//             } 
//         }
//         return ans;
//     }
// };