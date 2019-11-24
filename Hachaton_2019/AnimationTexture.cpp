#include "AnimationTexture.h"

AnimationTexture::AnimationTexture()
{
	texture = nullptr;
}

//maxlent - сколько анимаций(дорожек) в картинке хранится вообще, int w,h - эквивалент для среднего размера
AnimationTexture::AnimationTexture(SDL_Renderer* render, SDL_Texture* picter, int MaxFrames, int MaxLent, int w, int h)
{
	texture = picter;
	CurrentFrame = 0;
	FrameInc = 1;
	this->MaxFrames = MaxFrames;
	FrameRate = 100; //Milliseconds
	OldTime = 0;
	OneRaz = false;
	Oscillate = false;
	int w2, h2;
	SDL_QueryTexture(texture, NULL, NULL, &w2, &h2);
	stop = false;
	StepPixel = InPicter.w = InGame.w = w2 / MaxFrames;
	StepLent = InPicter.h = InGame.h = h2 / MaxLent;
	InPicter.y = 0;
	this->MaxLent = MaxLent;
	KoefW = (double)1 -((double)30 / (double)w);
	KoefH = (double)1 - ((double)30 / (double)h);
	InGame.w = w2;
	InGame.h = h2;
}

AnimationTexture::~AnimationTexture()
{

}

int AnimationTexture::GetCurrentFrame()
{
	return CurrentFrame;
}

int AnimationTexture::GetStepPixel()
{
	return StepPixel;
}

//ставит fps
void AnimationTexture::SetFrameRate(int Rate)
{
	FrameRate = Rate;
}

//какой фрейм сейчас будет
void AnimationTexture::SetCurrentFrame(int Frame)
{
	CurrentFrame = Frame;
}

//выбрать, какая дорожка сейчас будет анимироваться
void AnimationTexture::SetAnimationDoroshka(int Lent)
{
	if (Lent <= MaxLent && Lent > 0)
		InPicter.y = (Lent - 1) * this->StepLent;
}

//void AnimationTexture::Stop()
//{
//	CurrentFrame = 0;
//	stop = true;
//}
//
//void AnimationTexture::Start()
//{
//	stop = false;
//}

//выбирает какой сечас будет идти фрейм
void AnimationTexture::OnAnimation()
{
	if (!stop)
	{
		if (OldTime + FrameRate > SDL_GetTicks()) {
			return;
		}

		OldTime = SDL_GetTicks();

		CurrentFrame += FrameInc;

		if (Oscillate) {
			if (FrameInc > 0) {
				if (CurrentFrame > MaxFrames) {
					FrameInc = -FrameInc;
				}
			}
			else {
				if (CurrentFrame <= 0) {
					FrameInc = -FrameInc;
				}
			}
		}
		else {
			if (CurrentFrame >= MaxFrames) {
				if (OneRaz) return;
				CurrentFrame = 0;
			}
		}
	}
}

void AnimationTexture::DrawAnimationTexture(SDL_Renderer* ren)
{
	InPicter.x = GetStepPixel() * GetCurrentFrame(); //какой объект будет
	SDL_RenderCopy(ren, texture, &InPicter, &WindowSize::Mashtab(&InGame));
}

double AnimationTexture::GetKoefW()
{
	return KoefW;
}

double AnimationTexture::GetKoefh()
{
	return KoefH;
}
