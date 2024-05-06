#include <iostream>
#include <cstdlib>
#include <string> // Include string header for getline
using namespace std;

struct node
{
    char label[100]; // Increase size for book names
    int ch_count;
     node *child[10];
} *root;

class GT
{
public:
    void create_tree();
    void display(node *r1);

    GT()
    {
        root = NULL;
    }
};

void GT::create_tree()
{
    int tchapters, i, j;
    root = new node;
    cout << "Enter name of book: ";
    cin.ignore();
    cin.getline(root->label, sizeof(root->label)); // Use cin.getline instead of getline
    cout << "Enter number of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name: ";
        cin.ignore();
        cin.getline(root->child[i]->label, sizeof(root->child[i]->label)); // Use cin.getline instead of getline
        cout << "Enter number of sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name: ";
            cin.ignore();
            cin.getline(root->child[i]->child[j]->label, sizeof(root->child[i]->child[j]->label)); // Use cin.getline instead of getline
        }
    }
}

void GT::display(node *r1)
{
    int i, j, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";

        cout << "\n Book title : " << r1->label;
        tchapters = r1->ch_count;
        for (i = 0; i < tchapters; i++)
        {

            cout << "\n  Chapter " << i + 1;
            cout << " " << r1->child[i]->label;
            cout << "\n Sections";
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n  " << r1->child[i]->child[j]->label;
            }
        }
    }
}

int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;
        case 2:
            gt.display(root);
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
