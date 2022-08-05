//
// Created by admin on 2022/8/5.
//
#include <memory>

int main() {
    //智能指针保存的是一个文件资源，那么我们需要自定义一个删除器
    auto deleter = [](FILE *f){ fclose(f);};

    auto file = std::unique_ptr<FILE, decltype(deleter)> (
            fopen("Somefile.txt", "w"), deleter
            );

    auto l = [i = 0]() mutable  {
        return ++i;
    };

    l();
    l();
    l();
}
