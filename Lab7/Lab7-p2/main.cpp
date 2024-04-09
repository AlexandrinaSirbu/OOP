#include <iostream>
#include "TreeNode.h"

int main() {
    TreeNode* root = new TreeNode(15);
    TreeNode* child1 = new TreeNode(18);
    TreeNode* child2 = new TreeNode(20);
    TreeNode* child3 = new TreeNode(44);

    root->add_node(child1);
    root->add_node(child2);
    root->add_node(child3);

    TreeNode* foundNode = root->find([](int val) { return val == 26; });
    if (foundNode != nullptr) {
        std::cout << "Node with value 26 found!" << std::endl;
    }
    else {
        std::cout << "Node with value 26 not found!" << std::endl;
    }

    root->get_node().insert(new TreeNode(25), 1);

    root->sort();

    TreeNode* temp = root->get_children();
    while (temp != nullptr) {
        std::cout << temp->get_value() << " ";
        temp = temp->get_next_sibling();
    }
    std::cout << std::endl;

    std::cout << "Number of children: " << root->count() << std::endl;

    root->delete_node();

    return 0;
}
