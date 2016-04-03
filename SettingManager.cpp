#include "SettingManager.hpp"

	void	SettingManager::setPath(std::string path)
	{
		PATH_SETTING = path;
	}

	bool	SettingManager::readFromFile()
	{
		std::string					readBuffer;
		std::ifstream				flRead;

		while (ALL_SETTING.size() >= 1)
			ALL_SETTING.pop_back();

		flRead.open(PATH_SETTING);
		if (!flRead)
			return (false);
		while (std::getline(flRead, readBuffer))
		{
			if (readBuffer[0] != '#')
				ALL_SETTING.push_back(readBuffer);
		}
		flRead.close();
		return(true);					
	}

	std::string		SettingManager::getString(std::string beacon)
	{
		unsigned int	b_size = beacon.length();
		unsigned int	s_size = ALL_SETTING.size();

		for (unsigned int i = 0; i < s_size; i++)
		{
			if (beacon == ALL_SETTING[i].substr(0, b_size))
				return(ALL_SETTING[i].substr(b_size));
			//	return (stoi(ALL_SETTING[i].substr(b_size)));
		}
		return ("");
	}
	
	int				SettingManager::getInt(std::string beacon)
	{
		unsigned int	b_size = beacon.length();
		unsigned int	s_size = ALL_SETTING.size();

		for (unsigned int i = 0; i < s_size; i++)
		{
			if (beacon == ALL_SETTING[i].substr(0, b_size))
				return (stoi(ALL_SETTING[i].substr(b_size)));
		}
		return (0);
	}
	
	float			SettingManager::getFloat(std::string beacon)
	{
		unsigned int	b_size = beacon.length();
		unsigned int	s_size = ALL_SETTING.size();

		for (unsigned int i = 0; i < s_size; i++)
		{
			if (beacon == ALL_SETTING[i].substr(0, b_size))
				return (stof(ALL_SETTING[i].substr(b_size)));
		}
		return (0);
	}
