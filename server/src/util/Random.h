#pragma once

#include <concepts>

namespace util {

    template<typename T>
    concept FloatingPoint = std::floating_point<T>;

    template<typename T>
    concept Integer = std::integral<T>;

    // Returns a random number between min and max use the Mersenne Twister algorithm
    template<FloatingPoint T>
    T random(T min, T max) {
        static std::mt19937 generator(std::random_device{}());
        std::uniform_real_distribution<T> distribution(min, max);

        return distribution(generator);
    }

    // Cast integer to floating point
    template <Integer T>
    FloatingPoint auto random(T min, T max) {
        return random(static_cast<double>(min), static_cast<double>(max));
    }

}