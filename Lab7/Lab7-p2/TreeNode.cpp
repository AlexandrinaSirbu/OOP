#include "TreeNode.h"
#include <stdexcept>

TreeNode::TreeNode(int val, TreeNode* par) : value(val), parent(par), children(nullptr), nextSibling(nullptr) {}


void TreeNode::delete_children(TreeNode* node) {
    while (node != nullptr) {
        TreeNode* next = node->nextSibling;
        delete node;
        node = next;
    }
}

TreeNode::~TreeNode() {
    delete_children(children);
}


void TreeNode::add_node(TreeNode* node) {
    if (children == nullptr) {
        children = node;
    }
    else {
        TreeNode* temp = children;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = node;
    }
    node->parent = this;
}

TreeNode& TreeNode::get_node(TreeNode* parentPtr) {
    if (parentPtr == nullptr) {
        return *this;
    }
    TreeNode* temp = children;
    while (temp != nullptr) {
        if (temp->parent == parentPtr) {
            return *temp;
        }
        temp = temp->nextSibling;
    }
    throw std::invalid_argument("Parent node not found.");
}

void TreeNode::delete_node() {
    if (parent != nullptr) {
        if (parent->children == this) {
            parent->children = nextSibling;
        }
        else {
            TreeNode* temp = parent->children;
            while (temp != nullptr && temp->nextSibling != this) {
                temp = temp->nextSibling;
            }
            if (temp != nullptr) {
                temp->nextSibling = nextSibling;
            }
        }
    }
    delete this;
}

TreeNode* TreeNode::find(std::function<bool(int)> compare) {
    if (compare(value)) {
        return this;
    }
    TreeNode* temp = children;
    while (temp != nullptr) {
        TreeNode* result = temp->find(compare);
        if (result != nullptr) {
            return result;
        }
        temp = temp->nextSibling;
    }
    return nullptr;
}

void TreeNode::insert(TreeNode* node, int index) {
    if (index == 0) {
        node->nextSibling = children;
        children = node;
    }
    else {
        TreeNode* temp = children;
        for (int i = 0; i < index - 1; ++i) {
            if (temp == nullptr) {
                throw std::out_of_range("Index out of range.");
            }
            temp = temp->nextSibling;
        }
        if (temp == nullptr) {
            throw std::out_of_range("Index out of range.");
        }
        node->nextSibling = temp->nextSibling;
        temp->nextSibling = node;
    }
    node->parent = this;
}

void TreeNode::sort(std::function<bool(int, int)> compare) {
    if (compare == nullptr) {
        compare = [](int a, int b) { return a < b; };
    }
    TreeNode* curr = children;
    while (curr != nullptr) {
        TreeNode* next = curr->nextSibling;
        while (next != nullptr) {
            if (compare(next->value, curr->value)) {
                int temp = next->value;
                next->value = curr->value;
                curr->value = temp;
            }
            next = next->nextSibling;
        }
        curr = curr->nextSibling;
    }
}

int TreeNode::count(TreeNode* nodePtr) const {
    if (nodePtr == nullptr)
        nodePtr = children;

    int count = 0;
    while (nodePtr != nullptr) {
        count++;
        count += nodePtr->count(nodePtr->children);
        nodePtr = nodePtr->nextSibling;
    }
    return count;
}

