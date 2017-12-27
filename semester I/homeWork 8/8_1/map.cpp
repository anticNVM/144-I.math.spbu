#include "map.h"
#include <iostream>
#include <string>
#include <queue>
#include <assert.h>

using namespace std;

struct SplayNode {
    string key = "";
    string value = "";
    SplayNode* parent = nullptr;
    SplayNode* leftChild = nullptr;
    SplayNode* rightChild = nullptr;
};

struct Map {
    SplayNode* root = nullptr;
};

void splay(SplayNode* tree, SplayNode* node);
SplayNode* findNode(SplayNode* tree, const string& key);

Map* createMap()
{
    return new Map{};
}

void deleteRecursively(SplayNode* node)
{
    if (node->leftChild) {
        deleteRecursively(node->leftChild);
    }
    if (node->rightChild) {
        deleteRecursively(node->rightChild);
    }
    delete node;
}

void deleteMap(Map* map)
{
    if (map->root) {
        deleteRecursively(map->root);
    }
    delete map;
}

void add(Map* map, const string& key, const string& value)
{
    SplayNode* newNode = new SplayNode{};
    newNode->key = key;
    newNode->value = value;
    if (map->root == nullptr) {
        map->root = newNode;
        return;
    }
    SplayNode* current = map->root;
    bool flag = true;
    while (flag) {
        if (key < current->key) {
            if (current->leftChild == nullptr) {
                newNode->parent = current;
                current->leftChild = newNode;
                current = current->leftChild;
                flag = false;
            } else {
                current = current->leftChild;
            }
        } else if (key > current->key) {
            if (current->rightChild == nullptr) {
                newNode->parent = current;
                current->rightChild = newNode;
                current = current->rightChild;
                flag = false;
            } else {
                current = current->rightChild;
            }
        } else {
            current->value = value;
            delete newNode;
            flag = false;
        }
    }
    splay(map->root, current);
    map->root = current;
}

string getValue(Map* map, const string& key)
{
    SplayNode* node = findNode(map->root, key);
    if (node == nullptr) {
        return "";
    } else {
        splay(map->root, node);
        map->root = node;
        return node->value;
    }
}

bool isExists(Map* map, const string& key)
{
    SplayNode* node = findNode(map->root, key);
    if (node == nullptr) {
        return false;
    } else {
        splay(map->root, node);
        map->root = node;
        return true;
    }
}

void remove(Map* map, const string& key)
{
    SplayNode* node = findNode(map->root, key);
    if (node == nullptr)
        return;
    splay(map->root, node);
    if (node->leftChild == nullptr && node->rightChild == nullptr) {
        map->root = nullptr;
    } else if (node->leftChild == nullptr) {
        map->root = node->rightChild;
        node->rightChild = nullptr;
    } else if (node->rightChild == nullptr) {
        map->root = node->leftChild;
        node->leftChild = nullptr;
    } else {
        SplayNode* maxInLeft = node->leftChild;
        while (maxInLeft->rightChild != nullptr) {
            maxInLeft = maxInLeft->rightChild;
        }
        splay(node->leftChild, maxInLeft);
        maxInLeft->rightChild = node->leftChild;
        map->root = maxInLeft;
        maxInLeft->parent = nullptr;
    }
    delete node;
}

SplayNode* findNode(SplayNode* tree, const string& key)
{
    SplayNode* current = tree;
    while (current != nullptr) {
        if (key < current->key) {
            current = current->leftChild;
        } else if (key > current->key) {
            current = current->rightChild;
        } else {
            return current;
        }
    }
    return nullptr;
}

void rotate(SplayNode* node) {
    SplayNode* parent = node->parent;
    assert(parent != nullptr);
    SplayNode* gparent = parent->parent;

    if (node->key < parent->key) {
        if (node->rightChild) {
            node->rightChild->parent = parent;
        }
        parent->leftChild = node->rightChild;
        node->rightChild = parent;
    } else {
        if (node->leftChild) {
            node->leftChild->parent = parent;
        }
        parent->rightChild = node->leftChild;
        node->leftChild = parent;
    }
    parent->parent = node;

    if (gparent == nullptr) {
        node->parent = nullptr;
        return;
    }
    if (node->key < gparent->key) {
        gparent->leftChild = node;
    } else {
        gparent->rightChild = node;
    }
    node->parent = gparent;
}

// теперь node - корень
void zig(SplayNode* node)
{
    rotate(node);
}

void zigZig(SplayNode* node)
{
    rotate(node->parent);
    rotate(node);
}

void zigZag(SplayNode* node)
{
    rotate(node);
    rotate(node);
}

void splay(SplayNode *tree, SplayNode *node)
{
    SplayNode* treeParent = tree->parent;
    SplayNode* parent = node->parent;
    if (parent == tree->parent) {
        return;
    }
    SplayNode* gparent = parent->parent;
    if (gparent == tree->parent) {
        zig(node);
        return;
    }
    if (node->key < parent->key) {
        if (parent->key < gparent->key) {
            zigZig(node);
        } else {
            zigZag(node);
        }
    } else {
        if (parent->key > gparent->key) {
            zigZig(node);
        } else {
            zigZag(node);
        }
    }
    if (treeParent != tree->parent) {
        tree = node;
    }
    splay(tree, node);
}

void printRoot(Map* map)
{
    (map->root) ? (cout << map->root->key << endl) : (cout << "NULL" << endl);
}

void printTree(Map* map)
{
    queue<SplayNode*> que;
    que.push(map->root);
    while (que.size() > 0) {
        SplayNode* current = que.front();
        que.pop();
        if (current == nullptr)
            continue;

        cout << "(";
        (current->leftChild) ? (cout << current->leftChild->key) : (cout << "NULL");
        cout << " " << current->key << " ";
        (current->rightChild) ? (cout << current->rightChild->key) : (cout << "NULL");
        cout << ") : ";
        cout << (current->parent ? current->parent->key : "NULL") << endl;
        que.push(current->leftChild);
        que.push(current->rightChild);
    }
}

//void printRecursively(SplayNode* node, int n)
//{
//    if (node->leftChild) {
//        printRecursively(node->leftChild, n + 1);
//    }
//    for (int i = 0; i < n; ++i) {
//        cout << " ";
//    }
//    cout << node->key << endl;
//    if (node->rightChild) {
//        printRecursively(node->rightChild, n + 1);
//    }
//}

//void print(Map* map)
//{
//    if (map->root == nullptr) {
//        cout << "kek" << endl;
//        return;
//    }
//    printRecursively(map->root, 0);
//    cout << endl;
//}
