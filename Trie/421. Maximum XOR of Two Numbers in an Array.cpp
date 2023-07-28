https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/
class Solution {
//we create a trie node which is suitable for storing binary representation of integers so it will contain only 2 links

struct Node{
    Node* links[2];
    //0 ->0th idx
    //1->1st idx

    bool containsKey(int i){
        return (links[i]!=NULL);
    }
    void put(int i,Node* node){
        links[i]=node;
    }
    Node* get(int i){
        return links[i];
    }
};
class Trie{
    private:Node*root;
    public: 
    Trie(){
        root=new Node();
    }
//if we want to inset an integer in the trie we will do it in leftmost to rightmost fashion
//we will obtain 32nd bit by r shifting the no. 31 times & operating with 1.
//if  the bit is present we just move to its link and move to next iteration
//if bit is not present we put it and then move to its link and then nexy iteration
    void insert(int x){
        Node*node = root;
        for(int i=31;i>=0;i--){
            int bit =(x>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
//for maximum xor between and int x and y,they must have opposite bit values at corresponding positions, for e.g. if x is 1010 y must be 0101
//in order for xor to be maximum. in order for xor to be maximum leftmost bits are more desired to be different so we iterate bits from left
//to right
//we take a maxi =0 
//we calculate the leftmost bit .if (the trie node contains !bit) maxi,s leftmost bit =1 and we move to its link else we have no option to 
//move to the next bit
    int maxXOR(int x){
        Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit = (x>>i)&1;
            if(node->containsKey(1-bit)){
                maxi = maxi|(1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }
        return maxi;
    }
};

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it:nums) trie.insert(it);
        int maxi=0;
        for(auto it:nums){
            maxi=max(maxi,trie.maxXOR(it));
        }
        return maxi;

    }
};
