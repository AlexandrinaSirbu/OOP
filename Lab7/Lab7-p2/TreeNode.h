#pragma once
#include <iostream>
#include <functional>

    class TreeNode {
    private:
        int value;
        TreeNode* parent;
        TreeNode* children;
        TreeNode* nextSibling;

    public:
        TreeNode(int val, TreeNode* par = nullptr);
        ~TreeNode();
        void add_node(TreeNode* node);
        TreeNode& get_node(TreeNode* parentPtr = nullptr);
        void delete_node();
        void delete_children(TreeNode* node);
        TreeNode* find(std::function<bool(int)> compare);
        void insert(TreeNode* node, int index);
        void sort(std::function<bool(int, int)> compare = nullptr);
        int count(TreeNode* nodePtr = nullptr) const;
        TreeNode* get_children() const { return children; }
        int get_value() const { return value; }
        TreeNode* get_next_sibling() const { return nextSibling; }
};
