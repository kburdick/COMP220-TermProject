//
// Created by Kurt Burdick on 11/18/19.
//

#include <stdexcept>
#include <sstream>
#include "Song.h"

//constructor for the song class
Song::Song(std::string title, std::string artist, float duration) {

    this->title = title;
    this->artist = artist;
    this->duration = duration;
    this->playCount = 0;
}

//constructor that creates a song from a single string input
// TODO: this will be used to get the list of songs from the text file and create new song objects!
Song::Song(std::string songString) {

    std::stringstream splitter(songString);
    std::string songInfo = "";
    std::string titleString;
    std::string artistString;
    float durationString = 0;
    int playCountString = 0;

    //TODO: clean up this if statement with more concise code
    // it works... but looks bad
    if(splitter) {
        getline(splitter, songInfo, '\t');
        titleString = songInfo;
        songInfo = "";
        getline(splitter, songInfo, '\t');
        artistString = songInfo;
        songInfo = "";
        getline(splitter, songInfo, '\t');
        durationString = stof(songInfo);
        songInfo = "";
        getline(splitter, songInfo, '\t');
        playCountString = stoi(songInfo);
        songInfo = "";
    }

    this->title = titleString;
    this->artist = artistString;
    this->duration = durationString;
    this->playCount = playCountString;

}

// copy constructor
Song::Song(const Song& songToCopy) {

    this->title = songToCopy.title;
    this->artist = songToCopy.artist;
    this->duration = songToCopy.duration;
    this->playCount = songToCopy.playCount;

}

// returns a song by reference
// a combination of the copy constructor and the destructor
// not entirely necessary because their is not dynamic memory (could use implicit copy and assignment)
Song& Song::operator=(const Song& songToCopy) {

    if(this != &songToCopy) {

        this->title = songToCopy.title;
        this->artist = songToCopy.artist;
        this->duration = songToCopy.duration;
        this->playCount = songToCopy.playCount;

    }

    //needs a return value that is a reference to another object
    return *this;
}

Song::~Song(){
    //again can use the default destructor because no data is dynamically allocated
}


//setters start
void Song::updateSongTitle(std::string title) {
    this->title = title;
}

void Song::updateSongArtist(std::string artist) {
    this->artist = artist;
}

void Song::updateSongDuration(float duration) {
    this->duration = duration;
}

void Song::updatePlayCount(int num) {
    this->playCount = playCount + num;
}
//setters end

//getters start
std::string  Song::getSongTitle() {
    return this->title;
}

std::string Song::getSongArtist() {
    return this->artist;
}

float Song::getSongDuration() {
    return this->duration;
}

int Song::getPlayCount() {
    return this->playCount;
}
//getters end


//additional methods
// need to make another file that contains a toString method to read and write from files...
// TODO: do we want to use CSV or tab character delimited strings?
std::string Song::toString() {
    std::string songString = "";

    //example of a CSV style string
    //songString = title + ", " + artist + ", " + std::to_string(duration);

    //example of a tab delimited string
    songString = title + "\t" + artist + "\t" + std::to_string(duration) + '\t' + std::to_string(playCount);

    return songString;
}
