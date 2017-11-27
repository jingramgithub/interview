#include <iostream>

using namespace std;

struct Node
{
    int data;

    Node* left;
    Node* right;

};

class BTree
{
    public:
        Node* root;
        BTree() { root = nullptr; }

        void CreateBTree(int);
        void PreOrder(Node* tree);
        void PostOrder(Node* tree);
        void MidOrder(Node* tree);
};

void BTree::CreateBTree(int num)
{
    Node* newOne = new Node();
    newOne->data = num;
    newOne->left = nullptr;
    newOne->right = nullptr;

    if(root == nullptr)
        root = newOne;
    else
    {
        Node* current = root;
        Node* back = current;

        while(current != nullptr)
        {
            if(current->data == num)
            {
                delete newOne;
                return;
            }

            back = current;
            if(current->data > num)
                current = current->left;
            else
                current = current->right;
        }
        if(back->data > num)
            back->left = newOne;
        else
            back->right = newOne;
    }
}

void BTree::PreOrder(Node* tree)
{
    if(tree != nullptr)
        cout << tree->data << " ";
    else
        return;

    PreOrder(tree->left);
    PreOrder(tree->right);
}

void BTree::PostOrder(Node* tree)
{
    if(tree == nullptr)
        return;

    PostOrder(tree->left);
    PostOrder(tree->right);

    if(tree != nullptr)
        cout << tree->data << " ";
}

void BTree::MidOrder(Node* tree)
{
    if(tree == nullptr)
        return;

    MidOrder(tree->left);

    if(tree != nullptr)
        cout << tree->data << " ";

    MidOrder(tree->right);
}

void InverseTree(Node* tree)
{
    if(tree == nullptr)
        return;

    Node* tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
}

int main()
{
    BTree bt = BTree();

    bt.CreateBTree(2);
    bt.CreateBTree(1);
    bt.CreateBTree(3);

    bt.PreOrder(bt.root);
    cout << endl;
    bt.PostOrder(bt.root);
    cout << endl;
    bt.MidOrder(bt.root);
    cout << endl;

    InverseTree(bt.root);
    bt.PreOrder(bt.root);
    cout << endl;
    return 0;
}
