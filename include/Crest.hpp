#ifndef __CREST_H_
#define __CREST_H_

#include <memory>
#include <optional>
#include <string>

class Entity;
class Shots;
class Crest {
public:
    Crest() {}
    virtual ~Crest() {}
    virtual void generate(Shots&) {};
    virtual void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) {};
    virtual void onMiss(Shots&) {};
    virtual std::string describe() = 0;
};

class Aries : public Crest {
public:
    Aries() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Aries> getInstance();
    std::string describe() override {return "Aries";}
private:
    static std::shared_ptr<Aries> instance;
};

class Aquarius : public Crest {
public:
    Aquarius() : Crest() {}
    void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) override;
    static std::shared_ptr<Aquarius> getInstance();
    std::string describe() override {return "Aquarius";}
private:
    static std::shared_ptr<Aquarius> instance;
};

class Cancer : public Crest {
public:
    Cancer() : Crest() {}
    void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) override;
    static std::shared_ptr<Cancer> getInstance();
    std::string describe() override {return "Cancer";}
private:
    static std::shared_ptr<Cancer> instance;
};

class Capricorn : public Crest {
public:
    Capricorn() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Capricorn> getInstance();
    std::string describe() override {return "Capricorn";}
private:
    static std::shared_ptr<Capricorn> instance;
};

class Gemini : public Crest {
public:
    Gemini() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Gemini> getInstance();
    std::string describe() override {return "Gemini";}
private:
    static std::shared_ptr<Gemini> instance;
};

class Leo : public Crest {
public:
    Leo() : Crest() {}
    void generate(Shots&) override;
    void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) override;
    static std::shared_ptr<Leo> getInstance();
    std::string describe() override {return "Leo";}
private:
    static std::shared_ptr<Leo> instance;
};

class Libra : public Crest {
public:
    Libra() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Libra> getInstance();
    std::string describe() override {return "Libra";}
private:
    static std::shared_ptr<Libra> instance;
};

class Ophiucus : public Crest {
public:
    Ophiucus() : Crest() {}
    void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) override;
    static std::shared_ptr<Ophiucus> getInstance();
    std::string describe() override {return "Ophiucus";}
private:
    static std::shared_ptr<Ophiucus> instance;
};

class Pisces : public Crest {
public:
    Pisces() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Pisces> getInstance();
    std::string describe() override {return "Pisces";}
private:
    static std::shared_ptr<Pisces> instance;
};

class Sagittarius : public Crest {
public:
    Sagittarius() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Sagittarius> getInstance();
    std::string describe() override {return "Sagittarius";}
private:
    static std::shared_ptr<Sagittarius> instance;
};

class Scorpio : public Crest {
public:
    Scorpio() : Crest() {}
    void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) override;
    static std::shared_ptr<Scorpio> getInstance();
    std::string describe() override {return "Scorpio";}
private:
    static std::shared_ptr<Scorpio> instance;
};

class Taurus : public Crest {
public:
    Taurus() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Taurus> getInstance();
    std::string describe() override {return "Taurus";}
private:
    static std::shared_ptr<Taurus> instance;
};

class Virgo : public Crest {
public:
    Virgo() : Crest() {}
    void onHit(Shots&, int x, int y, std::optional<std::reference_wrapper<Entity>> hit) override;
    static std::shared_ptr<Virgo> getInstance();
    std::string describe() override {return "Virgo";}
private:
    static std::shared_ptr<Virgo> instance;
};
#endif