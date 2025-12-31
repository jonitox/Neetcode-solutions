#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    // Trie node definition
    struct TrieNode{
        bool end;
        TrieNode* child[26];
        TrieNode() {
            end = false;
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word) {
            int idx = c - 'a';
            if(!cur->child[idx]) cur->child[idx] = new TrieNode();
            cur = cur->child[idx];
        }    
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    // DFS to handle '.' wildcard
    bool dfs(string& word, int pos, TrieNode* cur){
        if (pos == word.size())
            return cur->end;

        char c = word[pos];
        // handle wildcard '.'
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (cur->child[i] && dfs(word, pos + 1, cur->child[i]))
                    return true;
            }
            return false;
        } else { // handle regular character
            int idx = c - 'a';
            if(cur->child[idx] == nullptr) 
                return false;
            return dfs(word, pos + 1, cur->child[idx]);
        }
    }
};




int main() {
    // test code (optional)
    return 0;
}