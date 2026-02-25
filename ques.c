#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    struct Song* next;
};

struct Song* addSong(struct Song* head, char title[]) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    newSong->next = NULL;

    if (head == NULL) {
        return newSong;
    }

    struct Song* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newSong;
    return head;
}

int countSongs(struct Song* head) {
    int count = 0;
    struct Song* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void printPlaylist(struct Song* head) {
    struct Song* temp = head;
    int index = 1;

    while (temp != NULL) {
        printf("%d. %s\n", index, temp->title);
        temp = temp->next;
        index++;
    }
}

void freePlaylist(struct Song* head) {
    struct Song* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Song* playlist = NULL;
    int n;
    char title[100];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
        playlist = addSong(playlist, title);
    }

    printf("%d\n", countSongs(playlist));
    printPlaylist(playlist);

    freePlaylist(playlist);
    return 0;
}