#pragma once

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
	void _delete(int);
	virtual ~binarytree();

protected:

private:
};


