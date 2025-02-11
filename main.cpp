#include <iostream>

using namespace std;

// ხის კვანძის სტრუქტურა/ Binary tree structure
struct Node {
    string name;
    string email;
    Node* left;
    Node* right;

    // კონსტრუქტორი/ Constructor
    Node (string n, string e) {
        name = n;
        email = e;
        left = right = nullptr; // ორივე პოინტერი საწყისად "ცარიელია"/ Both pointers are initialy "null"

    }
};
