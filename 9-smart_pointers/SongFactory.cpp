#include <iostream>
#include <memory>
#include <vector>

class Song {
    public:
    std::string _artist;
    std::string _title;
    Song(std::string artist, std::string title)
        : _artist(artist), _title(title) 
    { std::cout << "Created " << _title << " by " << _artist << std::endl;}
    ~Song() {
        std::cout << _title << " deleted!" << std::endl;
    }
};

void songFactory() {
    std::vector<std::unique_ptr<Song>> songs;

    songs.push_back(std::make_unique<Song>("Author 1", "Song 1"));
    songs.push_back(std::make_unique<Song>("Author 2", "Song 2"));
    songs.push_back(std::make_unique<Song>("Author 3", "Song 3"));
    songs.push_back(std::make_unique<Song>("Author 4", "Song 4"));

    for (const auto &song : songs) // copy constructor deleted
        std::cout << "Artist: " << song->_artist << " Title: " << song->_title << std::endl;
}
int main() {
    songFactory();


    return 0;
}