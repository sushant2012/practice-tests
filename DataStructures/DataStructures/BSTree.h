#include <iostream>
using namespace std;

template<typename T>
struct BSTree
{
	struct Node
	{
		T key;
		Node* left;
		Node* right;
		Node* parent;
		Node(): key(T()) {left = right = parent = 0;}
		Node(const T& key): key(key) {left = right = parent = 0;}
		~Node() {}
	};

	typedef Node* Link;

	BSTree(): m_head(0), m_size(0) {}
	~BSTree(){}

	bool empty(){return !m_head;}
	size_t size(){return m_size;}
	void intrav(){intrav_helper(m_head);}
	void postrav(){postrav_helper(m_head);}
	void pretrav(){pretrav_helper(m_head);}

	Link search(const T& key){return search_helper(m_head, key);}
	void insert(const T& key);
	void remove(const T& Key);
	Link min();
	Link max();
	Link successor(const T& key);
	Link predecessor(const T& key);

private:
	Link m_head;
	size_t m_size;
	void intrav_helper(Link t);
	void postrav_helper(Link t);
	void pretrav_helper(Link t);
	Link search_helper(Link head, const T& key);
};

template<typename T>
typename BSTree<T>::Link BSTree<T>::search_helper(Link t, const T& key)
{
	if (!t || t->key == key)
		return t;
	if (key < t->key)
		return search_helper(t->left, key);
	else
		return search_helper(t->right, key);
}

template<typename T>
void BSTree<T>::insert(const T& key)
{
	Link p = 0;
	Link x = m_head;
	while(x)
	{
		p = x;
		if (key == x->key)
			return;
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	x = new Node(key);
	++m_size;
	x->parent = p;
	if (!p)
		m_head = x;
	else if (key < p->key)
		p->left = x;
	else
		p->right = x;
}

template<typename T>
void BSTree<T>::remove(const T& key)
{

}

template<typename T>
void BSTree<T>::intrav_helper(Link t)
{
	if (!t)       return;
	intrav_helper(t->left);
	cout << t->key << ",";
	intrav_helper(t->right);
}

template<typename T>
void BSTree<T>::postrav_helper(Link t)
{
	if (!t) return;
	postrav_helper(t->left);
	postrav_helper(t->right);
	cout << t->key << ",";
}

template<typename T>
void BSTree<T>::pretrav_helper(Link t)
{
	if (!t) return;
	cout << t->key << ",";
	pretrav_helper(t->left);
	pretrav_helper(t->right);
}
