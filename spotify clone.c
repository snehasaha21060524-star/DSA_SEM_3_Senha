#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char name[50];
    struct Song *next;
};

struct Song *head = NULL;

void addSong()
{
    struct Song *newSong, *temp;

    newSong = (struct Song *)malloc(sizeof(struct Song));

    printf("Enter song name: ");
    scanf(" %[^\n]", newSong->name);

    newSong->next = NULL;

    if (head == NULL)
    {
        head = newSong;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
    }

    printf("Song added successfully!\n");
}

void display()
{
    struct Song *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    printf("\nSpotify Playlist:\n");

    while (temp != NULL)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

void playNext()
{
    if (head == NULL)
    {
        printf("No songs available\n");
    }
    else
    {
        printf("Now playing: %s\n", head->name);
        head = head->next;
    }
}

void deleteSong()
{
    struct Song *temp = head;
    struct Song *prev = NULL;
    char name[50];

    printf("Enter song name to delete: ");
    scanf(" %[^\n]", name);

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Song deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Song not found\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== SPOTIFY CLONE =====\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Next Song\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addSong();
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            playNext();
        }
        else if (choice == 4)
        {
            deleteSong();
        }
        else if (choice == 5)
        {
            printf("Thank you for using Spotify Clone!\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}