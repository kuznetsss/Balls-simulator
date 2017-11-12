#include "domain/physics.h"

#include <gtest/gtest.h>
#include <unordered_map>

#include "domain/ball.h"
#include "utils/vector2f.h"
#include "test_extesions.h"

using namespace domain;

TEST(Physics_Test, ForceCalculation)
{
    std::unordered_map<std::size_t, BallPtr> idToBallMap;
    const auto ball1 = std::make_shared<Ball>(utils::Vector2f(0.f, 0.f));
    idToBallMap.emplace(ball1->id().toStdSizeT(), ball1);
    auto ball2 = std::make_shared<Ball>(utils::Vector2f(3.f, 4.f));
    idToBallMap.emplace(ball2->id().toStdSizeT(), ball2);

    auto forceOnBall1 = Physics::calculateForceForBall(ball1, idToBallMap);
    EXPECT_VECTORS_EQ(forceOnBall1, utils::Vector2f(0.096f, 0.128f));

    ball2->setPosition(utils::Vector2f(0.f, 1.f));
    forceOnBall1 = Physics::calculateForceForBall(ball1, idToBallMap);
    EXPECT_VECTORS_EQ(forceOnBall1, utils::Vector2f());
}