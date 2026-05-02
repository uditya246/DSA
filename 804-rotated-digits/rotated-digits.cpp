class Solution {
public:
    bool is_valid(int n){
        string number = to_string(n);
        string rotated = number;
        for(int i = 0;i<number.size();i++){
            if(number[i]=='3'||number[i]=='4'||number[i]=='7'){
                return false;
            }
            if(number[i]=='0'||number[i]=='1'||number[i]=='8'){
                continue;
            }
            else if(number[i]=='2'){
                rotated[i] = '5';
            }
            else if(number[i]=='5'){
                rotated[i] = '2';
            }
            else if(number[i]=='6'){
                rotated[i] = '9';
            }
            else if(number[i]=='9'){
                rotated[i] = '6';
            }
        }
        return !(number==rotated);
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 2;i<=n;i++){
            ans+=is_valid(i);
        }
        return ans;
    }
};