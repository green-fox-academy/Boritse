//
// Created by Borbáls on 2019. 02. 01..
//

#ifndef BLOGPOSTS_BLOG_H
#define BLOGPOSTS_BLOG_H

#include "Blogposts.h"
#include <vector>

class Blog {
public:
    Blog();
    void add(Blogpsts _anypost);
    void remove(int i);
    void update(int k, Blogpsts _newpost);
    int amountOfPosts();
private:
    std::vector<Blogpsts> blogposts;
};


#endif //BLOGPOSTS_BLOG_H
