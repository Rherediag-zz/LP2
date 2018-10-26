#include "binarytree.h"

binarytree::binarytree()
{
    //ctor
}

binarytree::~binarytree()
{
    //dtor
}
int binarytree::lleaf(int pos_parent){
    return (2*pos_parent)+1;
}

int binarytree::rleaf(int pos_parent){
    return (2*pos_parent)+2;
}
int binarytree::parent(int pos_leaf){
    return (pos_leaf-1)/2;

}
void binarytree::down(int x){

    if(rleaf(x)>=tree.size())
        if(tree[x]<tree[lleaf(x)])
            std::swap(tree[x],tree[lleaf(x)]);
    else{
        if(tree[lleaf(x)]>tree[rleaf(x)]){
            if(tree[x]<tree[lleaf(x)])
                std::swap(tree[x],tree[lleaf(x)]);
            if(tree[x]<tree[lleaf(x)])
                std::swap(tree[x],tree[rleaf(x)]);
    }
    }
}
void binarytree::up(int x){

    while(tree[x]>(tree[x]-1)/2)
        std::swap(tree[x],(tree[x]-1)/2);

}
void binarytree::push(int x){
    tree.push_back(x);
    up(tree.size()-1);
}
