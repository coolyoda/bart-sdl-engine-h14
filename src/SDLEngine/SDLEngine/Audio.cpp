#include "Audio.h"

Audio* Audio::instance = NULL;

Audio::Audio():
musicVolume(100)
, sfxVolume(100)
, lastFocusChannel(-1)
{
	SDL_Init(SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, AUDIO_S16, 2, 4096))
	{
		Mix_AllocateChannels(16);
	}

}

Audio::~Audio()
{
	Mix_CloseAudio();

	Mix_HaltMusic();

	{
		//clean sound fx
		std::map<std::string, SoundFX*>::iterator iter = loadedSFX.begin();
		while (iter != loadedSFX.end())
		{
			Mix_FreeChunk (iter->second);
			iter++;
		}
	}

	{
		//clean music
		std::map<std::string, Music*>::iterator iter = loadedMusic.begin();
		while (iter != loadedMusic.end())
		{
			Mix_FreeMusic (iter->second);
			iter++;
		}
	}
}

SoundFX* Audio::GetSound(const std::string& path)
{
	if (path.find(".wav") == std::string::npos) 
	{
		std::cout << "Could not load " << path << ", the file must be of type WAV" << std::endl;
		return NULL;
	}

	if (loadedSFX[path] == NULL) 
	{
		loadedSFX[path] = Mix_LoadWAV(path.c_str());
	}

	if (loadedSFX[path] == NULL)
	{
		std::cout << "Could not load " << path << ", the file does not exist" << std::endl;
	}

	return loadedSFX[path];
};

Music* Audio::GetMusic(const std::string& path)
{
	if (loadedMusic[path] == NULL)
	{
		loadedMusic[path] = Mix_LoadMUS(path.c_str());
	}

	if (loadedMusic[path] == NULL)
	{
		std::cout << "Could not load " << path << ", the file does not exist" << std::endl;
	}

	return loadedMusic[path];
};

void Audio::PlaySound(const std::string& sfx)
{
	PlaySound(sfx, 100);
}

void Audio::PlaySound(const std::string& sfx, int volume)
{
	PlaySound(sfx, volume, 0.5, 0);
}

void Audio::PlaySound(const std::string& sfx, int volume, const float& screenPanning)
{
	PlaySound(sfx, volume, screenPanning, 0);
}

void Audio::PlaySound(const std::string& sfx, int volume, const float& screenPanning, const int& loopTimes)
{
	if (volume < 0)
	{
		volume = 0;
	}
	else if (volume > 255)
	{
		volume = 255;
	}

	int angle = ((screenPanning)* 180) - 90;
	if (angle < 0)
	{
		angle = 360 + angle;
	}

	Mix_SetPosition(Mix_PlayChannel(-1, GetSound(sfx), loopTimes), angle, (255 - ((float)volume / 100) * 255) * ((float)sfxVolume / 100));
}

void Audio::PlaySoundFocus(const std::string& sfx)
{
	lastFocusChannel = Mix_PlayChannel(-1, GetSound(sfx), 0);
	Mix_SetPosition(lastFocusChannel, 0, 255 - (255 * ((float)sfxVolume / 100)));

	Mix_VolumeMusic(musicVolume * 0.3);

	std::map<std::string, SoundFX*>::iterator iter = loadedSFX.begin();
	while (iter != loadedSFX.end())
	{
		if (iter->second != GetSound(sfx))
		{
			Mix_VolumeChunk(iter->second, sfxVolume * 0.3);
		}
		iter++;
	}

	//Mix_ChannelFinished((this->ResetFocus)(lastFocusChannel));
	Mix_ChannelFinished(Audio::CatchChannelDone);
}

void Audio::CatchChannelDone(int channel)
{
	GetInstance()->ResetFocus(channel);
}

void Audio::ResetFocus(const int& channel)
{
	if (channel == lastFocusChannel)
	{
		Mix_VolumeMusic(musicVolume);

		std::map<std::string, SoundFX*>::iterator iter = loadedSFX.begin();
		while (iter != loadedSFX.end())
		{
			Mix_VolumeChunk(iter->second, sfxVolume);
			iter++;
		}
	}
}

void Audio::PlayMusic(const std::string& song)
{
	PlayMusic(song, 100);
}

void Audio::PlayMusic(const std::string& song, const int& volume)
{
	PlayMusic(song, volume, 0);
}

void Audio::PlayMusic(const std::string& song, const int& volume, const int& delayInMs)
{
	Mix_FadeInMusic(GetMusic(song), 0, delayInMs);
	Mix_VolumeMusic((((float)volume / 100) * 128) * ((float) musicVolume / 100));
}

void Audio::PlayMusicLooped(const std::string& song)
{
	Mix_PlayMusic(GetMusic(song), -1);
}

void Audio::ChangeGlobalVolume(const int& volume)
{
	ChangeMusicVolume(volume);
	ChangeSFXVolume(volume);
}

void Audio::ChangeMusicVolume(const int& volume)
{
	musicVolume = ((float)volume / 100) * 128;
	Mix_VolumeMusic(musicVolume);
}

void Audio::ChangeSFXVolume(const int& volume)
{
	sfxVolume = ((float)volume / 100) * 128;

	std::map<std::string, SoundFX*>::iterator iter = loadedSFX.begin();
	while (iter != loadedSFX.end())
	{
		Mix_VolumeChunk(iter->second, sfxVolume);
		iter++;
	}
}