#include "main.hpp"
#include "classutils.hpp"

using namespace ClassUtils;
using namespace il2cpp_utils;

// field_get_value, field_set_value
std::vector<FieldInfo*> ClassUtils::GetFields(Il2CppClass* klass) {
    std::vector<FieldInfo*> ret;
    // only a single pointer since fields are stored as values
    FieldInfo* iter = nullptr; // needs to be explicitly set to nullptr
    while(il2cpp_functions::class_get_fields(klass, (void**)(&iter))) {
        if(iter)
            ret.push_back(iter);
    }
    return ret;
}

// I think all the property methods are gotten by getMethods
std::vector<MethodInfo*> ClassUtils::GetPropMethods(PropertyInfo* prop) {
    std::vector<MethodInfo*> ret{};
    // should actually make everything else const, but I'm lazy
    if(auto m = il2cpp_functions::property_get_get_method(prop))
        ret.push_back(const_cast<MethodInfo*>(m));
    if(auto m = il2cpp_functions::property_get_set_method(prop))
        ret.push_back(const_cast<MethodInfo*>(m));
    return ret;
}

std::vector<PropertyInfo*> ClassUtils::GetProperties(Il2CppClass* klass) {
    std::vector<PropertyInfo*> ret;
    // only a single pointer since properties are stored as values
    PropertyInfo* iter = nullptr;
    while(il2cpp_functions::class_get_properties(klass, (void**)(&iter))) {
        if(iter)
            ret.push_back(iter);
    }
    return ret;
}

std::vector<MethodInfo*> ClassUtils::GetMethods(Il2CppClass* klass) {
    std::vector<MethodInfo*> ret;
    // double pointer because methods are stored as pointers
    MethodInfo** iter = nullptr;
    while(il2cpp_functions::class_get_methods(klass, (void**)(&iter))) {
        if(*iter)
            ret.push_back(*iter);
    }
    return ret;
}

std::vector<Il2CppClass*> ClassUtils::GetInterfaces(Il2CppClass* klass) {
    std::vector<Il2CppClass*> ret;
    // double pointer because classes are stored as pointers
    Il2CppClass** iter = nullptr;
    while(il2cpp_functions::class_get_interfaces(klass, (void**)(&iter))) {
        if(*iter)
            ret.push_back(*iter);
    }
    return ret;
}

Il2CppClass* ClassUtils::GetParent(Il2CppClass* klass) {
    return il2cpp_functions::class_get_parent(klass);
}
