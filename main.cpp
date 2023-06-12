//
//  main.cpp
//  hw7
//
//  Created by Orkun Gökçe on 3.06.2023.
//
#include "Book.h"
#include "strutils.h"
#include <iostream>
#include <string>
#include <vector>

string lastName(string x) {
    string a;
    if (x.rfind(" ") != string::npos)
        a = x.substr(x.rfind(" ") + 1);
    else
        a = x;
    return a;
}

void addition(vector<Book>& a) {

    
    string title, author,z;
    int year;

    
    getline(cin,z);
    cout << "Enter the new book details: " << endl;
    cout << "Enter book's title: ";
    getline(cin, title);
    cout << "Enter book's author: ";
    getline(cin, author);
    cout << "Enter book's publication year: ";
    cin >> year;

    a.push_back({ title,author,year });
    
    

    

}
void displayOPS() {

    cout << "Library System Menu:" << endl;
    cout << "1. Add books" << endl;
    cout << "2. Search for an author" << endl;
    cout << "3. Search for by book title" << endl;
    cout << "4. Display books" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}


void insertion(vector<Book>& x, int n)
{
    Book key;
    int i, j = 0;
    for (i = 1; i < n; i++)
    {
        key = x[i];
        j = i - 1;

        // Move elementsof arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && LowerString(x[j].getAuthorLastName()) > LowerString(key.getAuthorLastName()))
        {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = key;

    }
  

}

void insertionAl(vector<Book>& x, int n)
{
    Book key;
    int i, j = 0;
    for (i = 1; i < n; i++)
    {
        key = x[i];
        j = i - 1;

        // Move elementsof arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && LowerString(x[j].getTitle()) > LowerString(key.getTitle()))
        {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = key;

    }
  
    insertion(x,x.size());
}

void stdSearch(vector<Book> x, string a) {
    bool b = true;

    for (int i = 0; i < x.size(); i++) {

        if (LowerString(a) == LowerString(x[i].getTitle())) {
            
            cout << "Title: " << x[i].getTitle() << ", Author: "<<x[i].getAuthor() << ", Publication Year: " << x[i].getPublicationYear() << ", Position: " << i + 1 << endl;
            b = false;
        }


    }
    
    if(b){
        cout<<"No books were found." << endl;
    }
     
}

void stdSearch2(vector<Book> x) {
    string a, y, z;
    bool b = true, c= false;
    int zort = 0;
    getline(cin, z);
    cout << "Enter the author of the book you want to search for: ";
    getline(cin, y);
    a = LowerString(y);
    for (int m = 0; m< x.size();m++){
        
        if (LowerString(a) == LowerString(x[m].getAuthor())){
            c = true;
            zort = m;
            break;
        }
        
    }
    
    if (c){
        cout << "Books by " << lastName(y) << ":" << endl;
    }
    for (int i = 0; i < x.size(); i++) {

        if (LowerString(a) == LowerString(x[i].getAuthor())) {
            
            cout << "Title: " << x[i].getTitle() << ", Publication Year: " << x[i].getPublicationYear() << ", Position: " << i+1 << endl;
            b = false;
        }


    }
    
    if(b){
        cout<<"No books were found." << endl;
    }
     
}




int main() {
    
    int op = 0;
    int c = 1;
    string autS,titleS;
        vector<Book> books = {
        {"The Great Gatsby", "F Scott Fitzgerald", 1925},
        {"Moby Dick", "Herman Melville", 1851},
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"Pride and Prejudice", "Jane Austen", 1813},
        {"Burmese Days", "George Orwell", 1934},
        {"Brave New World", "Aldous Huxley", 1932},
        {"Animal Farm", "George Orwell", 1945}
        };
        string h;
        while (op != 5) {
            insertionAl(books, books.size());
            displayOPS();
            
            cin >> op;

            if (op == 1) {
                addition(books);
            }
            else if (op == 2) {
                
                stdSearch2(books);
                
                
            }
            else if (op == 3) {
                getline(cin, h);
                cout << "Enter the title of the book you want to search for: ";
                getline(cin, titleS);
                
                cout << "Books matching the title \"" << titleS << "\"" << ":" << endl;
                stdSearch(books, LowerString(titleS));
                  
                
                
                

            }
            else if (op == 4) {
                insertionAl(books, books.size());
                cout << "Sorted books by author's last name:" << endl;
                for (int i = 0; i < books.size(); i++) {
                    cout << i + 1 << ". " << books[i].getTitle() << ", " << books[i].getAuthor() << ", " << books[i].getPublicationYear() << endl;
                    


                }
                cout << endl;
            }
            else if (op != 5)
                cout << "Invalid choice, please try again." << endl;

        }
        cout << "Goodbye!" << endl;
            
    
    
    
    
    return 0;
    
}
