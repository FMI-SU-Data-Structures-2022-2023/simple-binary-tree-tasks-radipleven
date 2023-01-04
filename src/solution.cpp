#include "solution.h"

int countElements(Node* tree) 
{
    if (!tree) return 0;
   
    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) 
{
    if (!tree) return 0;
    
    if (!tree->left && !tree->right)  return 1;
    
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) 
{
    if (!tree) return 0;
    
    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node* tree)
{
    if (!tree) return 0;

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) 
{
    if (!tree) return 0;
    
    if (!level) return tree->key;

    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}

bool symmetricNodes(Node* left, Node* right) 
{
    if (left == nullptr && right != nullptr || right == nullptr && left != nullptr) 
    {
        return false;
    }
    else if(left == nullptr && right == nullptr)  return true;

    if(left->key == right->key) return symmetricNodes(left->left, right->right) && symmetricNodes(left->right, right->left);

    return false;
}

bool isSymmetric(Node* tree) 
{
    if (!tree) return true;
    
    return symmetricNodes(tree->left,tree->right);
}

void saveInOrder(Node* tree, std::vector<int>& keys) 
{
    if (!tree)  return;

    saveInOrder(tree->left,keys);
    keys.push_back(tree->key);
    saveInOrder(tree->right, keys);
}

bool isBST(Node* tree) 
{
    std::vector<int> keys;
    saveInOrder(tree, keys);
    
    for (size_t i = 0; i < keys.size() - 1; i++)  if (keys[i] > keys[i + 1]) return false;
    
    return true;
}