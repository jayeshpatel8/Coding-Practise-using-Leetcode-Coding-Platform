#include <unordered_map>
//using namespace std;
#define TRUE true;
#define FALSE false;
const int ALPHABET_SIZE = 26;
//#define MAP
class Trie {
  //  class Trie * n;
#ifdef MAP
    unordered_map<char ,  Trie*> n;
    bool e;
#else
    struct Trie *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
#endif
public:
#ifdef MAP 
#else
// Returns new trie node (initialized to NULLs)
class Trie *getNode(void)
{
    class Trie *pNode =  new Trie;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
#endif
    /** Initialize your data structure here. */
    Trie() {
#ifdef MAP        
        e=false;
        n.clear();
#else
isEndOfWord=false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        children[i] = NULL;
#endif        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
#ifdef MAP        
        
Trie *t1=this;
        
        if (word.empty())
         return;
        if (n.empty())
        {
            //root node empty
            for(auto c1: word){
                auto *n1 = new Trie();
              //  n1->c=c1;
                t1->n.emplace(c1,n1);
                t1=n1;
            }
            t1->e=true;
            return;
        }
       
        t1=this;
        for(auto c1 : word)
        {
            auto got  = t1->n.find(c1);
            if( got == t1->n.end())
            {
                auto *n1 = new Trie();
              //  n1->c=c1;
                t1->n.emplace(c1,n1);
                t1=n1;
                    continue;
            }
            else
                t1=got->second;

        }
        t1->e=true;

#else
    class Trie *pCrawl = this;
 
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = new Trie;
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
#endif                
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
#ifdef MAP
         Trie *t1=this;
        
        if (word.empty()|| n.empty() )
             return FALSE;
        
        for(auto c1 : word)
        {
            auto got  = t1->n.find(c1);
            if( got == t1->n.end())
            {
                return FALSE;
            }
            else
                t1=got->second;

        }
        if(t1->e==true)
            return true;
        else 
            return false;

#else
    class Trie *pCrawl = this;
 
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
#endif                        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
#ifdef MAP
         Trie *t1=this;
        
        if (prefix.empty()|| n.empty() )
             return FALSE;
        
        for(auto c1 : prefix)
        {
            auto got  = t1->n.find(c1);
            if( got == t1->n.end())
            {
                return FALSE;
            }
            else
                t1=got->second;

        }
        return TRUE;

#else 
class Trie *pCrawl = this;
 
    for (int i = 0; i < prefix.length(); i++)
    {
        int index = prefix[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL);
#endif                    
        
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */