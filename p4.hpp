//file name : A3_SheetPb4_20220334
//purpose : solving problem 4
//author : mariam matarawy ahmed ali
//ID : 20220334
//section : s1
//date : 8/12/2023

#include "bits/stdc++.h"
using namespace std;
template <typename T>
class new_set {
protected:
    vector <T> set_items;
public :
    void add(const T &element){
        if (find(set_items.begin(),set_items.end(),element)== set_items.end())//to check whether this element exists in the
            // set already or no, if it exists, so we will not add it as the set does not have repeated items
            set_items.push_back(element); //else nothing happens
    }
    void remove(const T & element) {
        if (find(set_items.begin(), set_items.end(), element)!=set_items.end()) {
            auto it = find(set_items.begin(), set_items.end(), element);//to define the position of this element
            set_items.erase(it,set_items.end());
        }

    }
    int get_size() const {
        return set_items.size();
    }
    bool check_item(const T &element) const{
        return find(set_items.begin(), set_items.end(), element) !=set_items.end();//it will return true if the item exists
    }
    T* copy() {
        T *arr = new T(set_items.size);//here we do allocate new memory to fill it with new items of
        // other set, and this a shallow copy
        for (int i = 0; i < set_items.size(); i++) {
            arr[i] = set_items[i];
        }
        return arr;
    }
    void display() {
        cout << "elements of this set: ";
        for (auto i: set_items) {
            cout << i << " ";
        }
        cout << endl;
    }
    bool operator==(const new_set & another) const{
        if (this->get_size() != another.get_size()) return false;//if size of each set are not equal, it will return false
        else {
            for (auto i : set_items){
                if (!another.check_item(i)) return false;//here we will check every single element using
                // the function check item to make sure that it exists in the other set
            }
        }
        return true;
    }
    bool operator!=(const new_set & another){
        for (auto i : set_items){
            if (! another.check_item(i)) return true;//here we will do the same operation but with
            // different purpose, so it will return true of two sets are different from each other
        }
        return false;
    }




};
