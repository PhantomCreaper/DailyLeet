// 648. Replace Words
class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char c:word){
            if(node->children.find(c) == node->children.end()){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }

    string searchRoot(string word){
        TrieNode* node = root;
        for(char c:word){
            if(node->children.find(c) == node->children.end()){
                break;
            }
            node = node->children[c];
            if(!node->word.empty()){
                return node->word;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string root:dictionary){
            trie.insert(root);
        }
        stringstream ss(sentence);
        string word;
        string result = "";

        while(ss >> word){
            if(!result.empty()){
                result += " ";
            }
            result += trie.searchRoot(word);
        }
        return result;
    }
};
