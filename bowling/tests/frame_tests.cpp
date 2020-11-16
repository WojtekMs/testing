#include <gtest/gtest.h>

#include "Frame.hpp"

TEST(FrameTest, defaultFrameShouldBeEmpty) {
    Frame defaultFrame;
    EXPECT_EQ(defaultFrame.getFirstRoll(), ' ');
    EXPECT_EQ(defaultFrame.getSecondRoll(), ' ');
}

TEST(FrameTest, whenFirstRollIsXIsStrikeShouldReturnTrue) {
    Frame strikeFrame('X', ' ');
    EXPECT_TRUE(strikeFrame.isStrike());
}

TEST(FrameTest, whenFirstRollIsNotXIsStrikeShouldReturnFalse) {
    Frame firstFrame('5', '2');
    EXPECT_FALSE(firstFrame.isStrike());
    Frame secondFrame('5', '/');
    EXPECT_FALSE(secondFrame.isStrike());
    Frame thirdFrame('5', '-');
    EXPECT_FALSE(thirdFrame.isStrike());
}

TEST(FrameTest, whenSecondRollIsSpareIsSpareShouldReturnTrue) {
    Frame strikeFrame('5', '/');
    EXPECT_TRUE(strikeFrame.isSpare());
}

TEST(FrameTest, whenSecondRollIsNotSpareIsSpareShouldReturnFalse) {
    Frame firstFrame('5', '4');
    EXPECT_FALSE(firstFrame.isSpare());
    Frame secondFrame('5', '-');
    EXPECT_FALSE(secondFrame.isSpare());
}

TEST(FrameTest, whenBothRollsAreEqualComparisonOperatorShouldReturnTrue) {
    Frame firstFrame('2', '2');
    Frame secondFrame('2', '2');
    EXPECT_TRUE(firstFrame == secondFrame);
}

TEST(FrameTest, whenBothRollsAreNotEqualComparisonOperatorShouldReturnFalse) {
    Frame firstFrame('2', '2');
    Frame secondFrame('3', '2');
    EXPECT_FALSE(firstFrame == secondFrame);
}
