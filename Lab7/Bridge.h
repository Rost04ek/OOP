#pragma once
#include <string>

class Device {
public:
    virtual ~Device() {}
    virtual std::string Operation() const = 0;
};

class TV : public Device {
public:
    std::string Operation() const override;
};

class Radio : public Device {
public:
    std::string Operation() const override;
};

class Remote {
protected:
    Device* device;
public:
    Remote(Device* d);
    virtual ~Remote() {}
    virtual void ButtonPress() const = 0;
};

class SimpleRemote : public Remote {
public:
    SimpleRemote(Device* d);
    void ButtonPress() const override;
};

class AdvancedRemote : public Remote {
public:
    AdvancedRemote(Device* d);
    void ButtonPress() const override;
};