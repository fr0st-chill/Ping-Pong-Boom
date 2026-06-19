#include <SDL2/SDL.h>

// Main Window Render
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

// Ball Render
const int BALL_WIDTH = 15;
const int BALL_HEIGHT = 15;

class Vec2
{
    public:
        Vec2()
            :  x(0.0f), y(0.0f)
        {}

        Vec2(float x, float y)
            : x(x), y(y)
        {}

        Vec2 operator+(Vec2 const& rhs)
        {
            return Vec2(x + rhs.x, y + rhs.y);
        }
        Vec2& operator+=(Vec2 const& rhs)
        {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }

        Vec2 operator*(float rhs)
        {
            return Vec2(x * rhs, y * rhs);
        }
        // Ensure that x,y become a float type
        float x, y;
};

class Ball
{
public:
	Ball(Vec2 position)
		: position(position)
	{
		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);
		rect.w = BALL_WIDTH;
		rect.h = BALL_HEIGHT;
	}

	void Draw(SDL_Renderer* renderer)
	{
		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);

		SDL_RenderFillRect(renderer, &rect);
	}

	Vec2 position;
	SDL_Rect rect{};
};
