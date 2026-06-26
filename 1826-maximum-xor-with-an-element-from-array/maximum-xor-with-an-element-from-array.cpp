struct node{
    node* links[2];
    bool containsKey(int ind){
        return links[ind]!=NULL;
    }
    node* get(int ind){
        return links[ind];
    }
    void put(int ind,node* Node){
        links[ind] = Node;
    }
};
class Trie{
    private:
    node* root;
    public:
    Trie(){
        root = new node();
    }
    public:
    void insert(int num){
        node* Node = root;
        for(int i = 31;i>=0;i--){
            int ind = (num>>i)&1;
            if(!Node->containsKey(ind)){
                Node->put(ind,new node());
            }
            Node = Node->get(ind);
        }
    }
    int getMax(int num){
        node* Node = root;
        int maxi = 0;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(Node->containsKey(!bit)){
                maxi = maxi|(1<<i);
                Node = Node->get(!bit);
            }
            else{
                Node = Node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>ans(n);
        Trie* trie = new Trie();
        sort(nums.begin(),nums.end());
        vector<vector<int>> offlineQueries;
        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({queries[i][1], queries[i][0], i});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
       int i = 0;

        for (auto &it : offlineQueries) {
            while (i < nums.size() && nums[i] <= it[0]) {
                trie->insert(nums[i]);
                i++;
            }
            if (i == 0){
                ans[it[2]] = -1;
            }
            else{
                ans[it[2]] = trie->getMax(it[1]);
            }
        }
        return ans;
    }
};