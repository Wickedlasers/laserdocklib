#include <iostream>

using namespace std;

namespace
{
    int simple() { return 0; }
    float test1(int first, float second, char third) { return 0.0; }
    float test2(int first, float second, char third) { return 0.0; }

    template <typename T_Example>
    void templateExample(T_Example param) {}

    class Class
    {
    public: // interface
        void method(int var) {}
        void overload(int var) {}
        void overload(int first, float second) {}

    }; // class

    template <typename T_Example>
    class TemplateClass
    {
    public: // interface
        void templateDo(T_Example templateParam, int extraParam) {}

    }; // class

} // namespace

typedef void (Class::*ClassIntParamTypeFuncPtr)(int);

void print_class (Class * c, ClassIntParamTypeFuncPtr method){

    (c->*method)(1);
}

int main(int arg, char** argv)
{
    cout << "Hellow World!" << endl;
    // non-member examples
    int (*simpleNonMember)() = simple;
    simpleNonMember();

    typedef float (*TestTypeFuncPtr)(int, float, char);

    TestTypeFuncPtr test1FuncPtr = test1;
    TestTypeFuncPtr test2FuncPtr = test2;
    test1(7, 12.5, 'c'); // directly
    test1FuncPtr(7, 12.5, 'c'); // through the function pointer
    test2FuncPtr(11, 857.2, 'r');

    // non-member template examples
    void (*templateExampleFuncPtr1)(int) = templateExample<int>;
    void (*templateExampleFuncPtr2)(float) = templateExample<float>;
    templateExampleFuncPtr1(7);
    templateExampleFuncPtr2(7.f);

    // member examples
    Class* classPtr = new Class();
    Class classRef;
    void (Class::*overload2FuncPtr)(int, float) = &Class::overload;
    (classRef.*overload2FuncPtr)(0, 2.f);

    ClassIntParamTypeFuncPtr overload1AndMethodFuncPtr = nullptr;
    overload1AndMethodFuncPtr = &Class::method;
    overload1AndMethodFuncPtr = &Class::overload;
    (classPtr->*overload1AndMethodFuncPtr)(7);
    (classRef.*overload1AndMethodFuncPtr)(7);

    // template class member examples
    TemplateClass<float>* templateClassPtr = new TemplateClass<float>();

    typedef void (TemplateClass<float>::*TemplateDoTypeFloat)(float, int);
    TemplateDoTypeFloat templateDoFuncPtr = &TemplateClass<float>::templateDo;
    (templateClassPtr->*templateDoFuncPtr)(11.f, 5);

} // main 