
#include <vector>
using std::vector;
using std::iterator_traits;
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

template <typename E, typename K>
class BinarySearch {
public:
    typedef typename vector<E>::iterator iterator;
    typedef typename iterator_traits<iterator>::difference_type difference_type;
    typedef E * pointer;

    BinarySearch() {}

    ~BinarySearch() {
        list.empty();
    }

    void insert(const E& el) {
        iterator iter=list.begin();
        while ((iter != list.end()) && (*(iter) < el))
            iter++;
        list.insert(iter, el);
    }

    void remove(const K key) {
        iterator result = _search(key);
        list.erase(result);
    }

    pointer search(const K key) {
        iterator result = _search(key);
        if (result != list.end())
            return static_cast<pointer>(&(*result));
        else 
            return NULL;
    }

    iterator _search(const K key) {
        difference_type len = list.end()-list.begin();
        difference_type begin = 0, end = len-1, mid;
        iterator first = list.begin();

        while (begin <= end) {
            mid = (begin+end)/2;
            cout<<"\tComparing with element "<<(first+mid)->getKey()<<"..."<<endl;
            if (*(first+mid) < key)
                begin = mid + 1;
            else if (*(first+mid) > key)
                end = mid - 1;
            else {
                cout<<"\tFound!"<<endl;
                return (first + mid);
            }
        }
        return list.end();
    }

    void traversal() {
        for (iterator iter=list.begin();
                iter!=list.end(); iter++) {
            cout<<iter->getKey()<<"  ";
        }
        cout<<endl;
    }

private:
    vector<E> list;
};

