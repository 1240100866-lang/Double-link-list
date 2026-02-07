#include <iostream>
#include <string>
using namespace std;

struct Song {
    int id, duration;
    string title, artist;
    Song* prev;
    Song* next;
};

Song* head = NULL;
Song* current = NULL;

void insertSong(int id, string title, string artist, int duration) {
    Song* n = new Song{id, duration, title, artist, NULL, NULL};
    if (!head) {
        head = current = n;
        return;
    }
    Song* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

Song* searchSong(string key) {
    Song* temp = head;
    while (temp) {
        if (temp->title == key || temp->artist == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void modifySong(string key, string title, string artist, int duration) {
    Song* s = searchSong(key);
    if (s) {
        s->title = title;
        s->artist = artist;
        s->duration = duration;
    }
}

void displaySongs() {
    Song* temp = head;
    int count = 0, total = 0;
    while (temp) {
        cout << temp->id << " " << temp->title << " " << temp->artist << " " << temp->duration << endl;
        total += temp->duration;
        count++;
        temp = temp->next;
    }
    cout << "Total Songs: " << count << endl;
    cout << "Total Duration: " << total << endl;
}

void playNext() {
    if (current && current->next)
        current = current->next;
    if (current)
        cout << current->title << endl;
}

void playPrevious() {
    if (current && current->prev)
        current = current->prev;
    if (current)
        cout << current->title << endl;
}

int main() {
    insertSong(1, "SongA", "Artist1", 3);
    insertSong(2, "SongB", "Artist2", 4);
    insertSong(3, "SongC", "Artist3", 5);
    displaySongs();
    playNext();
    playPrevious();
    return 0;
}
