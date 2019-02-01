#include <iostream>
#include "Blogposts.h"
#include "Blog.h"

int main() {

    Blog myBlog;

    Blogpsts sanyi("Sanyi", "Sanyi Sándor", "Saaaanyiiii, Sanyikáááám", "1983.07.15.");
    Blogpsts karcsi("Karcsi", "Karcsi Károly", "Kaaaarcsiiii, Karcsikááám", "1994.02.13.");
    Blogpsts bela("Béla", "Béla Béla", "Béééélaaa, Bééluskáááám", "1996.02.13.");

    myBlog.add(sanyi);
    myBlog.add(karcsi);
    myBlog.add(bela);

    std::cout << myBlog.amountOfPosts() << std::endl;

    Blogpsts nyusziful("nyuszi", "nyusziful nyul", "nyunyunyunyunyunyu", "2019.02.01.");
    myBlog.update(1, nyusziful);

    std::cout << myBlog.amountOfPosts() << std::endl;

    myBlog.remove(2);

    std::cout << myBlog.amountOfPosts();

    return 0;
}