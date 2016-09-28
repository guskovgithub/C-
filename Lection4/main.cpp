#include <cstdlib>
#include <iostream>

using namespace std;


struct Dot
{
    int x;
    int y;
};


struct Node       //Структура являющаяся звеном списка
{
    Dot *dot;     //Значение x будет передаваться в список
    Node *next;
    Node *prev;//Указатели на адреса следующего и предыдущего элементов списка

};


struct List   //Создаем тип данных Список
{
    Node *head = NULL;
    Node *tail = NULL;  //Указатели на адреса начала списка и его конца

};

void append( List *list, Dot *dot);
void print(List *list);
void del(List *list, int pos);
void find(List *list,  Dot *dot);
void lenth(List *list);


void lenth(List *list) {
    Node *new_element = new Node();
    new_element = list->head;
    if (list->head == NULL) cout << "список пуст"; int _lenth = 0;
    if (list->head != NULL) {
        int _lenth = 1;
        while (new_element->next != NULL) {
            _lenth++;
            new_element = new_element->next;

        }
        cout <<  _lenth << endl;
    }
 }


void append( List *list, Dot *dot )
{
    Node *new_element = new Node(); // Выделение памяти под новый элемент структуры
    new_element->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    new_element->dot = dot;             // Записываем значение в структуру

    if ( list->head != NULL ) // Если список не пуст
    {
        new_element->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = new_element; // Указываем адрес следующего за хвостом элемента
        list->tail = new_element;       //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        new_element->prev = NULL; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = new_element;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void print( List * list )
{
    Node * new_element = list->head;  // Временно указываем на адрес первого элемента
    if (list->head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    while( new_element != NULL )      // Пока не встретим пустое значение
    {
        cout << "(" << new_element->dot->x << ","<< new_element->dot->y << ")" << " "; //Выводим значение на экран
        new_element = new_element->next;     //Смена адреса на адрес следующего элемента
    }
    cout<<"\n";
}


void find(List *list, Dot *dot)
{
    Node * new_element = list->head;  // Временно указываем на адрес первого элемента
    while( new_element != NULL )
    {
        if (new_element->dot->x == dot->x || new_element->dot->y == dot->y)
        {
            cout << "TRUE" <<  endl;
            return;
        }
        new_element = new_element->next;


    }
    cout << "FALSE"<<  endl;
}
void insert(List *list, Dot *dot, int pos)
{
    Node *new_element = new Node();
    new_element->dot = dot;
    Node *node = list->head;
    for (int i=pos; i>1; i--) node = node->next;
    node->prev->next = new_element;
    new_element->prev = node->prev;
    new_element->next = node;
    node->prev = new_element;
}

void del(List *list, int pos)
{
    if (list->head == NULL) { cout<<"\nСписок пуст\n\n"; }
    if (list->head == list->head->next) //если это последний элемент в списке
    {
        delete list->head; //удаление элемента
        list->head = NULL;
    }
    else
    {
        Node *a=list->head;
        for (int i=pos; i>1; i--) a=a->next;
        if (a==list->head) list->head=a->next;
        a->prev->next=a->next; //удаление элемента
        a->next->prev=a->prev;
        delete a;
    }
    cout<<"\nЭлемент удален...\n\n";

}


int main() {
    List mylist;
    //заполняем список 20ю точками со случайными значениями
    for (int i=0; i<20; i++)
    {
        Dot *mydot = new Dot();
        mydot->x = rand() % 100 ;
        mydot->y = rand() % 100 ;

        append(&mylist, mydot);
    }
    //выводим на экран элеметы списка
    print(&mylist);


    // фуннкция песатает длину списка
    cout << "длина списка: ";
    lenth(&mylist);
    // сделаем новую точку, чтобы проверить есть ли он в списке, а после вставить ее в список.
    Dot *mydot = new Dot();
    mydot->x = 1010;
    mydot->y = 1010;

    find(&mylist, mydot);
    insert(&mylist, mydot, 3);
    find(&mylist, mydot);


    print(&mylist);
    cout << "длина списка: ";
    lenth(&mylist);
    //удаляем третий элемент списка
    del(&mylist, 3);
    return 0;
}