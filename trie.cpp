https://leetcode.com/problems/word-break/submissions/1012094418/

struct Node {
    vector<Node*> next;
    bool isWord;
    Node() {
        isWord = false;
        next = vector<Node *>(26, nullptr);
    }
};

// insert
Node* curr = root;
for (char c: word) {
    int letter = c - 'a';
    if (curr->next[letter] == nullptr) {
        curr->next[letter] = new Node();
    }
    curr = curr->next[letter];
}
curr->isWord = true;
