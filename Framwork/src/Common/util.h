#pragma once

#include <string>

class Utils
{
public:
	static inline float getFileSize(const std::string& filename) {
		FILE *p_file = NULL;
		p_file = fopen(filename.c_str(), "rb");
		fseek(p_file, 0, SEEK_END);
		int size = ftell(p_file);
		fclose(p_file);

		return size / 1024.0f / 1024.0f;
	};

	static inline std::string remove_extension(const std::string& filename) {
		size_t lastdot = filename.find_last_of(".");
		if (lastdot == std::string::npos) return filename;
		return filename.substr(0, lastdot);
	}
	static void gen_random(char* str, const int len) 
	{
		static const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

		for (int i = 0; i < len; ++i)
			str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

		str[len] = 0;
	}

	static inline float mapValues(float rangeA[], float rangeB[], float value, unsigned int size = 2)
	{
		return (value - rangeA[0]) * (rangeB[1] - rangeB[0]) / (rangeA[1] - rangeA[0]) + rangeB[0];
	}

	static char* cpToUTF8(int cp, char* str)
	{
		int n = 0;
		if (cp < 0x80) n = 1;
		else if (cp < 0x800) n = 2;
		else if (cp < 0x10000) n = 3;
		else if (cp < 0x200000) n = 4;
		else if (cp < 0x4000000) n = 5;
		else if (cp <= 0x7fffffff) n = 6;
		str[n] = '\0';
		switch (n) {
		case 6: str[5] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x4000000;
		case 5: str[4] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x200000;
		case 4: str[3] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x10000;
		case 3: str[2] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0x800;
		case 2: str[1] = 0x80 | (cp & 0x3f); cp = cp >> 6; cp |= 0xc0;
		case 1: str[0] = cp;
		}
		return str;
	}
};
