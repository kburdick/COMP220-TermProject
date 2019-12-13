//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "MusicLibrary.h"
#include "FileIO.h"
#include "Song.h"

//default constructor creates an empty music library
MusicLibrary::MusicLibrary() {
    this->arrayOfSongs = new ArrayList(10);
    this->totalSongCount = 0;
}

MusicLibrary::MusicLibrary(ArrayList* listOfSongs) {
    this->arrayOfSongs = listOfSongs;
    this->totalSongCount = listOfSongs->getCurrentItemCount();
}

//destructor
MusicLibrary::~MusicLibrary() {
    delete [] arrayOfSongs;
}
/**
 * calls the file read in method
 * @param the name of the file in which to read in
 * @post generates a music library and prints out any songs that are already in the playlist
 */
void MusicLibrary::fileReadIn(std::string fileName){
    this->arrayOfSongs = readLibrary(fileName);
    this->totalSongCount = arrayOfSongs->getCurrentItemCount();
}


/**
 * Writes a playlist or library to fileName
 * @param fileName
 */
void MusicLibrary::WriteFile(std::string fileName) {
    arrayOfSongs->WriteFile(fileName);
}

/**
   * Removes all songs from the music library and any occurrences of those songs within the valid playlists
   * Prints out a message of any songs that do not occur within the library or the playlist
   * @param the name of the file containing all of the songs that should be removed from the library and playlists
   * @post a library and playlists without the songs given in the file
   */
void MusicLibrary::removeSongs(std::string fileName){
   ArrayList* tempLib = readLibrary(fileName);
   std::string titleToCheck;
   std::string titleToCheck2;
   int count2 = arrayOfSongs->getCurrentItemCount();
   int count = tempLib->getCurrentItemCount();
   for(int i = 0; i <= count; i++) {
       Song temp = tempLib->getValueAt(i);
       //std::cout << temp.toString() << std::endl;
       titleToCheck = temp.getSongTitle();
       for(int x = 0; x <= count2; x++){
           Song temp2 = arrayOfSongs->getValueAt(x);
           titleToCheck2 = temp2.getSongTitle();
           if(titleToCheck == titleToCheck2){
               arrayOfSongs->removeSong(temp);
               std::cout << "I'm here baby" << std::endl;
           }
           int foundSong = arrayOfSongs->findSong(temp);
           if(foundSong == 0){
               std::cout << temp.toString() << std::endl;
           }


       }
   }


}

/**
  * displays all songs within the music library
  * @post a list of all the songs within the music library printed to the user
  */
void MusicLibrary::displayAllSongs(){
    arrayOfSongs->toString();
}

/**
  * takes in an artist from the user
  * @param the name of the artist
  * @post a list of all the songs from the given artist is displayed to the user
  */
void MusicLibrary::displayArtist(std::string artist){

    int size = arrayOfSongs->getCurrentItemCount();
    std::string artistToCheck;
    for(int i = 0; i < size; i++){
        Song temp = arrayOfSongs->getValueAt(i);
        artistToCheck = temp.getSongArtist();
        if(artist == artistToCheck){
            std::cout<< temp.toString() << std::endl;
        }
    }
    // may need to manipulate so that it only prints out the song title and not all the information from the song obj

}

/**
  * displays all information of the song given an artist and a title
  * @param the name of the artist
  * @param the title of the song
  * @post a list of information about the song is displayed to the user
  */
std::string MusicLibrary::displaySongInfo(std::string artist, std::string title){
    int size = arrayOfSongs->getCurrentItemCount();
    std::string artistToCheck;
    std::string titleToCheck;
    std::string songString;
    for(int i = 0; i < size; i++){
        Song temp = arrayOfSongs->getValueAt(i);
        artistToCheck = temp.getSongArtist();
        titleToCheck = temp.getSongTitle();
        if(artist == artistToCheck && title == titleToCheck){
            songString =  temp.toString();
            return songString;
        }
    }

    return songString;
}


int MusicLibrary::sumDuration(){
    int size = arrayOfSongs->getCurrentItemCount();
    int duration = 0;

    for(int i = 0; i < size; i++) {
        Song temp = arrayOfSongs->getValueAt(i);

        duration = duration + temp.getSongDuration();
    }

    return duration; //TODO check function this currently returns seconds!
}

Song* MusicLibrary::findSong(Song songToFind) {
    std::string temp = songToFind.getSongTitle();

    int indexOfSong = arrayOfSongs->findSongByTitle(temp);

    Song newSong = arrayOfSongs->getValueAt(indexOfSong);

    return &newSong;
}

Song MusicLibrary::findSongAtIndex(int index){
    Song temp = arrayOfSongs->getValueAt(index);

    return temp;
}

int MusicLibrary::getItemCount() {
    int count = arrayOfSongs->getCurrentItemCount();

    return count;
}





