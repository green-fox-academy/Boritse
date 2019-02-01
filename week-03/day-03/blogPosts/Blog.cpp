//
// Created by Borbáls on 2019. 02. 01..
//

#include "Blog.h"
#include "Blogposts.h"
#include <vector>


Blog::Blog(){};
void Blog::add(Blogpsts _anypost)
{
    blogposts.push_back(_anypost);
};
void Blog::remove(int i)
{
    blogposts.erase(blogposts.begin() +i);
};
void Blog::update(int k, Blogpsts _newpost)
{
    blogposts[k]=_newpost;
};
int Blog::amountOfPosts(){
    int x=0;
    for(int i=0; i<blogposts.size(); i++){
        x++;
    }
    return x;
};