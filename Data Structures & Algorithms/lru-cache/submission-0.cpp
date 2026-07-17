class Node {
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v)
    {
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
   unordered_map<int,Node*>mp;
   Node* head=new Node(-1,-1);
   Node* tail=new Node(-1,-1);
   int capacity;
   void deletion(Node* node)
{
    Node* beforenode=node->prev;
    Node* afternode=node->next;
    beforenode->next=afternode;
    afternode->prev=beforenode;
    return;
}
void insertion(Node* node)
{
    Node* afterhead=head->next;
    head->next=node;
    node->next=afterhead;
    node->prev=head;
    afterhead->prev=node;

}
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;
        else
        {
            Node* node=mp[key];
            deletion(node);
            insertion(node);
            
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            if(mp.size()!=capacity)
            {
             Node* node=new Node(key,value);
             insertion(node);
             mp[key]=node;
            }
            else
            {
                Node* todelete=tail->prev;
                deletion(todelete);
                mp.erase(todelete->key);
                Node* node=new Node(key,value);
                insertion(node);
                mp[key]=node;
            }

        }
        else
        {
            Node* node=mp[key];
            deletion(node);
            insertion(node);
            node->val=value;
        }
    }
};
