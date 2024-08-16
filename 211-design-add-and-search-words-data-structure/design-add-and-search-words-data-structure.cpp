class WordDictionary {
public:
    bool end;
    WordDictionary* children[26];
    WordDictionary() {
        this->end = false;
        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
    }
    
    void addWord(string word) {
        int n = word.size();
        WordDictionary* p = this;
        for(int i=0;i<n;i++){
            int k = word[i]-'a';
            if(p->children[k]==NULL){
                p->children[k] = new WordDictionary();
            }
            p=p->children[k];
        }
        p->end = true;
    }
    
    bool search(string word) {
        int n = word.size();
        WordDictionary* p = this;
        for(int i=0;i<n;i++){
            if(word[i]=='.'){
                for(auto ch: p->children){
                    if(ch && ch->search(word.substr(i+1))) return true;
                }
                return false;
            }else{
                int k = word[i]-'a';
                if(p->children[k]==NULL) return false;
                p = p->children[k];
            }
        }
        return p && p->end;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */