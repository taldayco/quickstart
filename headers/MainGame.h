#pragma once
#include "../rogue_engine/headers/Camera2D.h"
#include "../rogue_engine/headers/GLSLProgram.h"
#include "../rogue_engine/headers/InputManager.h"
#include "../rogue_engine/headers/Window.h"

enum class GameState { PLAY, EXIT };
class MainGame {
public:
  MainGame();
  ~MainGame();
  void run();

private:
  void initSystems();
  void initShaders();
  void gameLoop();
  void processInput();
  void drawGame();

  // member variables
  rogue_engine::Window _window;
  rogue_engine::GLSLProgram _textureProgram;
  rogue_engine::InputManager _inputManager;
  rogue_engine::Camera2D _camera2D;

  //_window variables
  int _screenWidth, _screenHeight;

  // store fps for FPS limiter functions
  int _fps;

  // store gameState
  GameState _gameState;
};
