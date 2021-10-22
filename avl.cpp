#include <iostream>

using namespace std;

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

Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return newNode(key);
    }

    if (key <= root->key)
    {
        root->left = insert(root->left, key);
    }

    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

int max(int x, int y)
{
    return (x >= y) ? x : y;
}
int height(Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool AVL(Node *root)
{
    int lh;
    int rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);  
    rh = height(root->right); 
    if (abs(lh - rh) <= 1 && AVL(root->left) && AVL(root->right))
        return 1;
    return 0;
}

int main()
{
    int rootNum;
    cin >> rootNum;
    Node *rootTree = NULL;
    if (rootNum == 0)
    {
        cout << "empty tree";
        return 0;
    }
    else
    {
        rootTree = newNode(rootNum);
        int sum = 0;
        while (1)
        {
            int t;
            cin >> t;
            if (t == 0)
            {
                if(AVL(rootTree)){
                    cout << "This tree has AVL property" ;
                }
                else{
                    cout << "This tree doesn't have AVL property" ;
                }
                break;
            }
            else
            {
                insert(rootTree, t);
            }
        }
    }
    return 0;
}