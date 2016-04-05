
#ifndef NULL
#define NULL 0
#endif

template <typename E, typename K>
struct BSTNode {
    E data;
    BSTNode<E, K> *leftChild, *rightChild;
    BSTNode(const E& x, BSTNode<E,K> *l=NULL, BSTNode<E,K> *r=NULL): 
        data(x), leftChild(l), rightChild(r) {}
};

template <typename E, typename K>
class BSTree {
public:
    typedef BSTNode<E, K> Node;
    typedef BSTNode<E, K> * pointer;

    BSTree(): root(NULL) {}

    ~BSTree() { _destroy(root); }

    void insert(const E& el) { _insert(el, root); }

    void remove(const K key) { _remove(key, root); }

    void traversal() const {
        cout<<"Pre-traversal:"<<endl;
        _pre_traversal(root); 
        cout<<endl;
        cout<<"Mid-traversal:"<<endl;
        _mid_traversal(root); 
        cout<<endl;
        cout<<"Post-traversal:"<<endl;
        _post_traversal(root); 
        cout<<endl;
    }

    E* search(const K key) const {
        pointer result = _search(key, root);
        if (result != NULL)
            return static_cast<E*>(&(result->data));
        else
            return NULL;
    }

private:
    pointer root;

    bool _insert(const E& el, pointer & _root);

    void _remove(const K key, pointer & _root);

    void _pre_traversal(pointer _root) const;

    void _mid_traversal(pointer _root) const;

    void _post_traversal(pointer _root) const;

    pointer _search(const K key, pointer _root) const;

    void _destroy(pointer _root);
};

template <typename E, typename K>
BSTNode<E, K> * BSTree<E, K>::_search(const K key, pointer _root) const {
    if (_root != NULL) {
        cout<<"\tComparing with "<<_root->data.getKey();
        if (_root->data > key) {
            cout<<": turn left"<<endl;
            return _search(key, _root->leftChild);
        } else if (_root->data < key) {
            cout<<": turn right"<<endl;
            return _search(key, _root->rightChild);
        } else {
            cout<<": found!"<<endl;
            return _root;   // found
        }
    } else {
        cout<<"\tNOT found!"<<endl;
        return NULL;        // not found
    }
}

// note the argument of _root should be reference!
template <typename E, typename K>
bool BSTree<E, K>::_insert(const E& el, pointer & _root) {
    if (_root == NULL) {
        _root = new Node(el);
        return true;
    } else if (el < _root->data)
        _insert(el, _root->leftChild);
    else if (el > _root->data)
        _insert(el, _root->rightChild);
    else
        return false;
}

// note the argument of _root should be reference!
template <typename E, typename K>
void BSTree<E, K>::_remove(const K key, pointer & _root) {
    if (_root != NULL) {
        cout<<"\tComparing with "<<_root->data.getKey();
        if (_root->data > key) {
            cout<<": turn left"<<endl;
            _remove(key, _root->leftChild);
        } else if (_root->data < key) {
            cout<<": turn right"<<endl;
            _remove(key, _root->rightChild);
        } else { // found
            cout<<": found!"<<endl;
            cout<<"\tRemoving element with key="<<key<<"..."<<endl;
            if (_root->leftChild != NULL && _root->rightChild != NULL) {
                pointer tmp = _root->rightChild;
                while (tmp->leftChild != NULL)
                    tmp = tmp->leftChild;
                _root->data = tmp->data;
                _remove(static_cast<K>(tmp->data.getKey()), _root->rightChild);
            } else if (_root->leftChild == NULL) {
                pointer tmp = _root;
                _root = _root->rightChild;
                delete tmp;
            } else {
                pointer tmp = _root;
                _root = _root->leftChild;
                delete tmp;
            }
        }
    }
}

template <typename E, typename K>
void BSTree<E, K>::_pre_traversal(pointer _root) const {
    if (_root != NULL) {
        cout<<_root->data.getKey();
        if (!(_root->leftChild == NULL && _root->rightChild == NULL)) {
            cout<<"(";
            _pre_traversal(_root->leftChild);
            cout<<"|";
            _pre_traversal(_root->rightChild);
            cout<<")";
        }
    }
}

template <typename E, typename K>
void BSTree<E, K>::_mid_traversal(pointer _root) const {
    if (_root != NULL) {
        cout<<"(";
        _mid_traversal(_root->leftChild);
        cout<<"<"<<_root->data.getKey()<<">";
        _mid_traversal(_root->rightChild);
        cout<<")";
    }
}

template <typename E, typename K>
void BSTree<E, K>::_post_traversal(pointer _root) const {
    if (_root != NULL) {
        if (!(_root->leftChild == NULL && _root->rightChild == NULL)) {
            cout<<"(";
            _post_traversal(_root->leftChild);
            cout<<"|";
            _post_traversal(_root->rightChild);
            cout<<")";
        }
        cout<<_root->data.getKey();
    }
}

template <typename E, typename K>
void BSTree<E, K>::_destroy(pointer _root) {
    if (_root != NULL) {
        _destroy(_root->leftChild);
        _destroy(_root->rightChild);
        delete _root;
    }
}

