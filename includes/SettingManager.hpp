#ifndef SETTINGMANAGER_HPP
#define	SETTINGMANAGER_HPP

#include "std.hpp"

	static	std::string                 PATH_SETTING("setting.cfg");
	static	std::vector<std::string>    ALL_SETTING(0);

class  	SettingManager
{
	public:
	
	static void			setPath(std::string path);
	static bool			readFromFile();
	static std::string	getString(std::string beacon);
	static int			getInt(std::string beacon);
	static float		getFloat(std::string beacon);
};

#endif
