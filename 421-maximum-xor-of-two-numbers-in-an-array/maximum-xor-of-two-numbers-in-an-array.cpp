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
    int findMaximumXOR(vector<int>& nums) {
        int ans = INT_MIN;
        Trie* trie = new Trie();
        for(auto it : nums){
            trie->insert(it);
        }
        for(auto it : nums){
            ans = max(ans,trie->getMax(it));
        }
        return ans;
    }
};