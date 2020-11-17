#include "Frame.hpp"
#include <algorithm>

Frame::Frame(char first, char second) : firstRoll(first), secondRoll(second) {
}

bool Frame::operator==(const Frame& rhs) const {
    return firstRoll == rhs.firstRoll && secondRoll == rhs.secondRoll;
}

bool Frame::isBadCharacter(char roll) const {
    constexpr char badCharacters[]{'-', ' ', '\0'};
    return std::any_of(std::begin(badCharacters), std::end(badCharacters), [roll](char bad) { return roll == bad; });
}

char Frame::getFirstRoll() const {
    return firstRoll;
};

char Frame::getSecondRoll() const {
    return secondRoll;
};

size_t Frame::getPoints() const {
    if (isBadCharacter(firstRoll) && isBadCharacter(secondRoll)) {
        return 0;
    }
    if (isStrike() || isSpare()) {
        return 10;
    }
    if (isBadCharacter(firstRoll)) {
        return secondRoll - '0';
    }
    if (isBadCharacter(secondRoll)) {
        return firstRoll - '0';
    }
    return (firstRoll - '0') + (secondRoll - '0');
}

size_t Frame::getFirstRollPoints() const {
    if (isBadCharacter(firstRoll)) {
        return 0;
    }
    if (isStrike()) {
        return 10;
    }
    return firstRoll - '0';
}

std::ostream& operator<<(std::ostream& os, const Frame& frame) {
    os << "{" << frame.firstRoll << ", " << frame.secondRoll << "}";
    return os;
}

bool Frame::isSpare() const {
    return secondRoll == '/';
}

bool Frame::isStrike() const {
    return firstRoll == 'X';
}
