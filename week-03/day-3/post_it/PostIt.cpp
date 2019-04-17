//
// Created by Bence on 2019.04.17..
//

#include "PostIt.h"

PostIt::PostIt(std::string backgroundColor, std::string text, std::string textColor) {
    setBackgroundColor(backgroundColor);
    setText(text);
    setTextColor(textColor);
}

void PostIt::setBackgroundColor(std::string backgroundColor) {
    _backgroundColor = backgroundColor;
}
void PostIt::setText(std::string text) {
    _text = text;
}
void PostIt::setTextColor(std::string textColor) {
    _textColor = textColor;
}
std::string PostIt::getBackgroundColor(){
    return _backgroundColor;
}
std::string PostIt::getText(){
    return _text;
}
std::string PostIt::getTextColor(){
    return _textColor;
}