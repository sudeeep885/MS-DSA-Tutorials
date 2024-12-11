#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int value;

    TrieNode() {
        value = -1; // Default value indicating no data
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i]; // Recursively delete child nodes
                children[i] = nullptr;
            }
        }
    }
};

class Trie {
private:
    TrieNode* root;

    // Helper function for deletion
    bool deleteHelper(TrieNode* node, const string& key, int depth) {
        if (!node) return false;

        // Base case: If the end of the word is reached
        if (depth == key.size()) {
            if (node->value == -1) return false; // Key doesn't exist

            // Unset the value
            node->value = -1;

            // Check if the node has no children (it's now a leaf)
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) return false; // Still has children
            }
            return true; // Safe to delete this node
        }

        // Recurse for the child node corresponding to the current character
        int index = key[depth] - 'a';
        if (deleteHelper(node->children[index], key, depth + 1)) {
            delete node->children[index]; // Deallocate memory for the child
            node->children[index] = nullptr;

            // Check if this node can also be deleted
            if (node->value != -1) return false; // Node has a value
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) return false; // Node has children
            }
            return true; // Safe to delete this node
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root; // Deallocate the entire Trie
    }

    // Insert a key with a value
    void insert(const string& key, int value) {
        TrieNode* node = root;
        for (char c : key) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->value = value;
    }

    // Search for a key and return its value (-1 if not found)
    int search(const string& key) {
        TrieNode* node = root;
        for (char c : key) {
            int index = c - 'a';
            if (!node->children[index]) return -1; // Key not found
            node = node->children[index];
        }
        return node->value; // Return the value (-1 if no value stored)
    }

    // Delete a key from the Trie
    void remove(const string& key) {
        deleteHelper(root, key, 0);
    }
};

int main() {
    Trie trie;

    trie.insert("she", 100);
    trie.insert("shells", 200);

    cout << "Value for 'she': " << trie.search("she") << endl; // Output: 100
    cout << "Value for 'shells': " << trie.search("shells") << endl;     // Output: 200

    trie.remove("shell");
    cout << "Value for 'she' after deletion: " << trie.search("she") << endl; // Output: -1
    cout << "Value for 'shells': " << trie.search("shells") << endl;                   // Output: 200

    return 0;
}
