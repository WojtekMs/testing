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
                    std::pair<std::vector<Frame>, int>{{{'X', ' '},  // 19
                                                        {'4', '5'},  //+9 = 28
                                                        {'X', ' '},  //+21 = 49
                                                        {'X', ' '},  //+12 = 61
                                                        {'1', '1'},  //+2 = 63
                                                        {'X', ' '},  //+20 = 83
                                                        {'5', '/'},  //+20 = 103
                                                        {'X', ' '},  //+19 = 122
                                                        {'1', '8'},  //+9 = 131
                                                        {'X', ' '},  //+16 = 147
                                                        {'5', '1'}},
                                                       147},
                    std::pair<std::vector<Frame>, int>{{{'2', '/'}, {'4', '5'}, {'3', '/'}, {'2', '/'}, {'0', '/'}},
                                                       55},
                    std::pair<std::vector<Frame>, int>{
                        {{'X', ' '}, {'4', '5'}, {'X', ' '}, {'X', ' '}, {'1', '1'}, {'X', ' '}}, 73},
                    std::pair<std::vector<Frame>, int>{{{'1', '2'}, {'4', '5'}, {'2', '2'}, {'7', '0'}}, 23},
                    std::pair<std::vector<Frame>, int>{{{'X', ' '},  // 30
                                                        {'X', ' '},  //+30 = 60
                                                        {'X', ' '},  //+30 = 90
                                                        {'X', ' '},  //+30 = 120
                                                        {'X', ' '},  //+30 = 150
                                                        {'X', ' '},  //+30 = 180
                                                        {'X', ' '},  //+30 = 210
                                                        {'X', ' '},  //+30 = 240
                                                        {'X', ' '},  //+30 = 270
                                                        {'X', ' '},  //+30 = 300
                                                        {'X', ' '},
                                                        {'X', ' '}},
                                                       300},
                    std::pair<std::vector<Frame>, int>{{{'3', '/'},   // 15
                                                        {'5', '/'},   //+15 = 30
                                                        {'5', '/'},  //+15 = 45
                                                        {'5', '/'},   //+16 = 61
                                                        {'6', '/'},   //+16 = 77
                                                        {'6', '/'},   //+16 = 93
                                                        {'6', '/'},   //+17 = 110
                                                        {'7', '/'},   //+17 = 127
                                                        {'7', '/'},   //+18 = 145
                                                        {'8', '/'},   //+16 = 161
                                                        {'6', ' '}},
                                                       161}));
