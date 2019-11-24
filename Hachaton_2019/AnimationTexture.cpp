#include "AnimationTexture.h"

AnimationTexture::AnimationTexture()
{
	texture = nullptr;
}

//maxlent - ������� ��������(�������) � �������� �������� ������
AnimationTexture::AnimationTexture(SDL_Renderer* render, SDL_Texture* picter, int MaxFrames, int MaxLent, int w, int h)
{
	texture = picter;
	CurrentFrame = 0;
	FrameInc = 1;
	this->MaxFrames = MaxFrames;
	FrameRate = 100; //Milliseconds
	OldTime = 0;
	Oscillate = false;
	int w2, h2;
	SDL_QueryTexture(texture, NULL, NULL, &w2, &h2);

	StepPixel = InPicter.w = InGame.w = w2 / MaxFrames;
	StepLent = InPicter.h = InGame.h = h2 / MaxLent;
	InPicter.y = 0;
	this->MaxLent = MaxLent;
	KoefW = (double)1 - ((double)30 / (double)w);
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

//������ fps
void AnimationTexture::SetFrameRate(int Rate)
{
	FrameRate = Rate;
}

//����� ����� ������ �����
void AnimationTexture::SetCurrentFrame(int Frame)
{
	CurrentFrame = Frame;
}

//�������, ����� ������� ������ ����� �������������
void AnimationTexture::SetAnimationDoroshka(int Lent)
{
	if (Lent <= MaxLent && Lent > 0)
		InPicter.y = (Lent - 1) * this->StepLent;
}

//�������� ����� ����� ����� ���� �����
void AnimationTexture::OnAnimation()
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
			CurrentFrame = 0;
		}
	}
}

void AnimationTexture::DrawAnimationTexture(SDL_Renderer* ren)
{
	InPicter.x = GetStepPixel() * GetCurrentFrame(); //����� ������ �����
	SDL_RenderCopy(ren, texture, &InPicter, &WindowSize::Mashtab(&InGame));
}

double AnimationTexture::GetKoefH()
{
	return KoefH;
}

double AnimationTexture::GetKoefW()
{
	return KoefW;
}
