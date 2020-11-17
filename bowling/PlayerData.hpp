#pragma once

#include "Frame.hpp"

#include <string>
#include <vector>

class PlayerData {
    std::string name{};
    std::vector<Frame> rolls{};

    size_t countBonusStrikePoints(size_t frameIndex, int depth = 2) const;
    size_t countBonusSparePoints(size_t frameIndex) const;
    bool isBadCharacter(char) const;
    bool isRegularFrame(int frameIndex) const;

   public:
    PlayerData() = delete;
    PlayerData(const std::string& n, const std::vector<Frame>& r);
    bool operator==(const PlayerData& rhs) const;
    size_t countPoints() const;
    const std::vector<Frame>& getRolls() const;
    const std::string& getName() const;
};
