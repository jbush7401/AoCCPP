#include "Day7.h"
#include "Util.h"
#include <iostream>

void Day7_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day7.txt");
	Folder rootFolder = Folder("/");
	currentFolder = &rootFolder;
	int i = 1;
	//Iterate through commands
	while(i < vec.size()) {
		//Process Command
		if (vec[i][0] == '$') {
			ProcessCommand(i);
			continue;
		}
		i++;
	}
}

void Day7_2022::PartTwo()
{

}

void Day7_2022::ProcessCommand(int& i)
{
	if (vec[i][2] == 'l') {
		i = i + 1;
		while (vec[i][0] != '$') {
			// If a directory, add it to the folders with it's name
			if (vec[i][0] == 'd')
				currentFolder->folders.push_back(Folder(vec[i].substr(4), currentFolder));
			else{
				currentFolder->files.push_back(File(stoi(vec[i].substr(0, vec[i].find_first_of(' '))), vec[i].substr(vec[i].find_first_of(' ') + 1)));
			}
			i++;
		}
		//Set total size of direcctory
		long tSize = 0;
		for (File f : currentFolder->files) {
			tSize += f.size;
		}
		currentFolder->SetSize(tSize);
	}
	else {
		if (vec[i] == "$ cd ..") {
			currentFolder = currentFolder->previousFolder;
		}
		else {
			for (Folder f : currentFolder->folders) {

				if (f.name == vec[i].substr(vec[i].find_first_of('d') + 2))
					currentFolder = &f;
			}
		}
		i++;
	}
}

void Day7_2022::Folder::SetSize(int s)
{
	totalSize += s;
	if (previousFolder != nullptr)
		previousFolder->totalSize += s;
}
