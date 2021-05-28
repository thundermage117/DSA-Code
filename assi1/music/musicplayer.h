//search, playlists, genre, artist, album
//player:shuffle, previous , next, pause, play,repeat, volume
#ifndef __PLAYER_H
#define __PLAYER_H

typedef struct song_data song;
typedef struct list* playlist;

struct song_data
{
    char filename[50];//location of the song
    char artist[30];
    char genre[30];
    char album_name[30];
    int song_len;//Length of the song in seconds
};

struct list //playlist implementation using linked lists
{
    song s1;
    struct list *next;
};

playlist ALL_SONGS;//Playlist containing all songs


song create_song();//function to add new songs in the system, add_song(ALL_SONGS, new_song) called, also creates or adds song to a playlist based on album name,artist and genre
playlist create_playlist(song,char*);//creates a new playlist defined by the user

void add_song(playlist,song);//fn to add song to any playlist
void remove_song(playlist,song);//fn to remove song from the playlist

song search_song(char[50]); //fn to search based on given text(it maybe song name, album name,artist etc)

//MUSIC PLAYER INTERFACE

void play_song(song,int time=0);//unfortunately C doesn't allow default parameters
int pause_song();//returns the time the song was paused, value used in play_song

void next_song(song, playlist);//plays the next song in a playlist, play_song() is called at end
void prev_song(song, playlist);//plays the previous song in a playlist,play_song() called at end

void repeat(int);//takes 0,1,2 as input, 0= repeat off, 1= repeats playlist once complete,2= repeats the song continously
playlist shuffle(int, playlist);//0 or 1 as input, 0=no shuffle, 1=shuffle , returns a new temporary shuffled playlist(shuffling maybe implemented using rand function)

void volume_set(int); //input lies between 0-100, sets volume accordingly

#endif