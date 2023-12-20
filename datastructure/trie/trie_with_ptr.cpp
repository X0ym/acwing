#include <iostream>
#include <string>

using namespace std;

#define N 26

struct TrieNode
{
    TrieNode *child[N];
    bool flag;
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int u = word[i] - 'a';
            if (!p->child[u])
            {
                // insert a new node if the path does not exist
                p->child[u] = new TrieNode();
            }
            p = p->child[u];
        }
        p->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int u = word[i] - 'a';
            if (!p->child[u])
            {
                return false;
            }
            p = p->child[u];
        }
        return p->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int u = prefix[i] - 'a';
            if (!p->child[u])
            {
                return false;
            }
            p = p->child[u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
