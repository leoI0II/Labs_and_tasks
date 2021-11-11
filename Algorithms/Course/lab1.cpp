#include<iostream>
#include<initializer_list>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>


// class tree_element{
// public:
//     tree_element(int _key, tree_element* p = nullptr, tree_element* _left = nullptr, tree_element* _right = nullptr) :
//         key(_key), parent(p), left(_left), right(_right){}
    
//     int key;
//     tree_element* parent;
//     tree_element* left;
//     tree_element* right;
    
// };

// class tree{
//     tree_element* root;
//     tree_element* last_w;
// public:
//     tree(tree_element* _root = nullptr) : root(_root), last_w(_root) {}

//     void append_child(tree_element* ch){
//         if (last_w->left) {
//             last_w->right = ch;
//         }
//         else {
//             last_w->left = ch;
//         }
//         last_w = ch;
//     }

// };

void check_list(const initializer_list<int>& list){
    for (auto& elem: list)
        cout << elem << " ";
    cout << endl;
}

// vector<bool> used;

// void dfs(int node_index)
// {
//     used[node_index] = true;
//     for (auto i : graph[node_index])
//     {
//         if (!used[i])
//             dfs(i);
//     }
// }


class Tree{
private:
    map<int, vector<int>> tree;
    int tree_root;
    int parent_count;
    int tree_height;

    void find_height(int root, vector<int>& cur_len, int cur_height){

        for(auto& child: tree[root])
            find_height(child, cur_len, cur_height + 1);
        cur_len.push_back(cur_height);
    }


    // void find_height(int root, vector<int>& cur_len, int cur_height){
    //     tree_height = cur_height;
    //     // vector<int> tmp_height;
    //     for (auto& child: tree[root]){
    //         // tree_height = std::max(1 + find_height(child, cur_height + 1), tree_height);
    //         find_height(child, cur_height + 1);
    //     }
    //     // for (int i = 0; i < tree[root].size(); i++){
    //     //     tree_height = std::max(1 + find_height(tree[root][i]), tree_height);
    //     // }
    //     // return tree_height;
    //     // map<int, vector<int>>::iterator it = tree.begin();
    //     // for (map<int, vector<int>>::iterator it = tree.begin(); it != tree.end(); it++){
    //     //     vector<bool> used(parent_count, false);
    //     //     tmp_height.push_back(dfs(root, it, used));
    //     // }
    //     // auto it = max_element(begin(tmp_height), end(tmp_height));
    //     // return *it;
    // }
    // int dfs(int node_index, map<int, vector<int>>::iterator childs, vector<bool>& used)
    // {
    //     int tmp_max = 0;
    //     used[node_index] = true;
    //     // for (int& ch : childs->second[node_index])
    //     // {
    //     //     if (!used[ch])
    //     //         dfs(ch, childs, used);
    //     // }
    //     for(vector<int>::iterator it = childs->second.begin(); it != childs->second.end(); it++){
    //         if (!used[*it])
    //             tmp_max = dfs(*it, childs, used);
    //     }
    //     return tmp_max;
    // }
    // int find_height(int root){
    //     used[root] = true;
    //     for (auto i: tree[root]){
    //         if (!used[i])
    //             find_height(i);
    //     }
    // }
public:
    Tree(const vector<int>& tree_parents){
        if (tree_parents.size() == 0){
            tree_height = 0;
            return;
        }

        parent_count = tree_parents.size();
        for (int i = 0; i < tree_parents.size(); i++)
            if (tree_parents[i] == -1){
                tree_root = i;
                break;
            }

        for (int i = 0; i < tree_parents.size(); i++){
            if (tree_parents[i] == -1)
                continue;
            vector<int> childs;
            for (int j = i; j < tree_parents.size(); j++){
                if (tree_parents[j] == tree_parents[i])
                    childs.push_back(j);
            }
            tree.insert(pair<int, vector<int>>(tree_parents[i], childs));
        }

        // tree.erase(-1);
        
        vector<int> cur_len;
        find_height(tree_root, cur_len, 1);
        vector<int>::iterator it = max_element(begin(cur_len), end(cur_len));
        tree_height = *it;

    }
    void print_tree() const {
        for (auto& parents: tree){
            cout << "Key: " << parents.first << ", value: ";
            for (int i = 0; i < parents.second.size(); i++)
                cout << parents.second[i] << ", ";
            cout << endl;
        }
    }

    int height() const{
        return tree_height;
    }

};



int main(){

    int n;
    cin >> n;

    vector<int> par(n);

    for (int& p: par)
        cin >> p;

    Tree a(par);

    a.print_tree();

    cout << a.height() << endl;

    return 0;
}