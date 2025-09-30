#pragma once

class IDay {
public:
	virtual void PartOne() = 0;
	virtual void PartTwo() = 0;
	virtual ~IDay() = default; 
};