#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cassert>
using namespace std;

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


public:
    Tree(const vector<int>& tree_parents){
        if (tree_parents.size() == 0){
            tree_height = 0;
            return;
        }

        parent_count = tree_parents.size();
        tree_root = -1;
        for (int i = 0; i < tree_parents.size(); i++)
            if (tree_parents[i] == -1){
                tree_root = i;
                break;
            }
        if (tree_root == -1){
            tree_height = -1;
            return;
        }
        vector<bool> check_parent(parent_count, false);
        for (int i = 0; i < tree_parents.size(); i++){
            if (tree_parents[i] == -1)
                continue;
            vector<int> childs;

            if (!check_parent[tree_parents[i]])
                check_parent[tree_parents[i]] = true;
            else
                continue;

            for (int j = i; j < tree_parents.size(); j++){
                if(tree_parents[j] == j)
                    continue;
                else if (tree_parents[j] == tree_parents[i])
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

    void obrat(int cur_root){
        if (tree[cur_root].empty()){
            cout << cur_root << " ";
            return;
        }
        for (auto& elem: tree[cur_root]){
            obrat(elem);
        }
        cout << cur_root << " ";
    }

    int height() const{
        return tree_height;
    }    
    int root() const{
        return tree_root;
    }
};

// void TEST(Tree& obj, int correct_answer){
//     static int i = 0;
//     assert(obj.height() == correct_answer);
//     cout << ++i << ": ok" << endl;
// }

int main(){

    int n;
    cin >> n;

    vector<int> par(n);
    for (int& p: par)
        cin >> p;

    Tree a(par);
    a.print_tree();
    cout << a.height() << endl;

    // cout << endl;
    // a.obrat(a.root());

    // Tree t1({4, -1, 4, 1, 1}); TEST(t1, 3);

    // Tree t2({-1, 0, 4, 0, 3}); TEST(t2, 4);

    // Tree t3({9, 7, 5, 5, 2, 9, 9, 9, 2, -1}); TEST(t3, 4);

    // Tree t4({6, 6, 6, 6, 6, 2, -1, 2}); TEST(t4, 3);

    // Tree t5({}); TEST(t5, 0);

    // Tree t6({5, -1, 1, 1, 1, 6, 4}); TEST(t6, 5);

    // Tree t7({9, 2, -1, 1, 3, 4, 0, 4, 9, 7}); TEST(t7, 8);

    // Tree t8({9, 2}); TEST(t8, -1);

    return 0;
}