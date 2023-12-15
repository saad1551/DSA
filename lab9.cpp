#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node *left;
        tree_node *right;
        int data;
    };

public:
    tree_node *root;

    BinarySearchTree()
    {
        root = nullptr;
    }
    bool isEmpty() const { return root == NULL; }
    void print_inorder();
    void inorder(tree_node *);
    void print_preorder();
    void preorder(tree_node *);
    void print_postorder();
    void postorder(tree_node *);
    void insert(int);

    tree_node *remove(int d, tree_node *node)
    {
        // First locate the element, if the element is not found, simply generate an error message
        //  Then there will be three cases in removing d. Code accordingly
        //  1. Removing a leaf node
        //  2. Removing a node with a single child
        //  3. Removing a node with 2 children, then adjust its parents and grand children links
        if (node == nullptr)
            return nullptr;

        else if (d < node->data)
        {
            node->left = remove(d, node->left);
            return node;
        }

        else if (d > node->data)
        {
            node->right = remove(d, node->right);
            return node;
        }

        else if (d == node->data)
        {
            // if the node does not have any children, then simply delete it
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return node;
            }
            // if the tree has only right child
            else if (node->left == nullptr && node->right != nullptr)
            {
                // store the node to delete in a temp pointer
                tree_node *temp = node;
                // make the parent point toward the right child
                node = node->right;
                // delete the node
                delete temp;
                return node;
            }
            // if the tree has only left child
            else if (node->left != nullptr && node->right == nullptr)
            {
                // store the node to delete in a temp pointer
                tree_node *temp = node;
                // make the parent point toward the left child
                node = node->left;
                // delete the node
                delete temp;
                return node;
            }
            // if the tree has both left and right children
            else if (node->left != nullptr && node->right != nullptr)
            {
                // store the node to delete in a temp pointer
                tree_node *temp = node;
                // go the right subtree
                node = node->right;
                // traverse to left subtrees until there is no left subtree left
                while (node->left != nullptr)
                {
                    node = node->left;
                }
                // replace the data of the node to be deleted with the data of the leaf node of the left subtree
                temp->data = node->data;
                temp->right = node->right;
                // delete the leaf node
                delete node;
                return node;
            }
        }
        return nullptr;
    }
};

void BinarySearchTree::insert(int d)
{

    tree_node *t = new tree_node;
    tree_node *parent = root;
    t->data = d;
    t->left = nullptr;
    t->right = nullptr;

    if (root == nullptr)
    {
        root = t;
        return;
    }

    // Smaller elements should go to the left, whereas larger  elements should go to the right
    else
    {
        while (1)
        {
            // if the element is equal to the current node
            if (d == parent->data)
            {
                return;
            }
            // if the element is smaller than or equal to the current node
            if (d < parent->data)
            {
                // if the current element has no left child
                if (parent->left == nullptr)
                {
                    // insert the new node as the left child of the current node
                    parent->left = t;
                    // end the function
                    return;
                }
                // if the current node has a left child
                else
                {
                    // move to the left child of the current node
                    parent = parent->left;
                }
            }
            // if the element is greater than the current node
            if (d > parent->data)
            {
                if (parent->right == nullptr)
                {
                    // insert the new node as the right child of the current node
                    parent->right = t;
                    // end the function
                    return;
                }
                // if the current element has a right child
                else
                {
                    parent = parent->right;
                }
            }
        }
    }
}

void BinarySearchTree::print_inorder()
{
    inorder(root);
    cout << endl;
}

void BinarySearchTree::inorder(tree_node *p)
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->data << "\t";
        inorder(p->right);
    }
}

void BinarySearchTree::print_preorder()
{
    preorder(root);
    cout << endl;
}

void BinarySearchTree::preorder(tree_node *p)
{
    if (p != nullptr)
    {
        cout << p->data << "\t";
        preorder(p->left);
        preorder(p->right);
    }
}

void BinarySearchTree::print_postorder()
{
    postorder(root);
    cout << endl;
}

void BinarySearchTree::postorder(tree_node *p)
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "\t";
    }
}

void insertIntoTree(BinarySearchTree *b)
{
    cout << "How many elements do you want to insert?" << endl;
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element # " << i << ":"
             << "\t";
        cin >> val;
        b->insert(val);
    }
}

int main()
{
    BinarySearchTree b;

    while (true)
    {

        int menuOption = 0;

        while (menuOption > 6 || menuOption < 1) // This loop can exit program
        {
            cout << "\t*****************************************" << endl;
            cout << "\t* Select Option:\t\t\t*" << endl;
            cout << "\t*\t0. Test using data from an array\t\t*" << endl;
            cout << "\t*\t1. Insert New Data\t\t*" << endl;
            cout << "\t*\t2. In-Order Traversal\t\t*" << endl;
            cout << "\t*\t3. Pre-Order Traversal\t\t*" << endl;
            cout << "\t*\t4. Post-Order Traversal\t\t*" << endl;
            cout << "\t*\t5. Delete an item\t\t*" << endl;
            cout << "\t*\t6. Exit\t\t\t\t*" << endl;
            cout << "\t*****************************************" << endl;

            cout << "> ";
            cin >> menuOption;

            if (menuOption == 6)
            {
                return 0; // Exiting
            }

            switch (menuOption)
            {
            case 0:
            {
                // setting up the random number generator
                srand(time(0));

                // Asking the user for the size of the array to test the program
                cout << "Enter the size of the array to test: ";
                int n;
                cin >> n;

                // creating an array of the given size
                int *array = new int[n];

                // populating the array with random numbers
                for (int i = 0; i < n; i++) {
                    array[i] = rand();
                }

                // insert each of the numbers in the array into the tree one by one
                for (int i = 0; i < n; i++) {
                    b.insert(array[i]);
                }
                break;
            }
            case 1:
            {
                insertIntoTree(&b);
                break;
            }
            case 2:
            {
                b.print_inorder();
                break;
            }
            case 3:
            {
                b.print_preorder();
                break;
            }
            case 4:
            {
                b.print_postorder();
                break;
            }
            case 5:
            {
                cout << "Enter element to remove:" << endl;
                int elem;
                cin >> elem;
                b.remove(elem, b.root);
            }
            }
        }
    }
    getchar();
}