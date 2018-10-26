#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>

class binarytree
{
    public:
        int _size;
        std::vector<int>  tree;
        binarytree();
        int lleaf(int);
        int rleaf(int);
        int parent(int);
        void push(int);
        void up(int);
        void down(int);
        void _delete();
        virtual ~binarytree();

    protected:

    private:
};

#endif // BINARYTREE_H
