#include <iostream>
#include <string>
using namespace std;

struct pers {
    string firstname;
    string lastname;
    int age;
    pers* wsk;
};

int addLast(pers* List, string fname, string lname, int age) {
    pers* Person = new pers;
    Person->age = age;
    Person->firstname = fname;
    Person->lastname = lname;
    Person->wsk = NULL;
    pers* wsk = List;
    int ile = 1;
    while (wsk->wsk != NULL) {
        wsk = wsk->wsk;
        ile++;
    }
    wsk->wsk = Person;
    return ile+1;
}
/*
Napisz funkcję, która usuwa ostatni element z listy
i zwraca usunięty elment.
*/
pers* deleteLast(pers* List) {
    pers* Person = NULL;
    pers* wsk = List;
    while (wsk->wsk->wsk != NULL) {
        wsk = wsk->wsk;
    }
    Person = wsk->wsk;
    wsk->wsk = NULL;
    return Person;
}
int main()
{
    pers a = { "Jan", "Kowalski", 20, NULL };
    pers* ptr = &a;
    int w = addLast(ptr, "Marcin", "Musztarda", 25);
    w = addLast(ptr, "Teofil", "Banan", 24);
    w= addLast(ptr, "Leon", "Zawodowiec", 50);
    w = addLast(ptr, "Krystian", "Ziemniak", 18);
    w = addLast(ptr, "Jacek", "Fasola", 18);
    bool test = true;
    while (test) {
        cout << ptr->firstname << ", " << ptr->lastname << ", " << ptr->age << endl;
        cout << "----------------------------------" << endl;
        if (ptr->wsk == NULL)
            test = false;
        else ptr = ptr->wsk;
    }
    cout << "Liczba elementow listy: " << w << endl;
    ptr = &a;
    pers* remove = deleteLast(ptr);
    cout << remove->firstname << "," << remove->lastname << endl;
    test = true;
    while (test) {
        cout << ptr->firstname << ", " << ptr->lastname << ", " << ptr->age << endl;
        cout << "----------------------------------" << endl;
        if (ptr->wsk == NULL)
            test = false;
        else ptr = ptr->wsk;
    }
}

