#include"libraryArch.h"

/* A recursively called API, which shall parse the directory tree, right upto the base
where no more directories exist after it, and shall search for the required file extensions.
If we find any files which match the desired extensions, we shall pass those names to the 
addToMap API of class Result
*/
void Windows :: listDir(char * dirn)
{
	char dirnPath[1024];
	sprintf(dirnPath, "%s\\*.*", dirn);

	WIN32_FIND_DATA f;
	HANDLE h = FindFirstFile(dirnPath, &f);

	if (h == INVALID_HANDLE_VALUE)
	{
		cout << "Returning due to invalid file handle" << endl;
		return;
	}

	do
	{
		const char * name = f.cFileName;

		if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) { continue; }

		char filePath[1024];
		sprintf(filePath, "%s%s%s", dirn, "\\", name);

		//if my filePath is having extension of *.c *.h or *.cpp then add it to the map
		if (strstr(filePath, ".h") ||
			strstr(filePath, ".c") ||
			strstr(filePath, ".cpp") ||
			strstr(filePath, ".rc"))
		{
			//add the file and the project name to the map
			rs.addToMap(filePath, inputString);
		}

		//If the discovered file happens to be a Directory ? then enter the same
		if (f.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			listDir(filePath);
		}

	} while (FindNextFile(h, &f));

	FindClose(h);
}

void Windows ::output()
{
	rs.prepareResult();
}
