#ifndef ARGCONVERT_H
#define ARGCONVERT_H

#include <stdexcept>
#include <string>

namespace hd {
    template<typename TO>
    class ArgConvert {
    public:
        TO operator()(const std::string& from) { return TO(from); }
    };

    template<>
    class ArgConvert<unsigned char> {
    public:
        unsigned char operator()(const std::string& from) {
            return static_cast<unsigned char>(std::stoul(from));
        }
    };

    template<>
    class ArgConvert<char> {
    public:
        char operator()(const std::string& from) {
            return static_cast<char>(std::stoi(from));
        }
    };

    template<>
    class ArgConvert<unsigned short> {
    public:
        unsigned short operator()(const std::string& from) {
            return static_cast<unsigned short>(std::stoul(from));
        }
    };

    template<>
    class ArgConvert<short> {
    public:
        short operator()(const std::string& from) {
            return static_cast<short>(std::stoi(from));
        }
    };

    template<>
    class ArgConvert<unsigned int> {
    public:
        unsigned int operator()(const std::string& from) { return std::stoul(from); }
    };

    template<>
    class ArgConvert<int> {
    public:
        int operator()(const std::string& from) { return std::stoi(from); }
    };

    template<>
    class ArgConvert<unsigned long int> {
    public:
        unsigned long int operator()(const std::string& from) { return std::stoul(from); }
    };

    template<>
    class ArgConvert<long int> {
    public:
        long int operator()(const std::string& from) { return std::stol(from); }
    };

    template<>
    class ArgConvert<unsigned long long int> {
    public:
        unsigned long long int operator()(const std::string& from) { return std::stoull(from); }
    };

    template<>
    class ArgConvert<long long int> {
    public:
        long long int operator()(const std::string& from) { return std::stoll(from); }
    };

    template<>
    class ArgConvert<float> {
    public:
        float operator()(const std::string& from) { return std::stof(from); }
    };

    template<>
    class ArgConvert<double> {
    public:
        double operator()(const std::string& from) { return std::stod(from); }
    };

    template<>
    class ArgConvert<long double> {
    public:
        long double operator()(const std::string& from) { return std::stold(from); }
    };
}

#endif