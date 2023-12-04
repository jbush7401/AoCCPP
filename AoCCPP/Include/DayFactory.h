#pragma once
#include <map>
#include <string>
#include <functional>
#include <memory>
#include "IDay.h"

using DayFactoryFunc = std::function<std::unique_ptr<IDay>()>;

class DayFactory {
    std::map<std::string, DayFactoryFunc> factoryMap;

public:
    void RegisterDay(const std::string& name, DayFactoryFunc func) {
        factoryMap[name] = func;
    }

    std::unique_ptr<IDay> CreateInstance(const std::string& year, const std::string& day) const {
        auto key = "Y" + year + "_D" + day;
        auto it = factoryMap.find(key);
        return it != factoryMap.end() ? it->second() : nullptr;
    }
};

