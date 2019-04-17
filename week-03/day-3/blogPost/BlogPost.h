//
// Created by Bence on 2019.04.17..
//
#include <iostream>
#include <string>

#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H


class BlogPost {
public:
    BlogPost(const std::string &name, const std::string &title, const std::string &text,
             const std::string &publicationDate);

    void setName(const std::string &name);

    void setTitle(const std::string &title);

    void setText(const std::string &text);

    void setPublicationDate(const std::string &publicationDate);

    const std::string &getName() const;

    const std::string &getTitle() const;

    const std::string &getText() const;

    const std::string &getPublicationDate() const;

private:
    std::string _name;
    std::string _title;
    std::string _text;
    std::string _publicationDate;


};


#endif //BLOGPOST_BLOGPOST_H
