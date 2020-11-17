#include <gtest/gtest.h>

#include "Frame.hpp"

class FrameTest : public ::testing::TestWithParam<std::pair<Frame, int>> {
   protected:
};

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

TEST_P(FrameTest, getPointsShouldReturnCalculatedPointsForOneFrame) {
    auto [frame, expectedPoints] = GetParam();
    auto actualPoints = frame.getPoints();
    EXPECT_EQ(expectedPoints, actualPoints);
}

INSTANTIATE_TEST_SUITE_P(calculatingManyScores,
                         FrameTest,
                         testing::Values(std::pair<Frame, int>{{'3', '3'}, 6},
                                         std::pair<Frame, int>{{'1', '3'}, 4},
                                         std::pair<Frame, int>{{'0', '/'}, 10},
                                         std::pair<Frame, int>{{'X', ' '}, 10},
                                         std::pair<Frame, int>{{'3', '\0'}, 3},
                                         std::pair<Frame, int>{{'3', '-'}, 3},
                                         std::pair<Frame, int>{{'3', ' '}, 3},
                                         std::pair<Frame, int>{{'0', '-'}, 0},
                                         std::pair<Frame, int>{{'5', '/'}, 10},
                                         std::pair<Frame, int>{{'3', '6'}, 9},
                                         std::pair<Frame, int>{{' ', ' '}, 0},
                                         std::pair<Frame, int>{{' ', '\0'}, 0},
                                         std::pair<Frame, int>{{' ', '-'}, 0}));
