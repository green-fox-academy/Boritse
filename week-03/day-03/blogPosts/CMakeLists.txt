cmake_minimum_required(VERSION 3.13)
project(blogPosts)

set(CMAKE_CXX_STANDARD 14)

add_executable(blogPosts main.cpp Blog.cpp Blog.h Blogposts.cpp Blogposts.h)