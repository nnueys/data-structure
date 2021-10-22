#include <iostream>

using namespace std ;

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key <= root->key) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
    return root ;
}


void leafSum(Node *root, int& sum){
    if (!root)
        return;
    if (!root->left && !root->right)
        sum += root->key;
    leafSum(root->left, sum);
    leafSum(root->right, sum);
}

void Inorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

int main(){
    int rootNum ;
    cin >> rootNum ;
    Node *rootTree = NULL;
    if(rootNum == 0){
        cout << "empty tree" ;
        return 0 ;
    }
    else{
        rootTree = newNode(rootNum) ;
        int sum = 0 ;
        while (1)
        {
            int t ;
            cin >> t ;
            if(t == 0){
                leafSum(rootTree,sum) ;
                cout << sum << endl  ; 
                // Inorder(rootTree) ;           
                break ;
            }
            else{
                insert(rootTree,t) ;
            }
        }
    }
    return 0 ;
}