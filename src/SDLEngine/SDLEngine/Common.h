#pragma once

/**
* @file Common.h
* @brief Todo
*/

#ifndef DEFAULT_TIMESTEP_MS
#define DEFAULT_TIMESTEP_MS 10
#endif

#ifndef DEFAULT_WIN_TITLE
#define DEFAULT_WIN_TITLE "Engine - "
#endif

#ifndef DEFAULT_WIN_W
#define DEFAULT_WIN_W 800
#endif

#ifndef DEFAULT_WIN_H
#define DEFAULT_WIN_H 600
#endif

// STD includes
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <map>

// UTL includes
#include "StringConcat.h"
#include "Timer.h"
#include "Pool.h"

// SDL includes
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "SDL.h"

// Box2D includes
#include "Box2D/Box2D.h"

// GLM include
#include "glm.hpp"

//Audio Engine
#include "Audio.h"