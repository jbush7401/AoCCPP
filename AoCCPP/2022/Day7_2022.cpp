#include "Day7_2022.h"
#include "Util.h"
#include <iostream>

void Day7_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day7.txt");
	currentFolder = &rootFolder;
	AllFolders.push_back(&rootFolder);

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
	
	std::cout << "Part 1: " << CheckSizes(&rootFolder) << std::endl;
}

void Day7_2022::PartTwo()
{
	std::cout << "Part 2: " << CheckSizesPart2(&rootFolder, 30000000 - (70000000 - rootFolder.totalSize)) << std::endl;
}

void Day7_2022::ProcessCommand(int& i)
{
	if (vec[i][2] == 'l') {
		i = i + 1;
		while (i < vec.size() && vec[i][0] != '$') {
			// If a directory, add it to the folders with it's name
			if (vec[i][0] == 'd'){
				std::string d = vec[i].substr(4);
				currentFolder->folders.push_back(Folder(d, currentFolder));
			}
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
			for (size_t j = 0; j < currentFolder->folders.size(); j++) {

				if (currentFolder->folders[j].name == vec[i].substr(vec[i].find_first_of('d') + 2)){
					currentFolder = &currentFolder->folders[j];
					break;
				}
			}
		}
		i++;
	}
}

void Day7_2022::Folder::SetSize(long s)
{
	totalSize += s;
	if (previousFolder != nullptr)
		previousFolder->SetSize(s);
}

long Day7_2022::CheckSizes(Folder * f) {
	std::vector<Folder*> foldersToCheck;
	long total = 0;
	foldersToCheck.push_back(f);
	while (foldersToCheck.size() > 0)
	{
		Folder* temp = foldersToCheck[0];
		if (temp->totalSize <= 100000){
			total += temp->totalSize;
		}
		for (int i = 0; i < temp->folders.size(); i++) {
			foldersToCheck.push_back(&temp->folders[i]);
		}
		foldersToCheck.erase(foldersToCheck.begin());
	}
	return total;
}

long Day7_2022::CheckSizesPart2(Folder* f, long neededSpace)
{
	std::vector<Folder*> foldersToCheck;
	long delCandidate = LONG_MAX;
	foldersToCheck.push_back(f);
	while (foldersToCheck.size() > 0)
	{
		Folder* temp = foldersToCheck[0];
		if (temp->totalSize >= neededSpace && temp->totalSize < delCandidate) {
			delCandidate = temp->totalSize;
		}
		for (int i = 0; i < temp->folders.size(); i++) {
			foldersToCheck.push_back(&temp->folders[i]);
		}
		foldersToCheck.erase(foldersToCheck.begin());
	}
	return delCandidate;
}

