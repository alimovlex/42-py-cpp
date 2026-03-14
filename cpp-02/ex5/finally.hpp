//
// Created by robot on 3/13/26.
//
#pragma once
#include <functional>

class finally
{
public:
    finally(std::function<void()> f) : func_(std::move(f)) { }
    ~finally() { func_(); }
private:
    std::function<void()> func_;
};

