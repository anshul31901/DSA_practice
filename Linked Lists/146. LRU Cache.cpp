
struct node{

    int val;
    int key;

    node*next;
    node*prev;
    node(int x,int y){
        key = x; 
        val =y;
        next= NULL;
        prev = NULL;
    }

};

class LRUCache {
public:
    unordered_map<int,node*>mp;
    int capacity;
    node*head;
    node*tail;
    LRUCache(int cap) {
        capacity = cap;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node*newnode){
        node*temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        temp->prev = newnode;
        newnode->next = temp;
    }
    void delnode(node*delnode){
        node*delprev = delnode->prev;
        node*delnext = delnode->next;
        delnext->prev = delprev;
        delprev->next = delnext;


    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        node* resnode = mp[key];
        delnode(resnode);
        addNode(resnode);
        return resnode->val;
   
    }
  
    
    void put(int key, int value) {
        int cap = mp.size();

        if(mp.find(key)==mp.end()){
            if(cap == capacity){
                //new node insert
                node*temp = tail->prev;
                delnode(temp);
                mp.erase(temp->key);
            
            }
                node* newnode = new node(key,value);
                mp[key]= newnode;
                addNode(newnode);

        }
        node* desiredNode = mp[key];
        desiredNode->val = value;
        delnode(desiredNode);
        addNode(desiredNode);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
