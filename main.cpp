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

// ფუნქცია ახალი მომხმარებლის დასამატებლად/ Function to add new user
Node* insert(Node* root, string name, string email) {
    if (root == nullptr) {
        return new Node(name,email); // იქმნება ახალი კვანძი/ Creating new node
    }

    if (name < root->name) {
        root->left = insert(root->left, name, email); // მარცხენა/ Left
    } else {
        root->right = insert(root->right, name, email); // მარჯვენა/ Right
    }

    return root;
}

// მომხმარებლის ძიება/ Search user
Node* search(Node* root, string name) {
    if (root == nullptr || root -> name == name) {
        return root;
    }

    if (name < root ->name) {
        return search(root -> left, name); // იძებნება მარცხნივ/ Search in left
    } else {
        return search(root -> right, name); // იძებნება მარჯვნივ/ Search in right
    }
}

// ხის მონაცემების გამოტანა (Inorder Traversal)/ Tree data output
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root -> left);
        cout << "Name: " << root -> name << ", Email: " << root-> email << endl;
        inorder(root -> right);
    }
}

int main () {
    Node* root = nullptr;

    // მომხმარებლებლების ჩამონათვალი/ List of data
    root = insert(root, "John", "john@example.com");
    root = insert(root, "Luka", "luka@example.com");
    root = insert(root, "Gio", "gio@example.com");
    root = insert(root, "Tamta", "tamta@example.com");

    // ახალი მომხმარებლის დამატება/ Add new user
    string newName, newEmail;
    cout << "Enter new user name: ";
    cin >> newName;
    cout << "Enter new user email: ";
    cin >> newEmail;

    root = insert(root, newName, newEmail);
    
    // მომხმარებლის ძიება/ Search user
    string searchName = "Luka";
    Node* user = search(root, searchName);
    if (user != nullptr) {
        cout << searchName << "\nFound: " << user -> email << endl;
    } else {
        cout << searchName << "\nNot found.\n";
    }
    
    // მონაცემების გამოტანა/ Out put of data
    cout << "User database:\n";
    inorder(root);
    return 0;
}