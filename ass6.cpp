#include <iostream>

using namespace std;

class node{
    public :
        string name;
        double score;
        node *left, *right;
        void set_data(string s, double n);
};

void node::set_data(string s, double n){
    name = s;
    score = n;
}

class my_tree{
    public:
        int node_count;
        node *root;
        my_tree();

        int insert_root(node t);
        int insert_left(string tname, node t);
        int insert_right(string tname, node t);

        double score_sum();
        double score_average();
        void  print_data_inorder(); 
        void  print_data_preorder();
        void  print_data_postorder();

        int n_d2_nodes();
        int n_d1_nodes();
        int n_leaf_nodes();
};

int node_insert_left(node *p, string tname, node tnode);
int node_insert_right(node *p, string tname, node tnode);
double sum_allnodes(node *p);
void inorder_print(node *p);
void preorder_print(node *p);
void postorder_print(node *p);

int n_d2_nodes_count(node* p);
int n_d1_nodes_count(node* p);
int n_leaf_count(node* p);

my_tree::my_tree(){
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t){
    if (root != NULL)
        return 0;
    node *p;
    p = new node;
    (*p) = t;

    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count ++;
    return 1;
}

int my_tree::insert_left(string tname, node tnode){
    int result = 0;

    result = node_insert_left(root,tname,tnode);
    if(result == 1)
        node_count++;
        return result;
}

int node_insert_left(node *p, string tname, node tnode){
    if(p == NULL)
        return 0;
    if(p->name == tname){
        if(p->left != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;

        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else{
        int result = 0;

        result = node_insert_left(p->left,tname,tnode);
        if(result != 0)
            return result;
        return node_insert_left(p->right,tname,tnode);
    }
}

int my_tree::insert_right(string tname, node tnode){
    int result = 0;

    result = node_insert_right(root,tname,tnode);
    if(result == 1)
        node_count++;
        return result;
}

int node_insert_right(node *p, string tname, node tnode){
    if(p == NULL)
        return 0;
    if(p->name == tname){
        if(p->right != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;

        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }
    else{
        int result = 0;

        result = node_insert_right(p->right,tname,tnode);
        if(result != 0)
            return result;
        return node_insert_right(p->left,tname,tnode);
    }
}

double my_tree::score_sum(){
    return sum_allnodes(root);
}

double sum_allnodes(node *p)
{
    if (p == NULL)
    return 0;
    return 
    sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_average(){
    double average = 0;
    average = sum_allnodes(root);
    average = average/node_count;

    return average;
}
void  my_tree::print_data_inorder(){
    inorder_print(root);
}

void inorder_print(node *p)
{
if (p == NULL) return;
    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void  my_tree::print_data_preorder(){
    preorder_print(root);
}


void preorder_print(node *p)
{
if (p == NULL) return;

    cout << p->name << " : " << p->score << "\n";
    preorder_print(p->left);
    preorder_print(p->right);
}

void  my_tree::print_data_postorder(){
    postorder_print(root);
}

void postorder_print(node *p)
{
if (p == NULL) return;

    postorder_print(p->left);
    postorder_print(p->right);
    cout <<p->name << " : " << p->score << "\n";
}

int my_tree::n_d2_nodes(){
    int count = 0;

    count = n_d2_nodes_count(root);

        return count;
}

int n_d2_nodes_count(node* p){
    if(p == NULL)
        return 0;

    int count = 0;

    if(p->left != NULL && p->right != NULL)
        count = 1;

    count += n_d2_nodes_count(p->left) + n_d2_nodes_count(p->right);

    return count;
}

int my_tree::n_d1_nodes(){

    int count = 0;

    count = n_d1_nodes_count(root);

        return count;
}

int n_d1_nodes_count(node* p){
    if(p == NULL)
        return 0;

    int count = 0;

    if((p->left != NULL && p->right == NULL)|| (p->left == NULL&& p -> right != NULL))
        count = 1;
    
    count += n_d1_nodes_count(p->left) + n_d1_nodes_count(p->right);

    return count;
}

int my_tree::n_leaf_nodes(){
    int count = 0;

    count = n_leaf_count(root);


        return count;
}

int n_leaf_count(node* p){
    if(p == NULL)
        return 0;

    int count = 0;

    count = n_leaf_count(p->left) + n_leaf_count(p->right);

    if(p->left == NULL && p->right == NULL)
        count ++;

    return count;
}

int main()
{
        my_tree  thetree;
        node  tmp;
        tmp.set_data("Kim", 81.1);
        thetree.insert_root(tmp);
        tmp.set_data("Lee", 86.2);
        thetree.insert_left("Kim", tmp);
        tmp.set_data("Park", 79.4);
        thetree.insert_right("Kim", tmp);
        tmp.set_data("Choi", 77.8);
        thetree.insert_left("Lee", tmp);
        tmp.set_data("Ryu", 92.2);
        thetree.insert_right("Lee", tmp);
        tmp.set_data("Cho", 68.6);
        thetree.insert_right("Park", tmp);
        tmp.set_data("Yang", 72.8);
        thetree.insert_left("Ryu", tmp);
        tmp.set_data("Jung", 62.3);
        thetree.insert_left("Cho", tmp);

        cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl;  // degree 2인 node 수
        cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl; // degree 1인 node 수
        cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;      // leaf node 수

        return 0;
}
