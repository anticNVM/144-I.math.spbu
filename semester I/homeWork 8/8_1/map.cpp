#include "map.h"
#include <string>

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

void deleteMap(Map* map)
{
    // TODO
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
                flag = false;
            } else {
                current = current->leftChild;
            }
        } else if (key > current->key) {
            if (current->rightChild == nullptr) {
                newNode->parent = current;
                current->rightChild = newNode;
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
    // TODO
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
