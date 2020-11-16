#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

#include "Frame.hpp"
#include "PlayerData.hpp"

class PlayerTests : public ::testing::TestWithParam<std::pair<std::vector<Frame>, int>> {
   protected:
    std::string playerName{"John"};
};

TEST_P(PlayerTests, countPointsShouldCalculatePlayerScore) {
    auto [playerRolls, expectedScore] = GetParam();
    PlayerData player{playerName, playerRolls};
    auto actualScore = player.countPoints();
    EXPECT_EQ(expectedScore, actualScore);
}

INSTANTIATE_TEST_SUITE_P(
    testingManyScores,
    PlayerTests,
    testing::Values(std::pair<std::vector<Frame>, int>{{{'5', '2'}, {'7', '-'}}, 14},
                    std::pair<std::vector<Frame>, int>{{{'1', '2'}, {'7', '/'}, {'2', '1'}}, 18},
                    std::pair<std::vector<Frame>, int>{{{'X', ' '},
                                                        {'4', '5'},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'1', '1'},
                                                        {'X', ' '},
                                                        {'5', '/'},
                                                        {'X', ' '},
                                                        {'1', '8'},
                                                        {'X', ' '},
                                                        {'5', '1'}},
                                                       152},
                    std::pair<std::vector<Frame>, int>{{{'2', '/'}, {'4', '5'}, {'3', '/'}, {'2', '/'}, {'0', '/'}},
                                                       55},
                    std::pair<std::vector<Frame>, int>{
                        {{'X', ' '}, {'4', '5'}, {'X', ' '}, {'X', ' '}, {'1', '1'}, {'X', ' '}}, 72},
                    std::pair<std::vector<Frame>, int>{{{'1', '2'}, {'4', '5'}, {'2', '2'}, {'7', '0'}}, 23},
                    std::pair<std::vector<Frame>, int>{{{'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '},
                                                        {'X', ' '}},
                                                       300}));
