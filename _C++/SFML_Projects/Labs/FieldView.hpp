#ifndef FIELD_VIEW_HPP
#define FIELD_VIEW_HPP

#include"Field.hpp"
#include<SFML/Graphics.hpp>
#include<map>
#include<initializer_list>
#include<functional>

enum class OutMode { CLI, GUI };

class FieldView {
public:
    FieldView(Field& _field, OutMode md = OutMode::GUI);
    ~FieldView(){}

    void Mode(OutMode md);
    void setField(Field& _field);
    void loadPictures(std::initializer_list<std::string> fpList);
    void draw();
private:
    // std::reference_wrapper<Field> field;
    Field& field;
    OutMode mode;
    std::map<Type, std::string> filePaths;

};


#endif //FIELD_VIEW_HPP