#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book{

    private:
        int book_id;
        std::vector<std::string> authors;
        std::string title;
        int year;
        std::string position;
        float value;

    public:
        Book(int = 0, std::vector<std::string> ={}, const std::string& = "", int = 1900, const std::string& = "", float= 0.0);
        bool operator<(const Book&);
        int getId() const {return book_id;}
        std::vector<std::string> getAuthors() const {return authors;}
        std::string getTitle() const {return title;}
        int getYear() const {return year;}
        std::string getPosition() const {return position;}
        float getValue() const {return value;}
        virtual void print() const;





};


#endif