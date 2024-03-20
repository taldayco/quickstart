#include "../headers/MainGame.h"
#include "../rogue_engine/headers/Timing.h"
#include "../rogue_engine/headers/rogue_engine.h"
#include <SDL2/SDL.h>

MainGame::MainGame()
    : _screenWidth(1024), _screenHeight(768), _gameState(GameState::PLAY),
      _fps(0){};
MainGame::~MainGame(){};

void MainGame::run() {
  initSystems();
  gameLoop();
};

void MainGame::initSystems() {
  // initialize game engine
  rogue_engine::init();
  // create SDL window
  _window.create("quickstart", _screenWidth, _screenHeight, 0);
};

void MainGame::initShaders() {
  // compile color shader
  _textureProgram.compileShaders("shaders/textureShading.vert",
                                 "shaders/textureShading.frag");
  _textureProgram.addAttribute("vertexPosition");
  _textureProgram.addAttribute("vertexColor");
  _textureProgram.addAttribute("vertexUV");
};

void MainGame::gameLoop() {
  // create and initialize FPS limiter
  rogue_engine::FpsLimiter fpsLimiter;
  fpsLimiter.setMaxFPS(60);

  while (_gameState == GameState::PLAY) {
    fpsLimiter.begin();

    processInput();

    drawGame();

    // fpsLimiter.end; returns current fps, so we can set the _fps variable
    // equal to it
    _fps = fpsLimiter.end();
  }
};

void MainGame::processInput() {
  SDL_Event evnt;

  while (SDL_PollEvent(&evnt) == true) {
    // figure out what kind of event it is
    switch (evnt.type) {
    // if the event is SDL_QUIT,
    // return 0 from GameState
    case SDL_QUIT:
      _gameState = GameState::EXIT;
      break;
    };
  }
}

void MainGame::drawGame(){

};
