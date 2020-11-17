#include "BowlingAlley.hpp"
#include "Game.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace fs = std::filesystem;

BowlingAlley::BowlingAlley(const fs::path& pathToFolder) : path_(pathToFolder) {
    loadFromFolder(path_);
}

void BowlingAlley::loadFromFolder(const fs::path& pathToFolder) {
    if (!fs::is_directory(pathToFolder)) {
        throw std::invalid_argument{"please enter path to directory!\n"};
    }
    games_.clear();
    for (auto& entry : fs::directory_iterator(pathToFolder)) {
        if (entry.is_regular_file()) {
            games_.emplace_back(std::make_shared<Game>(entry.path()));
        }
    }
}

std::string BowlingAlley::getOutputString() {
    std::stringstream stream{};
    for (size_t i = 0; i < games_.size(); ++i) {
        stream << games_[i]->getOutputString(i + 1);
    }
    return stream.str();
}

const std::vector<std::shared_ptr<Game>>& BowlingAlley::getGames() const {
    return games_;
}
