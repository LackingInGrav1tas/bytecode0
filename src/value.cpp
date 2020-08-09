#include <vector>
#include <string>
#include <iostream>
#include <stack>

#include "vm.hpp"
#include "types.hpp"

Value numberValue(double num) {
    Value val;
    val.type = TYPE_DOUBLE;
    val.storage.number = num;
    return val;
}

Value stringValue(char* str) {
    Value val;
    val.type = TYPE_STRING;
    val.storage.string = str;
    return val;
}

Value boolValue(bool boolean) {
    Value val;
    val.type = TYPE_BOOL;
    val.storage.boolean = boolean;
    return val;
}

Value nullValue() {
    Value val;
    val.type = TYPE_NULL;
    val.storage.boolean = false;
    val.storage.number = 0;
    val.storage.string = "";
    return val;
}

std::string shorten(std::string str) {
    while (str.back() == '0')
        str.pop_back();
    if (str.back() == '.')
        str.pop_back();
    return str;
}

std::string getPrintable(Value value) {
    switch (value.type) {
        case TYPE_DOUBLE: return shorten(std::to_string(value.storage.number));
        case TYPE_BOOL: return std::to_string(value.storage.boolean);
        case TYPE_STRING: return value.storage.string;
        case TYPE_NULL: return "";
        default: return "error";
    }
}