#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
#include <vector>

class Publication {


public:

    static int nGenPub;
    Publication (std::string,std::vector<std::string> ,int);
    ~Publication();

    //member functions
    virtual std::string toString();
    
    //operator
    bool operator < (const Publication&);
    bool operator > (const Publication&);
    
    // set functions
    Publication& setTitle(std::string);
    Publication& setAuthors(const std::vector<std::string>&);
    Publication& setYear(int);

    // get Functions
    std::string getTitle() const;
    const std::vector<std::string>& getAuthors();
    int getYear() const;

private:
    std::string title;
    std::vector<std::string> authors;
    int year;

};


#endif