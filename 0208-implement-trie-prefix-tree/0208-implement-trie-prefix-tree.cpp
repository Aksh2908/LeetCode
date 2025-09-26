typedef struct node{
    node *links[26];
    bool flag;
    node(){
        for(int i=0;i<26;i++){
            links[i]=nullptr;
        }
        flag=false;
    }
}node;
class Trie {
private: node *root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->links[word[i]-'a']==nullptr){
                temp->links[word[i]-'a']=new node();
            }
            temp=temp->links[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        node *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->links[word[i]-'a']==nullptr){
                return false;
            }
            temp=temp->links[word[i]-'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        node *temp=root;
        for(int i=0;i<prefix.length();i++){
            if(temp->links[prefix[i]-'a']==nullptr){
                return false;
            }
            temp=temp->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */