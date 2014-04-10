#pragma once

/**
* @file Common.h
* @brief Todo
*/

#ifndef TITLE_PREFIX
#define TITLE_PREFIX "Engine - "
#endif

#ifndef DEFAULT_TIMESTEP
#define DEFAULT_TIMESTEP 10
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
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"