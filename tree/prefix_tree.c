#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// The number of children for each node
// We will construct a N-ary tree and make it
// a Trie
// Since we have 26 english letters, we need
// 26 children per node
#define N 26

typedef struct TrieNode TrieNode;

struct TrieNode {
    TrieNode* children[N];
    bool end_ofword;
};

TrieNode* make_trienode(char data) {
    // Allocate memory for a TrieNode
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    for (int i=0; i<N; i++)
        node->children[i] = NULL;
    node->end_ofword = false;
    return node;
}

void free_trienode(TrieNode* node) {
    for(int i=0; i<N; i++) {
        if (node->children[i] != NULL) {
            free_trienode(node->children[i]);
        }
        else {
            continue;
        }
    }
    free(node);
}

bool isaword(struct TrieNode* root)
{
    return root->end_ofword != false;
}

void insert_trie(TrieNode* root, char* word) {
    // Inserts the word onto the Trie
    // ASSUMPTION: The word only has lower case characters
    TrieNode* temp = root;

    for (int i=0; word[i] != '\0'; i++) {
        int idx = (int) word[i] - 97;
        if (temp->children[idx] == NULL) {
            
            temp->children[idx] = make_trienode(word[i]);
        }
       temp=  temp->children[idx];
    }
    temp->end_ofword = true;
}


void print_trie(TrieNode* root,char* str, int start) {
    // Prints the nodes of the trie
    if (isaword(root)){
		str[start] = '\0';
		printf("%s\n", str);
	}
    for (int i = 0; i < N; i++)
	{
		if(root->children[i]){
			str[start] = i + 97;
			print_trie(root->children[i], str, start+1);
		}
	}
	
}

int main() {
    // Driver program for the Trie Data Structure Operations
    TrieNode* root = make_trienode('\0');
    insert_trie(root, "mohammed");
    insert_trie(root, "reda");
    insert_trie(root, "ibrahim");
    insert_trie(root, "aissa");
	char str[20];
    print_trie(root, str, 0);
    free_trienode(root);
    return 0;
}

