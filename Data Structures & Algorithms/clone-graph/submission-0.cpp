/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* curr,Node* clone_node,unordered_map<Node*,Node*>&mp)
    {
        for(Node*n:curr->neighbors)
        {
            if(mp.find(n)==mp.end())
            {
                Node* clone=new Node(n->val);
                mp[n]=clone;
                clone_node->neighbors.push_back(clone);
                helper(n,clone,mp);
                
            }
            else
            {
                clone_node->neighbors.push_back(mp[n]);
               
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;
        Node* clone_node=new Node(node->val);
    
        unordered_map<Node*,Node*>mp;
        mp[node]=clone_node;
        helper(node,clone_node,mp);
        return clone_node;

    }
};
