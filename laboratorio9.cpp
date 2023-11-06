#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node{
	string letra;
	int data;
	Node *left;
	Node *right;
	
	Node(string l) : letra(l), data(0), left(nullptr), right(nullptr) {}
	Node(int d) : letra(""), data(d), left(nullptr), right(nullptr) {}
};

// funciones de impresion
void print_pre_order(Node *current);
void print_in_order(Node *current, int mode);
void print_post_order(Node *current);

Node* insert_node(Node *current, int data);

// funciones de busqueda
Node* DFS(Node *current, string value);
Node* BFS(Node *root, string value);

int main()
{
	// ejercicio 1
	Node *root_letra = new Node("M");
	root_letra->left = new Node("C");
	root_letra->right = new Node("Z");
	root_letra->left->left = new Node("X");
	root_letra->left->right = new Node("O");
	root_letra->right->left = new Node("T");
	root_letra->right->right = new Node("F");
	root_letra->right->left->left = new Node("W");
	
	// ejercicio 2
	cout << "pre-order: ";
	print_pre_order(root_letra);
	cout << endl << "in-order ";
	print_in_order(root_letra, 0);
	cout << endl << "post-order: ";
	print_post_order(root_letra);
	cout << endl;
	
	//ejercicio 3
	int arr[10] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
	Node *root_data = nullptr;
	for (int i=0; i<10; i++)
		root_data = insert_node(root_data, arr[i]);
	
	print_in_order(root_data,1);
	cout << endl;
	
	// ejercicio 4
	Node *searchDFS = DFS(root_letra, "O");
	if (searchDFS != nullptr)
		cout << "Encontrado: " << searchDFS->letra << endl;
		
	// ejercicio 5
	Node *searchBFS = BFS(root_letra, "C");
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

void print_in_order(Node *current, int mode)
{
	if (current == nullptr)
		return;
		
	print_in_order(current->left, mode);
	if (mode == 0) // imprime string
		cout << current->letra << "  ";
	else // imprime int
		cout << current->data << "  ";
	print_in_order(current->right, mode);
}
void print_post_order(Node *current)
{
	if (current == nullptr)
		return;
		
	print_post_order(current->left);
	print_post_order(current->right);
	cout << current->letra << "  ";
}

Node* insert_node(Node *current, int data)
{
	if (current == nullptr)
		return new Node(data);
		
	if (current->data > data)
		current->left = insert_node(current->left, data);
	else
		current->right = insert_node(current->right, data);
		
	return current;
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
