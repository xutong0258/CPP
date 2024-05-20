#include <iostream>  
#include <memory>  
  
// 一个简单的类  
class MyClass {  
public:  
    void print() const {  
        std::cout << "MyClass object printed!" << std::endl;  
    }  
};  
  
int main() {  
    // 创建一个原始的 shared_ptr  
    std::shared_ptr<MyClass> sptr = std::make_shared<MyClass>();  
  
    // 从 shared_ptr 创建一个 weak_ptr  
    std::weak_ptr<MyClass> wptr = sptr;  
  
    // 尝试将 weak_ptr 转换为 shared_ptr  
    if (std::shared_ptr<MyClass> temp_sptr = wptr.lock()) {  
        // 如果 temp_sptr 不是空的（即 weak_ptr 仍然有效），则使用它  
        temp_sptr->print();  
    } else {  
        // 如果 temp_sptr 是空的（即 weak_ptr 已经失效），则做一些其他的处理  
        std::cout << "The weak_ptr is expired!" << std::endl;  
    }  
  
    // 在这里，我们可以继续使用原始的 shared_ptr，或者再次从 weak_ptr 获取一个 shared_ptr  
    // 但请注意，过度使用 lock() 可能会导致 shared_ptr 的数量增加，从而影响资源的释放  
  
    // 为了演示 weak_ptr 的过期，我们重置原始的 shared_ptr  
    sptr.reset();  
  
    // 再次尝试从 weak_ptr 获取 shared_ptr  
    if (std::shared_ptr<MyClass> temp_sptr2 = wptr.lock()) {  
        // 如果 temp_sptr2 不是空的（实际上它会是空的，因为 sptr 已经被重置了）  
        // 则这里的代码不会被执行  
        temp_sptr2->print();  
    } else {  
        // 这里会输出 "The weak_ptr is expired!"  
        std::cout << "The weak_ptr is expired!" << std::endl;  
    }  
  
    return 0;  
}
