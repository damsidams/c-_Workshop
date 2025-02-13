#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

class ResourceHandler {
public:
    virtual ~ResourceHandler() = default;
    virtual bool open(const std::string& resourcename) = 0;
    virtual void close() = 0;
    virtual bool isOpen() const = 0;
    virtual void read() = 0;
    virtual void write(const std::string& data) = 0;
};

class FileHandler : public ResourceHandler {
private:
    std::fstream file;
public:
    bool open(const std::string& filename) override;
    void close() override;
    bool isOpen() const override;
    void read() override;
    void write(const std::string& data) override;
};

class NetworkHandler : public ResourceHandler {
private:
    bool connected;
    std::string endpoint;
public:
    NetworkHandler() : connected(false) {}
    bool open(const std::string& url) override;
    void close() override;
    bool isOpen() const override;
    void read() override;
    void write(const std::string& data) override;
};

class MemoryHandler : public ResourceHandler {
private:
    std::vector<std::string> memory;
    bool isActive;
public:
    MemoryHandler() : isActive(false) {}
    bool open(const std::string& segment) override;
    void close() override;
    bool isOpen() const override;
    void read() override;
    void write(const std::string& data) override;
};
