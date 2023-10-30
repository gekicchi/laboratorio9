#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node{
	string letra;
	Node *left;
	Node *right;
	
	Node(string l) : letra(l), left(nullptr), right(nullptr) {}
};

// funciones de impresion
void print_pre_order(Node *current);
void print_in_order(Node *current);
void print_post_order(Node *current);

// funciones de busqueda
Node* DFS(Node *current, string value);
Node* BFS(Node *root, string value);

int main()
{
	Node *root = new Node("M");
	root->left = new Node("C");
	root->right = new Node("Z");
	root->left->left = new Node("X");
	root->left->right = new Node("O");
	root->right->left = new Node("T");
	root->right->right = new Node("F");
	root->right->left->left = new Node("W");
	
	cout << "pre-order: ";
	print_pre_order(root);
	cout << endl << "in-order ";
	print_in_order(root);
	cout << endl << "post-order: ";
	print_post_order(root);
	cout << endl;
	
	Node *searchDFS = DFS(root, "O");
	if (searchDFS != nullptr)
		cout << "Encontrado: " << searchDFS->letra << endl;
		
	Node *searchBFS = BFS(root, "C");
	if (searchBFS != nullptr)
		cout << "Encontrado: " << searchBFS->letra << endl;
	
	return 0;
}

void print_pre_order(Node *current)
{
	if (current == nullptr)
		return;
		
	cout << current->letra << "  ";
	print_pre_order(current->left);
	print_pre_order(current->right);
}

void print_in_order(Node *current)
{
	if (current == nullptr)
		return;
		
	print_in_order(current->left);
	cout << current->letra << "  ";
	print_in_order(current->right);
}
void print_post_order(Node *current)
{
	if (current == nullptr)
		return;
		
	print_post_order(current->left);
	print_post_order(current->right);
	cout << current->letra << "  ";
}

Node* DFS(Node *current, string value)
{
	if (current == nullptr || current->letra.compare(value) == 0)
		return current;
		
	Node *left_result = DFS(current->left, value);
	if (left_result != nullptr)
		return left_result;
		
	Node *right_result = DFS(current->right, value);
	if (right_result != nullptr)
		return right_result;
	
	return nullptr;
}

Node* BFS(Node *root, string value)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node *current = q.front();
		q.pop();
		
		if (current->letra.compare(value) == 0)
			return current;
			
		if (current->left != nullptr)
			q.push(current->left);
		if (current->right != nullptr)
			q.push(current->right);
	}
	
	return nullptr;
}
