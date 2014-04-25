#pragma once

/**
* @file SpriteAnimation.h
* @brief Todo
*/

#include "Common.h"

// Engine includes
#include "Sprite.h"

class SpriteAnimation : public Sprite
{
	public:
		enum Directions
		{
			DOWN	= 0,
			LEFT	= 1,
			RIGHT	= 2,
			UP		= 3,

			// direction counter
			DIR_NUM
		};

		SpriteAnimation(const std::string& path, int x, int y);
		virtual ~SpriteAnimation();

		void Start();
		void Update(unsigned int t);
		void Draw();
		void Stop();

		// ANIMATION ACCESSORS
		void AddAnimationFrame(Directions dir, const SDL_Rect& rect);
		void PopAnimationFrame(Directions dir) {
			frames[dir].pop_back();
		}

		// DIRECTION ACCESSORS
		void SetCurrentDirection(Directions dir) { this->currentDirection = dir; }
		Directions GetCurrentDirection() const {
			return currentDirection;
		}

		// FRAME DELAY ACCESSORS
		void SetFrameDelay(unsigned int delay) { this->delay = delay; }
		unsigned int GetFrameDelay() const {
			return delay;
		}

		// FRAME NUMBER ACCESSORS
		void SetNumberOfFrame(unsigned int num) { this->frame = num; }
		unsigned int GetNumberOfFrame() const {
			return frame;
		}

	protected:
		std::vector<SDL_Rect> frames[DIR_NUM];
		Directions currentDirection;
		unsigned int delay;
		unsigned int frame;
		bool isLooping;
};