#ifndef __CREST_H_
#define __CREST_H_

#include <memory>

class Shots;
class Crest {
public:
    Crest() {}
    virtual ~Crest() {}
    virtual void generate(Shots&) {};
    virtual void onHit(Shots&) {};
    virtual void onMiss(Shots&) {};
};

class Aries : public Crest {
public:
    Aries() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Aries> getInstance();
private:
    static std::shared_ptr<Aries> instance;
};

class Aquarius : public Crest {
public:
    Aquarius() : Crest() {}
    void onHit(Shots&) override;
    static std::shared_ptr<Aquarius> getInstance();
private:
    static std::shared_ptr<Aquarius> instance;
};

class Cancer : public Crest {
public:
    Cancer() : Crest() {}
    void onHit(Shots&) override;
    static std::shared_ptr<Cancer> getInstance();
private:
    static std::shared_ptr<Cancer> instance;
};

class Capricorn : public Crest {
public:
    Capricorn() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Capricorn> getInstance();
private:
    static std::shared_ptr<Capricorn> instance;
};

class Gemini : public Crest {
public:
    Gemini() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Gemini> getInstance();
private:
    static std::shared_ptr<Gemini> instance;
};

class Leo : public Crest {
public:
    Leo() : Crest() {}
    void generate(Shots&) override;
    void onHit(Shots&) override;
    static std::shared_ptr<Leo> getInstance();
private:
    static std::shared_ptr<Leo> instance;
};

class Libra : public Crest {
public:
    Libra() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Libra> getInstance();
private:
    static std::shared_ptr<Libra> instance;
};

class Ophiucus : public Crest {
public:
    Ophiucus() : Crest() {}
    void onHit(Shots&) override;
    static std::shared_ptr<Ophiucus> getInstance();
private:
    static std::shared_ptr<Ophiucus> instance;
};

class Pisces : public Crest {
public:
    Pisces() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Pisces> getInstance();
private:
    static std::shared_ptr<Pisces> instance;
};

class Sagittarius : public Crest {
public:
    Sagittarius() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Sagittarius> getInstance();
private:
    static std::shared_ptr<Sagittarius> instance;
};

class Scorpio : public Crest {
public:
    Scorpio() : Crest() {}
    void onHit(Shots&) override;
    static std::shared_ptr<Scorpio> getInstance();
private:
    static std::shared_ptr<Scorpio> instance;
};

class Taurus : public Crest {
public:
    Taurus() : Crest() {}
    void generate(Shots&) override;
    static std::shared_ptr<Taurus> getInstance();
private:
    static std::shared_ptr<Taurus> instance;
};

class Virgo : public Crest {
public:
    Virgo() : Crest() {}
    void onHit(Shots&) override;
    static std::shared_ptr<Virgo> getInstance();
private:
    static std::shared_ptr<Virgo> instance;
};
#endif