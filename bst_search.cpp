
#include "person.h"
#include "bst_search.h"

#define SIZE 10

int main() {
    BSTree<Person, long> myBSTree;
    Person *persons[SIZE];

    // Construct tree
    persons[0] = new Person(1050, "A", 0);
    persons[1] = new Person(1080, "B", 0);
    persons[2] = new Person(1110, "C", 0);
    persons[3] = new Person(1000, "D", 0);
    persons[4] = new Person(1008, "E", 0);
    persons[5] = new Person(1103, "F", 0);
    persons[6] = new Person(1001, "G", 0);
    persons[7] = new Person(1002, "H", 0);
    persons[8] = new Person(1012, "I", 0);
    persons[9] = new Person(1102, "J", 0);

    for (int i=0;i<SIZE;i++) {
        persons[i]->display();
        myBSTree.insert(*persons[i]);
    }
    cout<<endl;

    for (int i=0;i<SIZE;i++)
        delete persons[i];

    myBSTree.traversal();
    cout<<endl;

    // Search
    Person *result;
    long key;
    key = 1012;
    cout<<"Searching element with key="<<key<<"..."<<endl;
    result = myBSTree.search(key);
    if (result != NULL) {
        cout<<"Found!"<<endl;
        result->display();
    } else
        cout<<"NOT Found!"<<endl;
    cout<<endl;

    key = 1013;
    cout<<"Searching element with key="<<key<<"..."<<endl;
    result = myBSTree.search(key);
    if (result != NULL) {
        cout<<"Found!"<<endl;
        result->display();
    } else
        cout<<"NOT Found!"<<endl;
    cout<<endl;

    key = 1050;
    cout<<"Removing element with key="<<key<<"..."<<endl;
    myBSTree.remove(key);
    cout<<endl;

    myBSTree.traversal();
    cout<<endl;

    key = 1008;
    cout<<"Removing element with key="<<key<<"..."<<endl;
    myBSTree.remove(key);
    cout<<endl;

    myBSTree.traversal();
    cout<<endl;

    key = 1050;
    cout<<"Searching element with key="<<key<<"..."<<endl;
    result = myBSTree.search(key);
    if (result != NULL) {
        cout<<"Found!"<<endl;
        result->display();
    } else
        cout<<"NOT Found!"<<endl;
    cout<<endl;

    return 0;
}

