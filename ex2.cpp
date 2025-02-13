#include "ex2.hpp"

bool FileHandler::open(const std::string& filename) {
    file.open(filename, std::ios::in | std::ios::out);
    return file.is_open();
}

void FileHandler::close() {
    if (file.is_open()) file.close();
}

bool FileHandler::isOpen() const {
    return file.is_open();
}

void FileHandler::read() {
    if (!isOpen()) return;
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void FileHandler::write(const std::string& data) {
    if (!isOpen()) return;
    file << data;
}

bool NetworkHandler::open(const std::string& url) {
    endpoint = url;
    connected = true;
    std::cout << "Connected to: " << url << std::endl;
    return connected;
}

void NetworkHandler::close() {
    connected = false;
    endpoint.clear();
}

bool NetworkHandler::isOpen() const {
    return connected;
}

void NetworkHandler::read() {
    if (!connected) return;
    std::cout << "Network Reading: " << endpoint << std::endl;
}

void NetworkHandler::write(const std::string& data) {
    if (!connected) return;
    std::cout << "Network Sending: " << data << std::endl;
}

// MemoryHandler implementation
bool MemoryHandler::open(const std::string& segment) {
    isActive = true;
    std::cout << "Init Memory: " << segment << std::endl;
    return true;
}

void MemoryHandler::close() {
    isActive = false;
    memory.clear();
}

bool MemoryHandler::isOpen() const {
    return isActive;
}

void MemoryHandler::read() {
    if (!isActive) return;
    for (const auto& data : memory) {
        std::cout << data << std::endl;
    }
}

void MemoryHandler::write(const std::string& data) {
    if (!isActive) return;
    memory.push_back(data);
}
