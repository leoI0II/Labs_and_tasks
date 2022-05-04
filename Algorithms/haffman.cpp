#include<iostream>
#include<map>
#include<algorithm>
#include<list>
#include<vector>
#include<string>

struct Node{
    Node() {}
    Node(Node* l, Node* r) : left(l), right(r) {
        quant = left->quant + right->quant;
    }
    
    size_t quant;
    char sym = 0;
    Node* left;
    Node* right;
};

struct compare{
    bool operator()(Node* a, Node* b){
        return a->quant < b->quant;
    }
};


class Haffman{
public:

    Haffman(const std::string& _str) : str(_str){
        for (int i = 0; i < str.size(); i++){
            dict[str[i]]++;
        }

        
        for (auto it = dict.begin(); it != dict.end(); ++it){
            Node* p = new Node;
            p->quant = it->second;
            p->sym = it->first;
            l.push_back(p);
        }

        while(l.size() != 1){
            l.sort(compare());

            Node* leftCh = l.front();
            l.pop_front();

            Node* rightCh = l.front();
            l.pop_front();

            Node* parent = new Node(leftCh, rightCh);
            l.push_back(parent);
        }
        root = l.front();

        BuildCodeTable(root);

    }

    void BuildCodeTable(Node* root){
        if(root->left){
            tmpCode.push_back('0');
            BuildCodeTable(root->left);
        }
        if (root->right){
            tmpCode.push_back('1');
            BuildCodeTable(root->right);
        }
        if (root->sym) codeTable[root->sym] = tmpCode;
        tmpCode.pop_back();
    }

    const std::string& operator[](char ch){
        return codeTable[ch];
    }
    void showTable() const {
        for (auto it = codeTable.begin(); it != codeTable.end(); ++it)
            std::cout << it->first << " : " << it->second << std::endl;
    }
    std::map<char, std::string>& getCodeTable(){
        return codeTable;
    }

private:

    std::string str;
    std::map<char, size_t> dict;
    std::list<Node*> l;
    Node* root;

    std::string tmpCode;
    std::map<char, std::string> codeTable;

};



int main(){




    std::string str("hello world,Dzappala!");
    Haffman a(str);

    a.showTable();

    // std::string codeStr;

    // std::map<std::string, char> dec;

    // for (int i = 0; i < str.size(); i++){
    //     codeStr += a[str[i]];
    //     dec[a[str[i]]] = str[i];
    // }
    // std::cout << codeStr << std::endl;

    // std::string tmp;
    // for (int i = 0; i < codeStr.size(); ++i){
    //     tmp.push_back(codeStr[i]);
    //     for (auto it = dec.begin(); it != dec.end(); ++it){
    //         if (it->first == tmp){
    //             std::cout << it->second;
    //             tmp.clear();
    //         }
    //     }
    // }
    // std::cout << std::endl;



    // std::map<char, std::string> table = a.getCodeTable();
    
    // size_t f = codeStr.find(" ");
    // std::cout << f << std::endl;
    // std::string ne = codeStr.substr(0, f);
    // std::cout << ne << std::endl;


    // std::map<char, std::string> table = a.getCodeTable();
    // std::vector<std::pair<char, std::string>> dec;

    // for (int i = 0; i < codeStr.size() ; ++i){
    //     for (int j = 0; j < dec.size(); ++j){
    //         if (dec[j].second)
    //     }
    // }




    return 0;
}