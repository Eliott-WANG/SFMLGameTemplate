#pragma once
#include <chrono>
#include <random>
#include <functional>
#include <string>
#include <iostream>
#include <chrono>
class Utils
{
public:
    // Generate a random id.
    static std::string generateUniqueID() {
        // Step 1: Obtain the current system time
        auto currentTime = std::chrono::system_clock::now().time_since_epoch().count();

        // Step 2: Generate a random number
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9999);
        auto randomNumber = dis(gen);

        // Step 3: Combine the time and random number
        std::string combinedString = std::to_string(currentTime) + std::to_string(randomNumber);

        // Step 4: Apply a hashing algorithm
        std::hash<std::string> hasher;
        std::size_t hashedValue = hasher(combinedString);

        // Step 5: Format the ID (optional)
        std::string uniqueID = std::to_string(hashedValue);

        // Step 6: Use the ID
        return uniqueID;
    }
};

