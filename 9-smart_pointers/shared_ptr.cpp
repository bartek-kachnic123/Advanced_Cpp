#include <iostream>
#include <memory>

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

void inner_func(std::shared_ptr<Song> ptr) {
    std::cout << "Wykonywanie...." << std::endl;

}

void test() {
    std::shared_ptr<Song> ptr_empty (nullptr);
    {
        auto ptr  = std::make_unique<Song>("Author 1", "Song 1");
        auto shared_ptr = std::make_shared<Song>("Author 2", "Song 2");
        ptr_empty = shared_ptr;
    }
    std::cout << "Exit!" << std::endl;
}


int main() {
    test();

    return 0;
}