//
// Created by admin on 2022/7/27.
//
#pragma once
#include <string>
#include <thread>
#include <sstream>
#include <exception>
#include <random>
#include <list>

/*
enum class ExceptionCode {

};

class Exception : std::exception {
private:
    ExceptionCode mExCode;
public:
    explicit Exception(ExceptionCode const& exCode, std::string const& msg) noexcept : std::exception(msg.c_str()),
    mExCode(exCode)  {

    }

    ExceptionCode getCode() const noexcept{
        return mExCode;
    }


};

*/

class ExceptionImpl : std::exception {
public:
    std::string msg_;

    const char* what() const throw() override {
        return msg_.c_str();
    }
};
