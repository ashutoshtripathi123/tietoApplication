#include"libraryArch.h"

/*The result stored during the parsing of the files from directory, treats file name
as key. Although this is a criteria, however the result is expected to be in the format,
where common files are clubbed on the basis of projects, hence we need to create one more map
called as finalResult, where the key will be the project name, and second element shall 
be the file name*/
void Result::prepareResult()
{
	for (ir1 = ds.begin();ir1 != ds.end(); ir1++)
	{
		if (strstr(ir1->second.c_str(), ","))
		{
			ir2 = finalResult.find(ir1->second);
			if (ir2 == finalResult.end())
			{
				finalResult.insert(pair<string, string>(ir1->second, ir1->first));
			}
			else
			{
				string temp = "," + ir1->first;
				ir2->second.append(temp);
			}
		}
	}

	for (ir2 = finalResult.begin();ir2 != finalResult.end();ir2++)
	{
		istringstream iss(ir2->first);
		string token;
		while (getline(iss, token, ','))
		{
			cout << "/" << token << endl;
			fileHandler << "/" << token << endl;
		}

		istringstream iss1(ir2->second);
		while (getline(iss1, token, ','))
		{
			cout << '\t' << token << endl;
			fileHandler << '\t' << token << endl;
		}
	}
}

/*addToMap API treats the file name as key, and adds to the map only if the 
file does not exist in the map. If the file exists in the map, then append the project name*/
void Result:: addToMap(char *filePath, const char *inputString)
{
	char *ptr = filePath;
	string project;
	string fileLocation;
	ptr = ptr + strlen(inputString) + 1; //it just has the project name and the file name
	char *slash = strchr(ptr, '\\');
	fileLocation = slash;
	project = ptr;
	size_t i = project.find(fileLocation);
	if (i != string::npos)
	{
		project.erase(i, fileLocation.length());
	}

	fileLocation = slash + 1;
	ir1 = ds.find(fileLocation);
	if (ir1 == ds.end())
	{
		ds.insert(pair<string, string>(fileLocation, project));
	}
	else
	{
		//Append project name to ir->second, and continue
		string temp = "," + project;
		ir1->second.append(temp);
	}
}

