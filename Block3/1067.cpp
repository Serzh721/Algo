#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Tree {
    Tree() {
        this->name = "";
        this->children = {};
    }

    Tree(string name) {
        this->name = name;
        this->children = {};
    }

    string name;
    map<string, Tree *> children;
};

void print(Tree *tree, int level) {
    for (int i = 0; i < level - 1; i++) {
        cout << " ";
    }
    if (!tree->name.empty()) {
        cout << tree->name << endl;
    }
    level++;
    for (auto &child_tree : tree->children) {
        print(child_tree.second, level);
    }
}

int main() {
    int N;
    cin >> N;
    string curr_dir;
    Tree *empty_root = new Tree();

    for (int i = 0; i < N; ++i) {
        string curr_string;
        cin >> curr_string;

        curr_dir = "";
        Tree *curr_level = empty_root;

        for (int j = 0; j <= curr_string.size(); ++j) {
            if (curr_string[j] == '\\' || curr_string[j] == '\0') {
                auto dir_found = curr_level->children.find(curr_dir);

                if (dir_found == curr_level->children.end()) {
                    Tree *new_tree = new Tree(curr_dir);
                    curr_level->children[curr_dir] = new_tree;
                    curr_level = new_tree;
                } else {
                    curr_level = dir_found->second;
                }
                curr_dir = "";
            } else curr_dir += curr_string[j];
        }

    }
    print(empty_root, 0);
}
