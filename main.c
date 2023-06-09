/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               :
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song
{
    char penyanyi[25];
    char judul[50];
};

typedef struct node_stack
{
    struct node_stack *nextNode;
    struct song songData;

} node;

typedef struct stack_playlist
{
    struct node_stack *top;

} stack;

int isEmptyPlaylist(stack *playlist)
{
    return (playlist->top == NULL ? 1 : 0);
}

void push(stack *playlist, struct song _songData)
{
    node *newNode;
    newNode = malloc(sizeof(struct node_stack));
    newNode->songData = _songData;
    newNode->nextNode = playlist->top;
    playlist->top = newNode;
}

void pop(stack *playlist)
{
    node *tmp;
    tmp = playlist->top;
    playlist->top = tmp->nextNode;

    free(tmp);
}

void showPlaylist(stack *playlist, int playIndex)
{
    node *tmp;
    int i = 0;
    tmp = playlist->top;

    printf("\nNow Playing:\n");
    if (isEmptyPlaylist(playlist))
    {
        printf("Playlist kosong! Tambahkan lagu!\n");
        return;
    }

    // Reverse Stack untuk menampilkan secara FIFO
    stack *reversed_display;
    reversed_display = malloc(sizeof(stack *));
    reversed_display->top = NULL;
    while (tmp != NULL)
    {
        push(reversed_display, tmp->songData);
        tmp = tmp->nextNode;
    }

    // Tampilkan playlist dari hasil reverse stack
    tmp = reversed_display->top;
    while (tmp != NULL)
    {
        if (i == playIndex)
        {
            printf("-> %s oleh %s\n",
                   tmp->songData.penyanyi,
                   tmp->songData.judul);
        }
        else
        {
            printf("   %s oleh %s\n",
                   tmp->songData.penyanyi,
                   tmp->songData.judul);
        }
        tmp = tmp->nextNode;
        i++;
    }
}

int main()
{
    stack *currPlaylist;
    char *token;
    struct song songBuf;
    char str[75];
    currPlaylist = (stack *)malloc(sizeof(stack));
    // Inisialisasi Stack
    currPlaylist->top = NULL;
    char temp;

    char cmd = 'X';
    int numberofsong = 0;
    int nowIndex = -1;
    printf("-*-_-*-_-*-_-*-Jooxtify-*-_-*-_-*-_-*-");

    while (cmd != 'E')
    {
        showPlaylist(currPlaylist, nowIndex);

        printf("\nMasukkan Perintah: ");
        scanf("%c", &cmd);

        switch (cmd)
        {
        case '+':
        {
            printf("Masukkan Nama Lagu dan Penyanyi: ");
            scanf(" %[^\n]%*c", str);
            
            printf("%s\n", str);
//             for (int i = 0; i < strlen(str); i++)
//             {
//                 if (str[i] != )
//             }

            token = strtok(str, ",");
            strcpy(songBuf.penyanyi, token);
//             printf("%s\n", token);
//             for (int i = 0; i < strlen(str); i++)
//             {
//                 songBuf.penyanyi[i] = token[i];
//             }
            
            token = strtok(NULL, "\0");
            strcpy(songBuf.judul, token);
//             printf("%s\n", token);
//             for (int i = 0; i < strlen(token); i++)
//             {
//                 songBuf.judul[i] = token[i];
//             }

            push(currPlaylist, songBuf);
            numberofsong++;
            break;
        }

        case '>':
        {
            if (nowIndex >= numberofsong - 1)
            {
                nowIndex = 0;
            }
            else
            {
                nowIndex++;
            }
            break;
        }
        case '<':
        {
            if (nowIndex <= 0)
            {
                nowIndex = numberofsong - 1;
            }
            else if (nowIndex >= numberofsong - 1)
            {
                nowIndex = numberofsong - 1;
            }
            else
            {
                nowIndex--;
            }
            break;
        }
        case 'R':
        {
            nowIndex = 0;
            break;
        }
        case '-':
        {
            if (numberofsong != 0)
            {
                pop(currPlaylist);
                numberofsong--;
            }
            break;
        }

        case 'E':
            break;
        default:
        {
            printf("Masukan Perintah Tidak Valid!");
            break;
        }
        }
    }
    return 0;
}
