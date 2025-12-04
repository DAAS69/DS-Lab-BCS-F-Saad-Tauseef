#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct combatant
{
    char name[30];
    int hp;
    int attack;
    int key;
};

struct node
{
    combatant data;
    node* left;
    node* right;
};

node* create_node(combatant c)
{
    node* n = new node;
    n->data = c;
    n->left = 0;
    n->right = 0;
    return n;
}

node* insert_rec(node* root, combatant c)
{
    if(root == 0) return create_node(c);
    if(c.key < root->data.key)
        root->left = insert_rec(root->left, c);
    else
        root->right = insert_rec(root->right, c);
    return root;
}

node* find_min(node* root)
{
    if(root == 0) return 0;
    if(root->left == 0) return root;
    return find_min(root->left);
}

node* remove_rec(node* root, int k)
{
    if(root == 0) return root;

    if(k < root->data.key)
        root->left = remove_rec(root->left, k);
    else if(k > root->data.key)
        root->right = remove_rec(root->right, k);
    else
    {
        if(root->left == 0 && root->right == 0)
        {
            delete root;
            return 0;
        }
        else if(root->left == 0)
        {
            node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right == 0)
        {
            node* t = root->left;
            delete root;
            return t;
        }
        else
        {
            node* m = find_min(root->right);
            root->data = m->data;
            root->right = remove_rec(root->right, m->data.key);
        }
    }
    return root;
}

void inorder(node* root)
{
    if(root == 0) return;
    inorder(root->left);
    cout << root->data.name << "(" << root->data.hp << ") ";
    inorder(root->right);
}

int random_damage(int base)
{
    return base + (rand() % 5);
}

int main()
{
    srand(2);

    node* heroes = 0;
    node* enemies = 0;

    combatant h1 = {"ahmed", 40, 8, 10};
    combatant h2 = {"bilal", 35, 9, 5};
    combatant h3 = {"saad", 45, 7, 14};
    combatant h4 = {"hassan", 30, 10, 3};
    combatant h5 = {"umer", 38, 6, 18};

    heroes = insert_rec(heroes, h1);
    heroes = insert_rec(heroes, h2);
    heroes = insert_rec(heroes, h3);
    heroes = insert_rec(heroes, h4);
    heroes = insert_rec(heroes, h5);

    combatant e1 = {"jabbar", 38, 7, 11};
    combatant e2 = {"kashif", 30, 8, 4};
    combatant e3 = {"fahad", 42, 6, 15};
    combatant e4 = {"raheel", 33, 9, 2};
    combatant e5 = {"ayaz", 36, 7, 17};

    enemies = insert_rec(enemies, e1);
    enemies = insert_rec(enemies, e2);
    enemies = insert_rec(enemies, e3);
    enemies = insert_rec(enemies, e4);
    enemies = insert_rec(enemies, e5);

    int round = 1;

    while(heroes != 0 && enemies != 0)
    {
        cout << "\nround " << round << "\n";

        cout << "heroes: ";
        inorder(heroes);
        cout << "\n";

        cout << "enemies: ";
        inorder(enemies);
        cout << "\n";

        node* h = find_min(heroes);
        node* e = find_min(enemies);

        cout << "hero " << h->data.name << " attacks enemy " << e->data.name << "\n";
        int dmg = random_damage(h->data.attack);
        cout << "damage: " << dmg << "\n";

        e->data.hp -= dmg;
        if(e->data.hp <= 0)
        {
            cout << e->data.name << " is defeated\n";
            enemies = remove_rec(enemies, e->data.key);
            if(enemies == 0) break;
        }

        if(enemies != 0)
        {
            h = find_min(heroes);
            e = find_min(enemies);

            cout << "enemy " << e->data.name << " attacks hero " << h->data.name << "\n";
            dmg = random_damage(e->data.attack);
            cout << "damage: " << dmg << "\n";

            h->data.hp -= dmg;
            if(h->data.hp <= 0)
            {
                cout << h->data.name << " is defeated\n";
                heroes = remove_rec(heroes, h->data.key);
                if(heroes == 0) break;
            }
        }

        round++;
    }

    if(heroes == 0)
        cout << "\nenemies win\n";
    else
        cout << "\nheroes win\n";

    return 0;
}
