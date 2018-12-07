#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Person {
public:
    std::string name;
    int phoneNumber;
    int id;

    Person() {}
    Person(std::string n, int i) : name(n), phoneNumber(i) {}
    void set_name(std::string n) { name = n; }
    void set_phoneNumber(int n) { phoneNumber = n; }
    std::string get_name() { return name; }
    int get_phoneNumber() { return phoneNumber; }
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name;
        return os; }

};
class BST
{
    struct node
    {
        Person data;
        node* left;
        node* right;
        int height;
    };

    node* root;

    void makeEmpty(node* t)
    {
        if (t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(Person x, node* t)
    {
        if (t == nullptr)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = nullptr;
        }
        else if (x.name < t->data.name)
        {
            t->left = insert(x, t->left);
            if (height(t->left) - height(t->right) == 2)
            {
                if (x.name < t->left->data.name)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if (x.name > t->data.name)
        {
            t->right = insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x.name > t->right->data.name)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(Person x, node* t)
    {
        node* temp;


        if (t == nullptr)
            return nullptr;

        // Busca elemento
        else if (x.name < t->data.name)
            t->left = remove(x, t->left);
        else if (x.name > t->data.name)
            t->right = remove(x, t->right);

        // Encontro elemento con dos hijos

        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // uno o menos hijos
        else
        {
            temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
        }
        if (t == nullptr)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;

        // If node is unbalanced
        // If left node is deleted, right case
        if (height(t->left) - height(t->right) == 2)
        {
            // right right case
            if (height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if (height(t->right) - height(t->left) == 2)
        {
            // left left case
            if (height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    int height(node* t)
    {
        return (t == nullptr ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if (t == nullptr)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node* t)
    {
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(Person x)
    {
        root = insert(x, root);
    }

    void remove(Person x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(430,295);
    ui->nameLine->setText("Nombre");
    ui->phoneLine->setText("Telefono");
    BST t;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QWidget *wdg = new QWidget;
    wdg->
    wdg->show();
    //hide();//this will disappear main window
}

void MainWindow::on_backButton_clicked()
{

}

void MainWindow::on_delButton_clicked()
{

}

void MainWindow::on_nextButton_clicked()
{

}
