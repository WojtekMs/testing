#include "PlayerData.hpp"

#include <algorithm>

PlayerData::PlayerData(const std::string& n, const std::vector<Frame>& r) : name(n), rolls(r) {
}

bool PlayerData::operator==(const PlayerData& rhs) const {
    return name == rhs.name && rolls == rhs.rolls;
}

const std::vector<Frame>& PlayerData::getRolls() const {
    return rolls;
}

const std::string& PlayerData::getName() const {
    return name;
}

size_t PlayerData::countBonusStrikePoints(size_t frameIndex, int depth) const {
    size_t strikePoints = 0;
    if (!isRegularFrame(frameIndex)) {
        return 0;
    }
    if (frameIndex + 1 == rolls.size()) {
        return 0;
    }
    if (rolls[frameIndex + 1].isStrike()) {
        strikePoints += 10;
        if (frameIndex + 2 != rolls.size()) {
            strikePoints += rolls[frameIndex + 2].getFirstRollPoints();
        }
    } else {
        strikePoints += rolls[frameIndex + 1].getPoints();
    }
    return strikePoints;
}

size_t PlayerData::countBonusSparePoints(size_t frameIndex) const {
    if (!isRegularFrame(frameIndex)) {
        return 0;
    }
    if (frameIndex + 1 == rolls.size()) {
        return 0;
    }
    return rolls[frameIndex + 1].getFirstRollPoints();
}

size_t PlayerData::countPoints() const {
    size_t totalPoints = 0;
    for (size_t i = 0; i < rolls.size(); ++i) {
        if (rolls[i].isStrike()) {
            totalPoints += countBonusStrikePoints(i);
        } else if (rolls[i].isSpare()) {
            totalPoints += countBonusSparePoints(i);
        }
        if (isRegularFrame(i)) {
            totalPoints += rolls[i].getPoints();
        }
    }
    return totalPoints;
}

bool PlayerData::isRegularFrame(int frameIndex) const {
    return frameIndex >= 0 && frameIndex <= 9;
}

bool PlayerData::isBadCharacter(char roll) const {
    constexpr char badCharacters[]{'-', ' ', '\0'};
    return std::any_of(std::begin(badCharacters), std::end(badCharacters), [roll](char bad) { return roll == bad; });
}
