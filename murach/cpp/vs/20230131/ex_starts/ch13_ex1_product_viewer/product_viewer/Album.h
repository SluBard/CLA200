#pragma once
#include "Media.h"
#include <string>

class Album : public Media
{
private:
	std::string artist;
public:
    Album(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string format = "", std::string artist_param = "") :
        Media(name, price, disc_pct, format) {
        artist = artist_param;
    }

    void set_artist(std::string artist_param) {
        artist = artist_param;
    }
    std::string get_artist() const {
        return artist;
    }

    std::string get_description() const {
        return name + " by " + artist + " " + format;
    }
};

