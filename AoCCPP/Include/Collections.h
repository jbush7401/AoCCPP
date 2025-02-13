#pragma once
#include <stdexcept>
#include <iostream>
#include <vector>

template<typename T>
class GenArray2d {
private:
	T* data;
	size_t rows, cols;

public:
	GenArray2d(size_t r = 0, size_t c = 0) :
		rows(r),
		cols(c),
		data(new T[r * c]()) {
	}
	
	~GenArray2d() {
		delete[] data;
	}
	// Copy Constructor
	GenArray2d(const GenArray2d& other) :
		rows(other.rows),
		cols(other.cols),
		data(new T[rows * cols]) {
		for (size_t i = 0; i < rows * cols; i++) {
			data[i] = other.data[i];
		}
	}

	// Copy operator
	GenArray2d& operator=(const GenArray2d& other){
		// Check for self assignment
		if (this == &other)
			return *this;

		// Clean up resources
		delete[] data;

		// copy dimensions
		rows = other.rows;
		cols = other.cols;
		data = new T[rows * cols];
		for (size_t i = 0; i < rows * cols; i++) {
			data[i] = other.data[i];
            // Ensure the size of 'other.data' is not greater than 'data'
            if (rows * cols < other.rows * other.cols) {
				throw std::out_of_range("Source array is larger than destination array");
            }
            for (size_t i = 0; i < other.rows * other.cols; i++) {
				data[i] = other.data[i];
            }
		}

		return *this;
	}

	// Move constructor
	GenArray2d(GenArray2d&& other) noexcept
		: rows(other.rows),
		cols(other.cols),
		data(other.data)
	{
		// 1. "Steal" the pointer
		//    We already took 'other.data' in the initializer list.

		// 2. Leave 'other' in a safe state
		other.rows = 0;
		other.cols = 0;
		other.data = nullptr;
	}

    void initialize(size_t r, size_t c) {
		delete[] data;
		data = new T[r * c]();
    };

	// Function to convert 2D coordinates to 1D
	// data[row * cols + col] is the same as data[row][col]
	size_t index(size_t x, size_t y) const
	{
		return y * cols + x;
	}

	T* get(size_t x, size_t y) const
	{
		return &data[index(x, y)];
	}

	T* get(size_t index) const {
		return &data[index];
	}

	size_t getRows() const {
		return rows;
	}

	size_t getCols() const {
		return cols;
	}
	void set(size_t x, size_t y, T c) {
		data[index(x, y)] = c;
	}

	void set(std::vector<T> v)
	{
		for (int i = 0; i < v.size(); i++)
			data[i] = v[i];
	}

	size_t getSize() {
		return rows * cols;
	}

	void traverse() const
	{
		for (size_t y = 0; y < rows; y++) {
			for (size_t x = 0; x < cols; x++) {
				std::cout << get(y, x) << " ";
			}
			std::cout << std::endl;
		}
	}
};

		