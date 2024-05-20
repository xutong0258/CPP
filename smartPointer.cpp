#include <iostream>  
#include <memory>  
  
// һ���򵥵���  
class MyClass {  
public:  
    void print() const {  
        std::cout << "MyClass object printed!" << std::endl;  
    }  
};  
  
int main() {  
    // ����һ��ԭʼ�� shared_ptr  
    std::shared_ptr<MyClass> sptr = std::make_shared<MyClass>();  
  
    // �� shared_ptr ����һ�� weak_ptr  
    std::weak_ptr<MyClass> wptr = sptr;  
  
    // ���Խ� weak_ptr ת��Ϊ shared_ptr  
    if (std::shared_ptr<MyClass> temp_sptr = wptr.lock()) {  
        // ��� temp_sptr ���ǿյģ��� weak_ptr ��Ȼ��Ч������ʹ����  
        temp_sptr->print();  
    } else {  
        // ��� temp_sptr �ǿյģ��� weak_ptr �Ѿ�ʧЧ��������һЩ�����Ĵ���  
        std::cout << "The weak_ptr is expired!" << std::endl;  
    }  
  
    // ��������ǿ��Լ���ʹ��ԭʼ�� shared_ptr�������ٴδ� weak_ptr ��ȡһ�� shared_ptr  
    // ����ע�⣬����ʹ�� lock() ���ܻᵼ�� shared_ptr ���������ӣ��Ӷ�Ӱ����Դ���ͷ�  
  
    // Ϊ����ʾ weak_ptr �Ĺ��ڣ���������ԭʼ�� shared_ptr  
    sptr.reset();  
  
    // �ٴγ��Դ� weak_ptr ��ȡ shared_ptr  
    if (std::shared_ptr<MyClass> temp_sptr2 = wptr.lock()) {  
        // ��� temp_sptr2 ���ǿյģ�ʵ���������ǿյģ���Ϊ sptr �Ѿ��������ˣ�  
        // ������Ĵ��벻�ᱻִ��  
        temp_sptr2->print();  
    } else {  
        // �������� "The weak_ptr is expired!"  
        std::cout << "The weak_ptr is expired!" << std::endl;  
    }  
  
    return 0;  
}
