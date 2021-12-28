#include "gtest/gtest.h"
#include "src/GameManager/GameManager.h"
#include "src/Castle/Castle.h"
#include "src/Point/Point.h"
#include <memory>


TEST(Castle, Constructor) {
    TowerDefence::Table<int, TowerDefence::CastleData> table;
    TowerDefence::Point point(1, 1);
    TowerDefence::Castle castle(TowerDefence::Point(1, 1), 10, 10, 15, table);
    ASSERT_EQ(point, castle.getPoint());
    ASSERT_EQ(10, castle.getHealth());
    ASSERT_EQ(10, castle.getMaxHealth());
    ASSERT_EQ(15, castle.getGold());
}

TEST(Castle, Method) {
    TowerDefence::CastleData castleData(1, 1, 1, 1);
    TowerDefence::Pair<int, TowerDefence::CastleData> pair(1, castleData);
    TowerDefence::Point point(1, 1);
    TowerDefence::Table<int, TowerDefence::CastleData> table;
    table.push(pair);
    TowerDefence::Castle castle(TowerDefence::Point(1, 1), 10, 10, 15, table);
    castle.update();
    std::cout << castle.getGold() << std::endl;
    ASSERT_EQ(point, castle.getPoint());
    ASSERT_EQ(10, castle.getHealth());
    ASSERT_EQ(10, castle.getMaxHealth());
    ASSERT_EQ(16, castle.getGold());
}

TEST(Enemy, Constructor) {
    TowerDefence::Point point(1, 1);
    std::vector<TowerDefence::Point> route;
    route.push_back(point);
    TowerDefence::Enemy enemy(point, 10, 10, 15, 5, 5, route);
    ASSERT_EQ(point, enemy.getPoint());
    ASSERT_EQ(10, enemy.getHealth());
    ASSERT_EQ(10, enemy.getMaxHealth());
    ASSERT_EQ(15, enemy.getSpeed());
    ASSERT_EQ(5, enemy.getRecovery());
    ASSERT_EQ(5, enemy.getDamage());
    ASSERT_EQ(route, enemy.getRoute());
}

TEST(Tower, Constructor) {
    TowerDefence::TowerData castleData(1, 1, 1, 1);
    TowerDefence::Pair<int, TowerDefence::TowerData> pair(1, castleData);
    TowerDefence::Table<int, TowerDefence::TowerData> table;
    table.push(pair);
    TowerDefence::Point point(1, 1);
    TowerDefence::Tower tower(point, 1, table);

    ASSERT_EQ(point, tower.getPoint());
    ASSERT_EQ(1, tower.getMLevel());
}

TEST(Tower, Method) {
    TowerDefence::TowerData castleData(1, 1, 1, 1);
    TowerDefence::Pair<int, TowerDefence::TowerData> pair(1, castleData);
    TowerDefence::Table<int, TowerDefence::TowerData> table;
    table.push(pair);
    TowerDefence::Point point(1, 1);
    TowerDefence::Tower tower(point, 1, table);

    std::vector<TowerDefence::Point> route;
    route.push_back(point);
    std::shared_ptr<TowerDefence::Enemy>enemy = std::make_shared<TowerDefence::Enemy>(point, 10, 10, 15, 5, 5, route);

    tower.attackEnemy(enemy);

    ASSERT_EQ(9, enemy->getHealth());
}




int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

