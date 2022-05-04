#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<iomanip>


#define     INSERTED    "\033[1;33m"            //yellow
#define     FINDED      "\033[4;35m"            //magenta
#define     RESET       "\033[0m"

struct node {
	int			key;
	uint8_t		height;

	node*		left;
	node*		right;

    bool        inserted;
    bool        catched;

	node(int k, node* leftC = nullptr, node* rightC = nullptr) : 
			key(k), left(leftC), right(rightC), height(1), inserted(true), catched(false) {}

};

const int   spacesCount     = 5;
size_t      steps           = 0;

class AVL_Tree {
public:
	AVL_Tree(node* _root = nullptr) : root(_root) {}

	void insert(int k)
	{
		root = insert(root, k);
	}

	node* search(int k) {
		return find(root, k);
	}

    void showTree(){
        print(root, 0);
    }

    node* Delete(int k){
        root = remove(root, k);
    }

private:

    node* remove(node* p, int k) // удаление ключа k из дерева p
    {
        if( !p ) return 0;
        if( k < p->key )
            p->left = remove(p->left,k);
        else if( k > p->key )
            p->right = remove(p->right,k);	
        else //  k == p->key 
        {
            node* q = p->left;
            node* r = p->right;
            delete p;
            if( !r ) return q;
            node* min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
	}

	node* find(node* v, int k) {
		if (v == nullptr)
			return nullptr;
        std::cout << "Step " << ++steps << std::endl;
		v->catched = true;
        showTree();
        if (k < v->key) {
            std::cout << std::endl << k << " is less than " << v->key << ", so we go left." << std::endl;
			return find(v->left, k);
		}
		else if (k > v->key) {
            std::cout << std::endl << k << " is bigger than " << v->key << ", so we go right." << std::endl;
			return find(v->right, k);
		}
		else
			return v;
	}
    node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
    {
        if( p->left==0 )
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    node* findmin(node* p) // поиск узла с минимальным ключом в дереве p 
    {
        return p->left?findmin(p->left):p;
    }

	node* insert(node* v, int k)
	{
        std::cout << "Step " << ++steps << std::endl;
		if (!v) return new node(k);
        v->catched = true;
        showTree();
		if (k < v->key){
            std::cout << std::endl << k << " is less than " << v->key << ", so we go left." << std::endl;
			v->left = insert(v->left, k);
        }
		else{
            std::cout << std::endl << k << " is bigger than " << v->key << ", so we go right." << std::endl;
			v->right = insert(v->right, k);
        }
		return balance(v);
	}
	uint8_t getHeight(node* v) {
		return (v ? v->height : 0);
	}

	int balanceFactor(node* v) {
		return getHeight(v->right) - getHeight(v->left);
	}

	void fixHeight(node* v) {
		uint8_t hl = getHeight(v->left);
		uint8_t hr = getHeight(v->right);

		v->height = (hl > hr ? hl : hr) + 1;
	}

	node* rotateRight(node* v) {
        std::cout << std::endl <<
            "---------------------Right rotation "<< v->key << "-------------------" << std::endl << std::endl;
		node* q = v->left;

		v->left = q->right;
		q->right = v;

		fixHeight(v); fixHeight(q);

		return q;
	}

	node* rotateLeft(node* v) {
        std::cout << std::endl <<
            "---------------------Left rotation "<< v->key << "-------------------" << std::endl << std::endl;
		node* q = v->right;

		v->right = q->left;
		q->left = v;

		fixHeight(v); fixHeight(q);

		return q;
	}

	node* balance(node* v)
	{
		fixHeight(v);
		if (balanceFactor(v) == 2)
		{
			if (balanceFactor(v->right) < 0)
				v->right = rotateRight(v->right);
			return rotateLeft(v);
		}
		if (balanceFactor(v) == -2)
		{
			if (balanceFactor(v->left) > 0)
				v->left = rotateLeft(v->left);
			return rotateRight(v);
		}
		return v;
	}

    void print(node* root, int spaces){
        if (!root) return;

        spaces += spacesCount;
        print(root->right, spaces);

        std::cout << std::endl;
        for (int i = spacesCount; i < spaces; ++i){
            std::cout << " ";
        }
        // std::cout << root->key << std::endl;
        if (root->inserted){
            std::cout << INSERTED << root->key << RESET << std::endl;
            root->inserted = false;
        }
        else if (root->catched){
            std::cout << FINDED << root->key << RESET << std::endl;
            root->catched = false;
        }
        else{
            std::cout << root->key << std::endl;
        }
        print(root->left, spaces);
    }

	node* root;

};


int main(int argc, char* argv[]){

    AVL_Tree tree;

    if (argc > 1){
        std::cout << "-----------Insertion procedure, key = " << std::stoi(argv[1]) << "-----------" << std::endl;
        tree.insert(std::stoi(argv[1]));
        tree.showTree();
        for (int i = 2; i < argc; i++){
            steps = 0;
            std::cout << "-----------Insertion procedure, key = " << std::stoi(argv[i]) << "-----------" << std::endl;
            tree.insert(std::stoi(argv[i]));
            tree.showTree();
            std::cout << std::endl << std::endl;
        }
    }

    std::string command;
    int vert;

    std::cout << "Enter command: ";
    std::cin >> command;
    while(command != "exit"){
        std::cin >> vert;
        if (command == "insert"){
            steps = 0;
            std::cout << "-----------Insertion procedure, key = " << vert << "-----------" << std::endl;
            tree.insert(vert);
            tree.showTree();
            std::cout << std::endl << std::endl;
        }
        if (command == "find"){
            steps = 0;
            std::cout << "-----------Find procedure, key = " << vert << "-----------" << std::endl;
            node* tmpF = tree.search(vert);
            if (tmpF){
                std::cout << std::endl << tmpF->key << " was found!" << std::endl << std::endl;
            }
            else{
                std::cout << std::endl << vert << " there is no such key in tree!" << std::endl << std::endl;
            }
        }
        if(command == "delete"){
            tree.Delete(vert);
            tree.showTree();
        }
        std::cout << "Enter command: ";
        std::cin >> command;
    }



    return 0;
}