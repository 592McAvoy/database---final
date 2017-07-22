  #include "RBTree.h"

RBTree::RBTree()
{
	nullNode = new myRBNode(BLACK);
	nullNode->left = nullNode->right = nullNode;
	root = nullNode;
	fakeRoot = new myRBNode(BLACK, -999999999, nullNode, root);
}

RBTree::~RBTree()
{
	make_empty(root);
	delete nullNode;
}

void RBTree::insert(idxNode idx)
{
	if (idx == empty)//传入为空
		return ;
	myRBNode* node = my_insert(idx.key);
	if (node == NULL)//key已经存在
		return ;
	node->index = idx;	
}

myRBNode* RBTree::insert(int key)
{
	myRBNode* node= my_insert(key);
	
	return node;
}

idxNode RBTree::remove(int key)
{		
	if (!my_remove(key))
	{
		return empty;
	}	
	return result;
}

idxNode RBTree::fetch(int key)
{
	myRBNode* node = my_find(key);
	if (node == NULL)
	{
		return empty;
	}
	return node->getNode();	
}


void RBTree::save()
{
	ff.open("db.idx", ios::out | ios::binary);
	stack<myRBNode*> box;
	box.push(root);

	const int idxsize = 12;
	int count = 0;
	while (!box.empty())
	{
		myRBNode* temp = box.top();
		box.pop();
		idxNode idx = temp->getNode();
		idx.idxPos = count*idxsize;
		saveNode(idx);

		if (temp->left != nullNode)
			box.push(temp->left);
		if (temp->right != nullNode)
			box.push(temp->right);

		count++;
	}
	ff.close();

}


void RBTree::make_empty(myRBNode *& node)
{
	if (node == nullNode)
		return;
	make_empty(node->left);
	make_empty(node->right);
	delete node;
}

myRBNode * RBTree::my_find( const int &key)
{
	root = fakeRoot->right;
	if (root->mes==-1)
		return NULL;
	myRBNode* node = root;
	while (node != nullNode) {
		if (key < node->mes)
			node = node->left;
		else if (key > node->mes)
			node = node->right;
		else
			return node;
	}
	return NULL;
}

myRBNode* RBTree::my_insert(const int &key)
{
	current = parent = grand = fakeRoot;
	nullNode->mes = key;
	
	while (key != current->mes) {
		great = grand;
		grand = parent;
		parent = current;	
		if (key < current->mes) 
			current = current->left;
		else 
			current = current->right;
		if (current->left->color == RED&&current->right->color == RED)
			handleReorient(key);
	}
	nullNode->mes = -1;

	if (current != nullNode) return NULL;//existed key

	current = new myRBNode(RED, key, nullNode, nullNode);

	if (current->mes < parent->mes)
		parent->left = current;
	else
		parent->right = current;

	root = fakeRoot->right;
	root->color = BLACK;
	handleReorient(key);
	size++;
		
	return current;
}

void RBTree::handleReorient(const int &key)
{
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;

	if (parent->color == BLACK)return;

	grand->color = RED;
	if (key < parent->mes&&key < grand->mes) { //LL
		right_rot(grand,great);
		parent->color = BLACK;
	}
	else if (key > parent->mes&&key > grand->mes) {//RR
		left_rot(grand,great);
		parent->color = BLACK;
	}
	else if (key > parent->mes&&key < grand->mes) { //LR
		left_rot(parent,grand);
		right_rot(grand,great);
		current->color = BLACK;
	}
	else{									//RL		
		right_rot(parent,grand);
		left_rot(grand,great);
		current->color = BLACK;
	}
	
}

void RBTree::left_rot(myRBNode *& center, myRBNode*& center_f)
{
	myRBNode* temp = center->right;
	center->right = temp->left;
	temp->left = center;
	
	if (center == center_f->left)
		center_f->left = temp;
	else
		center_f->right = temp;
}

void RBTree::right_rot(myRBNode *& center, myRBNode*& center_f)
{
	myRBNode* temp = center->left;
	center->left = temp->right;
	temp->right = center;

	if (center == center_f->left)
		center_f->left = temp;
	else
		center_f->right = temp;
}

bool RBTree::my_remove(int & key)
{
	if (size == 0)
		throw(Error("Empty tree!"));

	ini_key = key;

	parent = grand = fakeRoot;
	brother = fakeRoot->left;
	current = fakeRoot->right;	

	while (current != nullNode) {
		if (current->left->color == BLACK&&current->right->color == BLACK) 
		{
			transfer_A();
			if (key != current->mes)
				basic_move(key);
			else
				key = find_key();
		}				
		else {
			if (key == current->mes)
				key = find_key();
			else
				basic_move(key);

			if (current->color == BLACK)
				transfer_B();
			else if (key != current->mes)
				basic_move(key);
			else
				key = find_key();
		}
	}
	fakeRoot->color = BLACK;
	root = fakeRoot->right;
	root->color = BLACK;
	if (del)
	{
		size--;
		del = false;
		return true;
	}
	return false;
}

void RBTree::basic_move(const int & key)
{
	if (key == current->mes)
		return;
	grand = parent;
	parent = current;
	if (key < current->mes) {
		brother = current->right;
		current = current->left;		
	}
	else {
		brother = current->left;
		current = current->right;		
	}
}

void RBTree::transfer_A()
{
	parent->color = BLACK;
	current->color = RED;

	if (brother->left->color == BLACK&&brother->right->color == BLACK) {
		if (brother != nullNode)
			brother->color = RED;
		return;
	}
	else
	{
		if (current == parent->left) 
		{
			if (brother->left->color == RED) {
				right_rot(brother, parent);
				left_rot(parent, grand);
				return;
			}
			else {
				brother->color = RED;
				brother->right->color = BLACK;
				left_rot(parent, grand);				
				return;
			}
		}
		else 
		{
			if (brother->right->color == RED) {
				left_rot(brother, parent);
				right_rot(parent, grand);
				return;
			}
			else {
				brother->color = RED;
				brother->left->color = BLACK;
				right_rot(parent, grand);				
				return;
			}
		}
	}
}

void RBTree::transfer_B()
{
	parent->color = RED;
	brother->color = BLACK;
	if (current == parent->left)
	{
		left_rot(parent, grand);
		grand = brother;
		brother = parent->right;
	}
	else
	{
		right_rot(parent, grand);
		grand = brother;
		brother = parent->left;
	}
}

int RBTree::find_key()
{
	int key;
	myRBNode* target;

	if (ini_key == current->mes)
	{
		result = current->index;
		del = true;
	}

	if (current->right == nullNode&&current->left == nullNode)
	{		
		key = current->mes;
		if (parent->left == current)
			parent->left = nullNode;
		else
			parent->right = nullNode;
		delete current;
		current = nullNode;
		return key;
	}
	else
	{
		if (current->right != nullNode)
		{
			target = find_succ(current);
			key = target->mes;
			current->mes = target->mes;
			current->index = target->index;

			grand = parent;
			parent = current;
			brother = parent->left;
			current = parent->right;			
		}
		else
		{
			target = find_prev(current);
			key = target->mes;
			current->mes = target->mes;
			current->index = target->index;

			grand = parent;
			parent = current;
			brother = parent->right;
			current = parent->left;
		}
		return key;
	}

}

myRBNode * RBTree::find_prev(myRBNode *& node)
{
	myRBNode *temp = node->left;
	while (temp->right != nullNode)
	{
		temp = temp->right;
	}
	return temp;
}

myRBNode * RBTree::find_succ(myRBNode *& node)
{
	myRBNode *temp = node->right;
	while (temp->left != nullNode)
		temp = temp->left;
	return temp;
}

void RBTree::saveNode(idxNode idx)
{
	ff.seekp(idx.idxPos);
	ff.write((char*)&idx, sizeof idx);
}
	


