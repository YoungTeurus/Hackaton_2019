#pragma once

#include <SDL.h>
#include "Texture.h"
#include "CSurface.h"

class AnimationTexture
{
public:
	AnimationTexture();
	AnimationTexture(SDL_Renderer* render, SDL_Texture* picter, int MaxFrames, int MaxLent);
	~AnimationTexture();

	int GetCurrentFrame();
	int GetStepPixel();
	void SetFrameRate(int Rate);
	void SetCurrentFrame(int Frame);
	void SetAnimationDoroshka(int Lent); // от 1 до MaxLent

	void OnAnimation();
	void DrawAnimationTexture(SDL_Renderer* ren);



	int    MaxFrames;
	bool   Oscillate;


	SDL_Rect InGame;
private:
	int StepPixel;
	int CurrentFrame;
	SDL_Texture* texture;

	SDL_Rect InPicter;
	int FrameRate; //Milliseconds
	long OldTime;
	int FrameInc;
	int MaxLent;
	int StepLent;
};

