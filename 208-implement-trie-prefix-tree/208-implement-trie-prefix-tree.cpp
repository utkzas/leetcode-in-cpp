// https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
/* 
trie {
  int a[26]
  bool flag
}*/
// production level code contains a lot of functions which eases reusability

struct Node {
    Node *links[26]; // array of pointers?
    bool flag=false;
    bool containsKey(char ch){
        return(links[ch-'a']!=NULL); //if it does exist
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;  // for this 'letter', save the reference node as this node
    }
    Node *get(char ch){ // return, where its pointing to (to get next one)
        return links[ch-'a'];
    }
    void setEnd() {
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};


class Trie {
private:
    Node *root;
public:
    Trie() {
      root = new Node(); // a new struct for every obj of the class
    }
    
    void insert(string word) {  // O(N)
        Node * node = root; // dummy
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){ // does it not contain word[i] ?  
                node->put(word[i],new Node()); // ok, then create a new one
            }
            // move to the new reference trie (iterate)
            node=node->get(word[i]);
        }
        node->setEnd(); // can you please put a flag/something to mark the end of the word?
    }
    
    bool search(string word) { //O(len)
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){ // if at any point word doesn't match the record, return false
                return false;
            }
            node=node->get(word[i]); // keep shifting
        }
        if(node->isEnd()) {
            return true; 
        }
        return false; // is the node marked as the end?
    }
    
    bool startsWith(string word) { //O(len)
        Node *node =root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) // if at any point word doesn't match the record, return false
                return false;
            node = node->get(word[i]);
        }
        return true; //basically no need to check anything, the word iterator successfully walked over the trie
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */