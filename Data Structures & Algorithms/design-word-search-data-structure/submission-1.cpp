struct Node
{
   Node* links[26];
   bool flag=false;

   bool containsKey(char ch)
   {
    if(links[ch-'a']!=NULL)
    return true;
    return false;
   }
   void put(char ch,Node* node)
   {
     links[ch-'a']=node;
   }
   Node* get(char ch)
   {
    return links[ch-'a'];
   }
   void setEnd()
   {
    flag=true;
   }
   bool isEnd()
   {
    return flag;
   }
};
class WordDictionary {
    private: Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(char ch:word)
        {
            if(node->containsKey(ch)==false)
            node->put(ch,new  Node());
            node=node->get(ch);
        }
        node->setEnd();
    }
    bool searchHelper(Node* root,string word)
    {
        Node* node=root;
        int n=word.length();
        for(int j=0;j<n;j++)
        {
            char ch=word[j];
            if(ch=='.')
            {
                for(int i=0;i<26;i++)
                {
                    if(node->links[i]!=NULL)
                    {
                        if(searchHelper(node->links[i],word.substr(j+1)))
                        return true;

                    }
                }
                return false;
            }
            else
            {
                if(node->links[ch-'a']==NULL)
                return false;
                node=node->get(ch);
            }
        }
        return node->isEnd();
    }
    bool search(string word) {
       return searchHelper(root,word); 
    }
};
