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
    //Variabel boleh ditambahkan, namun tidak boleh dikurangi
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

//Boleh menambahkan fungsi untuk mengolah stack

//Menampilkan Playlist serta lagu yang diputar berdasarkan playIndex
void showPlaylist(stack *playlist, int playIndex)
{
    //Implementasi Fungsi
    printf("Playlist kosong! Tambahkan lagu!\n");

    //printf("-> %s oleh %s",//lagu, penyanyi
    //printf("   %s oleh %s",//lagu, penyanyi

}

int main()
{   
    //Beberapa variabel yang mungkin diperlukan
    stack *currPlaylist;
    char *token;
    struct song songBuf; //Struct buffer
    char str[75]; //Variabel Penampung Masukan Lagu dan Penyanyi
    char temp;
    char cmd = 'X'; //Variabel penyimpan perintah
    int numberofsong = 0; //Jumlah lagu yang tersimpan dalam playlist
    int nowIndex = -1; //Indeks lagu yang sedang diputar
    printf("-*-_-*-_-*-_-*-Jooxtify-*-_-*-_-*-_-*-");

    showPlaylist(currPlaylist, nowIndex);//Contoh penggunaan fungsi showPlaylist

    printf("\nMasukkan Perintah: ");
    printf("Masukkan Nama Lagu dan Penyanyi: ");
    // printf("Masukan Perintah Tidak Valid!"); 
    getchar(); //Perintah mengosongkan buffer bila diperlukan

    return 0;
}
