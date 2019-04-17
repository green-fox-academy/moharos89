//
// Created by Bence on 2019.04.17..
//

#include "BlogPost.h"

BlogPost::BlogPost(const std::string &name, const std::string &title, const std::string &text,
                   const std::string &publicationDate) : _name(name), _title(title), _text(text),
                                                         _publicationDate(publicationDate) {

}

void BlogPost::setName(const std::string &name) {
    _name = name;
}

void BlogPost::setTitle(const std::string &title) {
    _title = title;
}

void BlogPost::setText(const std::string &text) {
    _text = text;
}

void BlogPost::setPublicationDate(const std::string &publicationDate) {
    _publicationDate = publicationDate;
}

const std::string &BlogPost::getName() const {
    return _name;
}

const std::string &BlogPost::getTitle() const {
    return _title;
}

const std::string &BlogPost::getText() const {
    return _text;
}

const std::string &BlogPost::getPublicationDate() const {
    return _publicationDate;
}
