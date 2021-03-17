/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#include <string>
#include "Game.hpp"
#include <unistd.h>

namespace IndieStudio {
    Game::Game(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state, std::shared_ptr<selectMenuConfig> selectMenuConfig) 
        : Scene(device, state), _selectMenuConfig(selectMenuConfig), _nbObj(0), _map(19),
        _entities(std::make_shared<std::map<std::string, std::shared_ptr<Entity>>>())
    {
        initScene();
        _selectMenuConfig->playersSkinDae[0] = irr::io::path(pathProject) + "/resources/Game/Personnage/Aj/Aj.MD3";
        _selectMenuConfig->playersSkinImage[0] = irr::io::path(pathProject) + "/resources/Game/Personnage/Aj/Aj.jpg";
        _selectMenuConfig->playersSkinDae[1] = irr::io::path(pathProject) + "/resources/Game/Personnage/Claire/Claire.MD3";
        _selectMenuConfig->playersSkinImage[1] = irr::io::path(pathProject) + "/resources/Game/Personnage/Claire/Claire.jpg";
    }

    Game::~Game()
    {
    }

    void Game::initScene()
    {
        initTextures();
        setConfigurations();
    }

    void Game::initTextures()
    {
        irr::scene::IMesh *ground;

        _textures["GROUND"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/Ground/Ground.png");
        ground = _smng->getGeometryCreator()->createPlaneMesh(irr::core::dimension2d<irr::f32>(2, 2), irr::core::dimension2d<irr::u32>(100, 100));
        ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _ground = _smng->addMeshSceneNode(ground);

        _textures["WALL"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/BreakWall/BreakWall.jpg");
        _meshes["WALL"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));

        _textures["UNBREAKWALL"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/UnbreakWall/UnbreakWall.jpg");
        _meshes["UNBREAKWALL"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));

        _meshes["BOMB"] = _smng->getMesh(irr::io::path(pathProject) + "/resources/Game/Grenade/Grenade.dae");
        _textures["EXPLOSION"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/Grenade/explosion.png");
        _meshes["EXPLOSION"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));

        _textures["WINGS"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/PowerUp/wings.png");
        _textures["SPEED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/PowerUp/speed.jpg");
        _textures["GRENADE"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/PowerUp/grenade.png");
        _textures["FIRE"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Game/PowerUp/fire.jpg");
        _meshes["WINGS"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));
        _meshes["SPEED"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));
        _meshes["GRENADE"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));
        _meshes["FIRE"] = _smng->getGeometryCreator()->createCubeMesh(irr::core::vector3df((5.0F), (15.0F), (5.0F)));
    }

    void Game::setConfigurations()
    {
        _ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _ground->setMaterialTexture(0, _textures["GROUND"]);
        _ground->setPosition(irr::core::vector3df(0, 0, 0));

        addContourWallSceneNode(-100, 100, "UNBREAKWALL");
        setAllObjectOnMap(-90, 90, _map.getMap());

        _camera = _smng->addCameraSceneNode(_ground, irr::core::vector3df(0, 180, -1));
        _camera->setTarget(_ground->getPosition());
    }

    void Game::addContourWallSceneNode(float x, float z, std::string const &name)
    {
        const int max = 100;
        const int min = -100;

        while (x < max) {
            std::string tmp = name + std::to_string(_nbObj);
            (*_entities)[tmp] = std::make_shared<Entity>(EntityType::UNBREAKWALLBORDURE, _smng->addMeshSceneNode(_meshes[name]));
            _ground->addChild((*_entities)[tmp]->getSceneNode());
            (*_entities)[tmp]->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            (*_entities)[tmp]->getSceneNode()->setMaterialTexture(0, _textures[name]);
            (*_entities)[tmp]->getSceneNode()->setPosition({x, 10, z});
            _nbObj += 1;
            x += 10;
        }
        while (z > min) {
            std::string tmp = name + std::to_string(_nbObj);
            (*_entities)[tmp] = std::make_shared<Entity>(EntityType::UNBREAKWALLBORDURE, _smng->addMeshSceneNode(_meshes[name]));
            _ground->addChild((*_entities)[tmp]->getSceneNode());
            (*_entities)[tmp]->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            (*_entities)[tmp]->getSceneNode()->setMaterialTexture(0, _textures[name]);
            (*_entities)[tmp]->getSceneNode()->setPosition({x, 10, z});
            _nbObj += 1;
            z -= 10;
        }
        while (x > min) {
            std::string tmp = name + std::to_string(_nbObj);
            (*_entities)[tmp] = std::make_shared<Entity>(EntityType::UNBREAKWALLBORDURE, _smng->addMeshSceneNode(_meshes[name]));
            _ground->addChild((*_entities)[tmp]->getSceneNode());
            (*_entities)[tmp]->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            (*_entities)[tmp]->getSceneNode()->setMaterialTexture(0, _textures[name]);
            (*_entities)[tmp]->getSceneNode()->setPosition({x, 10, z});
            _nbObj += 1;
            x -= 10;
        }
        while (z < max) {
            std::string tmp = name + std::to_string(_nbObj);
            (*_entities)[tmp] = std::make_shared<Entity>(EntityType::UNBREAKWALLBORDURE, _smng->addMeshSceneNode(_meshes[name]));
            _ground->addChild((*_entities)[tmp]->getSceneNode());
            (*_entities)[tmp]->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            (*_entities)[tmp]->getSceneNode()->setMaterialTexture(0, _textures[name]);
            (*_entities)[tmp]->getSceneNode()->setPosition({x, 10, z});
            _nbObj += 1;
            z += 10;
        }
    }

    void Game::setObjectOnMap(float x, float z, std::string const &name, EntityType type, float time, std::string const &playerID)
    {
        std::string tmp = name + std::to_string(_nbObj);
        (*_entities)[tmp] = std::make_shared<Entity>(type, _smng->addMeshSceneNode(_meshes[name]), time, playerID);
        _ground->addChild((*_entities)[tmp]->getSceneNode());
        (*_entities)[tmp]->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        (*_entities)[tmp]->getSceneNode()->setMaterialTexture(0, _textures[name]);
        (*_entities)[tmp]->getSceneNode()->setPosition({x, 0, z});
        _nbObj += 1;
    }

    void Game::setAllObjectOnMap(float x, float z, std::map<int, std::map<int, char>> map)
    {
        float tmpx = x;
        float tmpz = z;

        for (auto a : map) {
            for (auto b: a.second) {
                if (b.second == 'u')
                    setObjectOnMap(tmpx, tmpz, "UNBREAKWALL", EntityType::UNBREAKWALL, 0);
                else if (b.second == 'c')
                    setObjectOnMap(tmpx, tmpz, "WALL", EntityType::WALL, 0);
                tmpx += 10;
            }
            tmpz -= 10;
            tmpx = x;
        }
    }

    void Game::updatePlayerStat(Player player, EntityType const &type, irr::core::vector3df const &entityPos)
    {
        if (type == EntityType::PBOMB)
            player.addBombs();
        if (type == EntityType::PPASSWALL)
            player.addPassWall();
        if (type == EntityType::PRANGE)
            player.addRange();
        if (type == EntityType::PSPEED)
            player.addSpeed();
        dropEntityByPos(entityPos);
    }

    bool Game::haveCollision(Player player, float offsetX, float offsetZ)
    {
        const auto playerNextPositionX = player.getMesh()->getPosition().X + offsetX;
        const auto playerNextPositionZ = player.getMesh()->getPosition().Z + offsetZ;

        for (auto &entity : (*_entities)) {
            if (playerNextPositionX == entity.second->getSceneNode()->getPosition().X &&
                playerNextPositionZ == entity.second->getSceneNode()->getPosition().Z) {
                if (entity.second->getType() == EntityType::UNBREAKWALLBORDURE)
                    return true;
                if (entity.second->getType() == EntityType::PBOMB ||
                    entity.second->getType() == EntityType::PPASSWALL ||
                    entity.second->getType() == EntityType::PRANGE ||
                    entity.second->getType() == EntityType::PSPEED) {
                    updatePlayerStat(player, entity.second->getType(), entity.second->getSceneNode()->getPosition());
                    return false;
                }
                if (player.getPassWall())
                    return false;
                return true;
            }
        }
        return false;
    }

    void Game::setVisible(bool const &status)
    {
        _ground->setVisible(status);
        for (auto button : _buttons)
            button.second->setVisible(status);
        for (auto image : _images)
            image.second->setVisible(status);
        for (auto player : _players) {
            if (player.second.getIsAlive())
                player.second.getMesh()->setVisible(status);
        }
        for (auto &entity : (*_entities))
            entity.second->getSceneNode()->setVisible(status);
    }

    void Game::initConfiguration()
    {
        if (!_isFirstTime)
            return;

        irr::core::vector3df positions1 = *_hasPositions ? _playerOne.getMesh()->getPosition() : irr::core::vector3df(-90, 0, 90);
        irr::core::vector3df positions2 = *_hasPositions ? _playerTwo.getMesh()->getPosition() : irr::core::vector3df(90, 0, -90);

        _textures["PLAYERONE"] = _driver->getTexture(_selectMenuConfig->playersSkinImage[0]);
        _mesh["PLAYERONE"] = _smng->addAnimatedMeshSceneNode(_smng->getMesh(_selectMenuConfig->playersSkinDae[0]));
        _textures["PLAYERTWO"] = _driver->getTexture(_selectMenuConfig->playersSkinImage[1]);
        _mesh["PLAYERTWO"] = _smng->addAnimatedMeshSceneNode(_smng->getMesh(_selectMenuConfig->playersSkinDae[1]));

        _playerOne = Player(0, _map, _mesh["PLAYERONE"], _textures["PLAYERONE"], positions1,
            std::make_shared<std::map<std::string, irr::scene::IMesh *>>(_meshes),
            _entities,
            _smng,
            false);
        _playerTwo = Player(1, _map, _mesh["PLAYERTWO"], _textures["PLAYERTWO"], positions2,
            std::make_shared<std::map<std::string, irr::scene::IMesh *>>(_meshes),
            _entities,
            _smng,
            !_selectMenuConfig->haveTwoPlayer);
        _players["PLAYERONE"] = _playerOne;
        _players["PLAYERTWO"] = _playerTwo;
        _isFirstTime = false;
    }

    void Game::quit()
    {
        _isFirstTime = true;
    }

    bool Game::checkWallByPos(float x, float z)
    {
        for (auto &entity : *_entities) {
            EntityType tmpType = entity.second->getType();
            if (tmpType == EntityType::WALL || tmpType == EntityType::UNBREAKWALL || tmpType == EntityType::UNBREAKWALLBORDURE) {
                irr::core::vector3df tmp = entity.second->getSceneNode()->getPosition();
                if (tmp.X == x && tmp.Z == z) {
                    return true;
                }
            }
        }
        return false;
    }

    void Game::addExplosionByRange(irr::core::vector3df const &pos, int range, irr::scene::ISceneNode *node, std::string const &playerID)
    {
        const int total_block = 1 * range;

        setObjectOnMap(pos.X, pos.Z, "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
        for (int i = 1; i <= total_block; i++) {
            if (checkWallByPos(pos.X, pos.Z + (10 * i))) {
                setObjectOnMap(pos.X, pos.Z + (10 * i), "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
                i = total_block + 1;
            }
            else
                setObjectOnMap(pos.X, pos.Z + (10 * i), "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
        }
        for (int i = 1; i <= total_block; i++) {
            if (checkWallByPos(pos.X, pos.Z - (10 * i))) {
                setObjectOnMap(pos.X, pos.Z - (10 * i), "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
                i = total_block + 1;
            }
            else
                setObjectOnMap(pos.X, (pos.Z - (10 * i)), "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
        }
        for (int i = 1; i <= total_block; i++) {
            if (checkWallByPos(pos.X - (10 * i), pos.Z)) {
                setObjectOnMap(pos.X - (10 * i), pos.Z, "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
                i = total_block + 1;
            }
            else
                setObjectOnMap(pos.X - (10 * i), pos.Z, "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
        }
        for (int i = 1; i <= total_block; i++) {
            if (checkWallByPos(pos.X + (10 * i), pos.Z)) {
                setObjectOnMap(pos.X + (10 * i), pos.Z, "EXPLOSION", EntityType::EXPLOSION, 0.75, playerID);
                i = total_block + 1;
            }
            else
                setObjectOnMap(pos.X + (10 * i), pos.Z, "EXPLOSION", EntityType::EXPLOSION, 0.75);
        }
    }

    void Game::addPowerUpWhenWallIsDestroy(irr::core::vector3df const &pos)
    {
        srand(time(NULL));
       int nb = rand() % 8 + 0;

        if (nb == 1 || nb == 2)
            setObjectOnMap(pos.X, pos.Z, "GRENADE", EntityType::PBOMB, 10);
        else if (nb == 3 || nb == 4)
            setObjectOnMap(pos.X, pos.Z, "FIRE", EntityType::PRANGE, 10);
        else if (nb == 5)
            setObjectOnMap(pos.X, pos.Z, "WINGS", EntityType::PPASSWALL, 10);
        else if (nb == 6 || nb == 7)
            setObjectOnMap(pos.X, pos.Z, "SPEED", EntityType::PSPEED, 10);
    }

    void Game::dropEntityByPos(irr::core::vector3df const &pos)
    {
        for (auto &entity : *_entities) {
            irr::core::vector3df tmp = entity.second->getSceneNode()->getPosition();
            if (entity.second->getType() == EntityType::WALL) {
                if (pos == tmp) {
                    addPowerUpWhenWallIsDestroy(tmp);
                    entity.second->getSceneNode()->remove();
                    entity.second.reset();
                    (*_entities).erase(entity.first);
                    break;
                }
            }
            if (entity.second->getType() == EntityType::PBOMB ||
                entity.second->getType() == EntityType::PPASSWALL ||
                entity.second->getType() == EntityType::PRANGE ||
                entity.second->getType() == EntityType::PSPEED) {
                if (pos == tmp) {
                    entity.second->getSceneNode()->remove();
                    entity.second.reset();
                    (*_entities).erase(entity.first);
                    break;
                }
            }
        }
        for (auto player : _players) {
            if (player.second.getIsAlive() && player.second.getMesh()->getPosition() == pos) {
                player.second.setIsAlive(false);
                player.second.getMesh()->removeAll();
                player.second.getMesh()->removeAnimators();
                player.second.getMesh()->remove();
                break;
            }
        }
    }

      void Game::moveIa(Player player, irr::core::vector3df actualPos, irr::core::vector3df bestMov)
    {
        actualPos.X = actualPos.X + bestMov.X;
        actualPos.Y = actualPos.Y + bestMov.Y;
        actualPos.Z = actualPos.Z + bestMov.Z;
        player.setUpdateMove(true, bestMov.X, bestMov.Z);
    }

    void Game::findMoveIa(Player player)
    {
        irr::core::vector3df actualPos = player.getMesh()->getPosition();
        irr::core::vector3df bestMove = irr::core::vector3df(0, 0, 0);
        int x = 10;
        int z = 10;
        int timeout = 0;
        static int nb = 0;
        srand(time(NULL));
        static bool has_explosed = true;
        if (actualPos.X != irr::core::vector3df(90, 0, 0).X) {
                bestMove = irr::core::vector3df(10, 0, 0);
                player.getMesh()->setRotation(irr::core::vector3df(0, -90, 0));

            moveIa(player,actualPos,bestMove);
            has_explosed = true;
             if (nb == 2)
                player.plantBomb();
            return;
        }
        if (!haveCollision(player, 0, 10) && has_explosed) {
                bestMove = irr::core::vector3df(0, 0, 10);
                player.getMesh()->setRotation(irr::core::vector3df(0, 180, 0));
                moveIa(player,actualPos,bestMove);
        }
        else if(!haveCollision(player, -10, 0)) {
                bestMove = irr::core::vector3df(-10, 0, 0);
                player.getMesh()->setRotation(irr::core::vector3df(0, 90, 0));
                moveIa(player,actualPos,bestMove);
                nb =  2;
        }
         else {
            if (has_explosed) {
                player.plantBomb();
                has_explosed = false;
            }
            if (!haveCollision(player, -10, -z) || !haveCollision(player, 0, -z)) {
                bestMove = irr::core::vector3df(0, 0, -z);
                player.getMesh()->setRotation(irr::core::vector3df(0, 0, 0));
                z += 10;
            }
            moveIa(player, actualPos, bestMove);
        }
    }

    void Game::updatePlayerPos()
    {
        bool incrementX = false;
        bool isNegative = false;
        for (auto player : _players) {
            if (player.second.getUpdateMove()) {
                incrementX = player.second.getOffsetX() != 0;
                isNegative = incrementX ? (player.second.getOffsetX() < 0 ? true : false) : (player.second.getOffsetZ() < 0 ? true : false);
                if (_clockPlayer.getElapsedTimeInMillisecond() > 5) {
                    player.second.getMesh()->setPosition({
                        player.second.getMesh()->getPosition().X + (incrementX ? (isNegative ? -2 : 2) : 0),
                        player.second.getMesh()->getPosition().Y,
                        player.second.getMesh()->getPosition().Z + (incrementX ? 0 : (isNegative ? -2 : 2))});
                    _clockPlayer.restart();
                }
                if (player.second.getMesh()->getPosition().X == player.second.getLastPositionX() &&
                    player.second.getMesh()->getPosition().Z == player.second.getLastPositionZ()) {
                        player.second.setUpdateMove(false, 0, 0);
                        break;
                }
            }
        }
    }

    void Game::checkWhoIsAlive()
    {
        if (!_selectMenuConfig->haveTwoPlayer) {
            if (!_players["PLAYERONE"].getIsAlive()) {
                quit();
                *_state = gameState::GAMEOVER;
                return;
            }
            if (!_players["PLAYERTWO"].getIsAlive()) {
                quit();
                *_state = gameState::PLAYER1;
                return;
            }

        } else {
            if (!_players["PLAYERONE"].getIsAlive()) {
                quit();
                *_state = gameState::PLAYER2;
                return;
            }
            if (!_players["PLAYERTWO"].getIsAlive()) {
                quit();
                *_state = gameState::PLAYER1;
                return;
            }
        }
    }

    void Game::run()
    {
        initConfiguration();

        checkWhoIsAlive();

        for (auto &entity : *_entities) {
            if (entity.second->getType() == EntityType::BOMB) {
                if (entity.second->checkTimer(3)) {
                    auto pos = entity.second->getSceneNode()->getPosition();
                    addExplosionByRange(pos, getPlayer(entity.second->getPlayerID()).getRange(), entity.second->getSceneNode(), entity.second->getPlayerID());
                    _removeEntities.push_back(entity.first);
                };
            }
            if (entity.second->getType() == EntityType::EXPLOSION) {
                if (entity.second->checkTimer()) {
                    auto pos = entity.second->getSceneNode()->getPosition();
                    dropEntityByPos(pos);
                    getPlayer(entity.second->getPlayerID()).decreaseBombPlanted();
                    _removeEntities.push_back(entity.first);
                }
            }
            if (entity.second->getType() == EntityType::PBOMB ||
                entity.second->getType() == EntityType::PPASSWALL ||
                entity.second->getType() == EntityType::PSPEED ||
                entity.second->getType() == EntityType::PRANGE) {
                if (entity.second->checkTimer())
                    _removeEntities.push_back(entity.first);
            }
        }
        for (int i = 0; i < _removeEntities.size(); i++) {
            (*_entities)[_removeEntities[i]]->getSceneNode()->remove();
            (*_entities)[_removeEntities[i]].reset();
            (*_entities).erase(_removeEntities[i]);
        }

        updatePlayerPos();

        _removeEntities.clear();
        if (_selectMenuConfig->haveTwoPlayer == false)
        {
            if (!_playerTwo.getIsAlive())
                return;
            static bool isFirst = true;
            float time = clock.getElapsedTimeInSecond();
            static float timertime = 1.6;
            static int oldRange = _playerTwo.getRange();
            if (time > timertime && !isFirst) {
                if (_playerTwo.getRange() != oldRange && timertime > 0.6) {
                    oldRange = _playerTwo.getRange();
                }
                _playerTwo.setPassWall(false);
                findMoveIa(_playerTwo);
                clock.restart();
            }
            isFirst = false;
        }
    }
}




