/* !!! HASH TABLE !!! */

#include <iostream>
#include <cstring>


struct Node
{
    Node *next;
    char *key;
    char *data;
    char *value;
};



Node *hashTable[32];

unsigned int my_hash(char *str)
{
    unsigned  int hash_value =0;
    unsigned  char *p;
    for (p = (unsigned char *) str; *p != '\0'; p++)
        hash_value = 31 * hash_value + *p;
    return hash_value % 32;
}

Node *insert_node(char *key, char *value)
{
    int hash_value = 0;
    Node *new_node;
    hash_value = my_hash(key);
    new_node = (Node*) malloc(sizeof(Node));
    new_node ->key = key;
    new_node ->value = value;
    new_node->next = hashTable[hash_value];
    hashTable[hash_value] = new_node;
    return new_node;
}

void print_node(char *key)
{
    std::cout << "{key, value} = {" << hashTable[my_hash(key)]->key << ", " << hashTable[my_hash(key)]->value << "}" << std::endl;
}

bool find_node(char *key)
{
    Node *new_node;
    for (new_node = hashTable[ my_hash(key)]; ! new_node; new_node = new_node->next )
        if (! strcmp(key, new_node->key))
            return true;
}


int main ()
{

    insert_node("vlad", "8 966 545 89 56");
    insert_node("anton", "8 458 568 97 85");
    insert_node("igor", "8 456 965 87 56");
    insert_node("petya", "8 965 845 26 89");
    insert_node("alena", "8 965 845 26 84");
    insert_node("eva", "8 952 154 85 54");
    insert_node("sveta", "8 968 458 56 85");
    insert_node("vika", "8 548 568 96 22");


    print_node("vlad");
    print_node("anton");
    print_node("igor");
    print_node("petya");
    print_node("alena");
    print_node("eva");
    print_node("sveta");
    print_node("vika");

    if (find_node("vlad"))
        std::cout << "Элемент vlad  есть  в таблице " << std::endl;

    return 0;

}