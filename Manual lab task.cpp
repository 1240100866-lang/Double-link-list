#include <iostream>
#include <string>
using namespace std;

struct Book {
    string isbn, title, author;
    int year;
    Book* prev;
    Book* next;
};

Book* head = NULL;

void insertBook(string isbn, string title, string author, int year) {
    Book* n = new Book{isbn, title, author, year, NULL, NULL};
    if (!head) {
        head = n;
        return;
    }
    Book* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

Book* searchBook(string key) {
    Book* temp = head;
    while (temp) {
        if (temp->isbn == key || temp->title == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void modifyBook(string key, string title, string author, int year) {
    Book* b = searchBook(key);
    if (b) {
        b->title = title;
        b->author = author;
        b->year = year;
    }
}

void displayBooks() {
    Book* temp = head;
    int count = 0;
    while (temp) {
        cout << temp->isbn << " " << temp->title << " " << temp->author << " " << temp->year << endl;
        count++;
        temp = temp->next;
    }
    cout << "Total Books: " << count << endl;
}

int main() {
    insertBook("101", "DSA", "Mark", 2020);
    insertBook("102", "OOP", "John", 2019);
    modifyBook("101", "DSA Updated", "Mark", 2021);
    displayBooks();
    return 0;
}
