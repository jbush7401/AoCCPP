#pragma once
#include <map>
#include <string>
#include <memory>
#include <functional>
#include "IDay.h"
#include <format>

using DayFactoryFunc = std::function<std::unique_ptr<IDay>()>;

class DayFactory {
	using FactoryMap = std::map<std::string, std::function<std::unique_ptr<IDay>()>>;
	FactoryMap factoryMap;

public:
	template <typename T>
    void RegisterDay(int year, int day) {
		auto key = std::format("Y{}_D{}", year, day);
        factoryMap[key] = []() {return std::make_unique<T>(); };
    }

    std::unique_ptr<IDay> CreateInstance(int year, int day) const {
		auto key = std::format("Y{}_D{}", year, day);
        auto it = factoryMap.find(key);
        return it != factoryMap.end() ? it->second() : nullptr;
    }
};

