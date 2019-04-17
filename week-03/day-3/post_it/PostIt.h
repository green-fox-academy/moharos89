//
// Created by Bence on 2019.04.17..
//
#include <iostream>
#include <string>

#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H


class PostIt {
public:
    PostIt(std::string backgroundColor, std::string text, std::string textColor);

    void setBackgroundColor(std::string background);

    void setText(std::string text);

    void setTextColor(std::string textColor);

    std::string getBackgroundColor();

    std::string getText();

    std::string getTextColor();


private:
    std::string _backgroundColor;
    std::string _text;
    std::string _textColor;

};


#endif //POST_IT_POSTIT_H
