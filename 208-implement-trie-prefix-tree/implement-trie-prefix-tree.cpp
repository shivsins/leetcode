class Trie {
public:
    bool end;
    Trie* children[26];
    Trie() {
      this->end=false;
      for(int i=0;i<26;i++){
          this->children[i]=NULL;
      }
    }
    
    void insert(string word) {
        Trie* p = this;
        int n = word.size();
        for(int i=0;i<n;i++){
            int k = word[i]-'a';
            if(p->children[k]==NULL){
                p->children[k]=new Trie();
            }
            p=p->children[k];
        }
        p->end=true;
    }
    
    bool search(string word) {
        Trie* p = this;
        int n = word.size();
        for(int i=0;i<n;i++){
            int k = word[i]-'a';
            if(p->children[k]==NULL) return false;
            else p=p->children[k];
        }
        if(p!=NULL && p->end==true) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        int n = prefix.size();
        for(int i=0;i<n;i++){
            int k = prefix[i]-'a';
            if(p->children[k]==NULL) return false;
            else p=p->children[k];
        }
        if(p!=NULL) return true;
        else return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */