#pragma once
#include "IDay.h"
#include <string>
#include <vector>

class Day7_2022 : public IDay {
public:
    void PartOne();
    void PartTwo();

private:
    std::vector<std::string> vec;
    struct File {
        File(long s, std::string n) : size(s), name(n) {};
        long size;
        std::string name;
    };

    struct Folder {
        Folder(std::string n, Folder* prev = nullptr) : name(n), previousFolder(prev) {};
        ~Folder(){}

        std::string name = "";
        long totalSize = 0;
        std::vector<File> files;
        std::vector<Folder> folders;
        Folder* previousFolder;

        void SetSize(long s);
    };

    std::vector<Folder*> AllFolders;
    Folder* currentFolder = nullptr;
    Folder rootFolder = Folder("/");
    void ProcessCommand(int& i);
    long CheckSizes(Folder * f);
    long CheckSizesPart2(Folder* f, long neededSpace);
};
