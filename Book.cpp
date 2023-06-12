//
//  Book.cpp
//  hw7
//
//  Created by Orkun Gökçe on 3.06.2023.
//
#include "Book.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

Book::Book(){
    
}

Book::Book(const string& mytitle, const string& myauthor, int mypublicationYear){
 
    title = mytitle;
    author = myauthor;
    publicationYear = mypublicationYear;
    
}

string Book::getTitle() const{
    
    return title;
    
}

string Book::getAuthor() const{
    
    return author;
}

int Book::getPublicationYear()const{
    
    return publicationYear;
}

void Book::setTitle(const string& book_title){
    
    title = book_title;
    
}

void Book::setAuthor(const string &book_author){
    
    author = book_author;
}

void Book::setPublicationYear(int book_publicationYear){
    
    publicationYear = book_publicationYear;
    
}

string Book::getAuthorLastName()const{
    
    string a;
    if (getAuthor().rfind(" ") != string::npos)
        a = getAuthor().substr(getAuthor().rfind(" ") + 1);
    else
        a = getAuthor();
    return a;
    
}

void Book::display() const{
    string a, b;
    int c;
    a = getTitle();
    b = getAuthor();
    c = getPublicationYear();
    cout<<a<<", "<<b<<", "<<c<<endl;
    
}
