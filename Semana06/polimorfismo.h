#ifndef PROGRAMMING_POLIMORFISMO_H
#define PROGRAMMING_POLIMORFISMO_H

class Work {
public:
    Work() = default;
    Work(Work const&) = default;
    Work(std::string id, std::string title)
    : id_{id}, title_{title}
    {}
    virtual ~Work() {}
    std::string id()    { return id_; }
    std::string title() { return title_; }
    virtual void print(std::ostream&) {}
private:
    std::string id_;
    std::string title_;
};

class Book : public Work {
public:
    Book()
    : Work{}, author_{}, pubyear_{0}
    {}
    Book(Book const&) = default;
    Book(std::string id, std::string title, std::string author, int pubyear)
    : Work{id, title}, author_{author}, pubyear_{pubyear}
    {}
    std::string author() { return author_; }
    int pubyear()        { return pubyear_; }
    void print(std::ostream& out) override {
        out << author() << ", " << title() << ", " << pubyear() << ".";
    }
private:
    std::string author_;
    int pubyear_;
};

class Periodical : public Work {
public:
    Periodical()
    : Work{}, volume_{0}, number_{0}, date_{}
    {}
    Periodical(Periodical const&) = default;
    Periodical(std::string id, std::string title, int volume,
               int number, std::string date)
    : Work{id, title}, volume_{volume}, number_{number}, date_{date}
    {}
    int volume() { return volume_; }
    int number() { return number_; }
    std::string  date() { return date_; }
    void print(std::ostream& out) override {
        out << title() << ", " << volume() << '(' << number() << "), " <<
            date() << ".";
    }
private:
    int volume_;
    int number_;
    std::string date_;
};


#endif //PROGRAMMING_POLIMORFISMO_H
