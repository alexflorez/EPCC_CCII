#include <iostream>
#include <string>

class Work {
public:
    Work() = default;
    // : id_{}, title_{} // ""
    // {}
    Work(Work const& w) = default;
    // : id_{w.id_}, title_{w.title_}
    // {}
    Work(std::string id, std::string title)
    : id_{id}, title_{title}
    {}

    std::string id()    { return id_; }
    std::string title() { return title_; }
private:
    std::string id_;
    std::string title_;
};

class Book : public Work {
public:
    Book()
    : Work{}, author_{}, pubyear_{}  // "", 0
    {}
    Book(Book const&) = default;
    Book(std::string id, std::string title, std::string author, int pubyear)
    : Work{id, title}, author_{author}, pubyear_{pubyear}
    {}

    std::string author() { return author_; }
    int pubyear()        { return pubyear_; }
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
    std::string date() { return date_; }
private:
    int volume_;
    int number_;
    std::string date_;
};

int main() {
    Book b{"1", "Atomic Habits", "James Clear", 2018};
    Periodical p{"2", "Times", 1, 1, "May 1, 2020"};
    std::cout << b.title() << '\n' << p.title() << '\n';
}
