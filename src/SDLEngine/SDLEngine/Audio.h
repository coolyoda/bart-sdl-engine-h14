#pragma once

#include "Common.h"

typedef Mix_Chunk SoundFX;
typedef Mix_Music Music;

class Audio
{
public:
#pragma region SINGLETON
	static Audio* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Audio();
		}

		return instance;
	}

	static void Kill()
	{
		if (instance)
		{
			delete instance;
			instance = NULL;
		}
	}

private:
	Audio();
	Audio(const Audio& other);
	~Audio();

	Audio& operator= (const Audio& other);
	static Audio* instance;
#pragma endregion

public:
	static void CatchChannelDone(int channel);

	void PlaySound(const std::string& sfx);
	void PlaySound(const std::string& sfx, int volume);
	void PlaySound(const std::string& sfx, int volume, const float& screenPanning);
	void PlaySound(const std::string& sfx, int volume, const float& screenPanning, const int& loopTimes);

	void PlaySoundFocus(const std::string& sfx);

	void PlayMusic(const std::string& song);
	void PlayMusic(const std::string& song, const int& volume);
	void PlayMusic(const std::string& song, const int& volume, const int& fadeInMs);
	void PlayMusicLooped(const std::string& song);

	void ChangeGlobalVolume(const int& volume);
	void ChangeMusicVolume(const int& volume);
	void ChangeSFXVolume(const int& volume);

private:
	SoundFX* GetSound(const std::string& path);
	Music* GetMusic(const std::string& path);

	void ResetFocus(const int& channel);

	std::map<std::string, SoundFX*> loadedSFX;
	std::map<std::string, Music*> loadedMusic;

	int musicVolume;
	int sfxVolume;
	int lastFocusChannel;
};