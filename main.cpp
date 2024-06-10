#include <iostream>
#include <string>

// Weapon 클래스 정의
class Weapon {
private:
    std::string name;
    int damage;

public:
    Weapon(const std::string& _name, int _damage) : name(_name), damage(_damage) {}

    int getDamage() const {
        return damage;
    }

    std::string getName() const {
        return name;
    }

    void showInfo() const {
        std::cout << "무기 이름: " << name << "    무기 공격력: " << damage << std::endl;
    }
};

// Character 추상 클래스 정의
class Character {
protected:
    std::string name;
    int level;
    int strength;
    int agility;
    int intelligence;
    int attack;
    int defense;
    int mana;
    Weapon* weapon;

public:
    Character(const std::string& _name, int _level, int _strength, int _agility, int _intelligence, int _attack, int _defense, int _health, int _mana, Weapon* _weapon)
            : name(_name), level(_level), strength(_strength), agility(_agility), intelligence(_intelligence), attack(_attack), defense(_defense), health(_health), mana(_mana), weapon(_weapon) {}

    virtual ~Character() {}

    virtual void move() {
        std::cout << name << "님이 이동하였습니다." << std::endl;
    }

    virtual void showInfo() const {
        std::cout << "캐릭터 이름: " << name << "    레벨: " << level << std::endl;
        std::cout << "힘: " << strength << "             민첩: " << agility << "    지능: " << intelligence << std::endl;
        std::cout << "공격력: " << attack << "           방어력: " << defense << "   체력: " << health << "    정신력: " << mana << std::endl;
        if (weapon) {
            weapon->showInfo();
        }
    }

    virtual std::string getName() const {
        return name;
    }

    virtual void strike(Character& target) = 0;

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    int health;
};

// Warrior 클래스 정의
class Warrior : public Character {
public:
    Warrior(const std::string& _name, Weapon* _weapon) : Character(_name, 1, 100, 50, 20, 5, 3, 80, 20, _weapon) {}

    void showInfo() const override {
        Character::showInfo();
    }

    void strike(Character& target) override {
        int totalAttack = attack + weapon->getDamage();
        std::cout << getName() << "님이 " << target.getName() << "님을 " << weapon->getName() << " 칼로 찔렀습니다. ";
        target.takeDamage(totalAttack);
        std::cout << target.getName() << "님의 체력이 " << target.health << " 남았습니다." << std::endl;
    }
};

// Archer 클래스 정의
class Archer : public Character {
public:
    Archer(const std::string& _name, Weapon* _weapon) : Character(_name, 1, 50, 100, 20, 5, 3, 50, 50, _weapon) {}

    void showInfo() const override {
        Character::showInfo();
    }

    void strike(Character& target) override {
        int totalAttack = attack + weapon->getDamage();
        std::cout << getName() << "님이 " << target.getName() << "님에게 " << weapon->getName() << " 화살을 쐈습니다. ";
        target.takeDamage(totalAttack);
        std::cout << target.getName() << "님의 체력이 " << target.health << " 남았습니다." << std::endl;
    }
};

// Sorcerer 클래스 정의
class Sorcerer : public Character {
public:
    Sorcerer(const std::string& _name, Weapon* _weapon) : Character(_name, 1, 20, 50, 100, 5, 3, 20, 80, _weapon) {}

    void showInfo() const override {
        Character::showInfo();
    }

    void strike(Character& target) override {
        int totalAttack = attack + weapon->getDamage();
        std::cout << getName() << "님이 " << target.getName() << "님에게 " << weapon->getName() << " 마법을 걸었습니다. ";
        target.takeDamage(totalAttack);
        std::cout << target.getName() << "님의 체력이 " << target.health << " 남았습니다." << std::endl;
    }
};

int main() {
    Weapon mightySword("무적검", 3);
    Weapon mysticalBow("신비의 활", 2);
    Weapon skyStaff("하늘의 지팡이", 2);
    Weapon ironSword("강철검", 1);

    Character* character1 = new Warrior("전사1", &mightySword);
    Character* character2 = new Archer("궁수1", &mysticalBow);
    Character* character3 = new Sorcerer("마법사1", &skyStaff);
    Character* character4 = new Warrior("전사2", &ironSword);

    character1->showInfo();
    std::cout << std::endl;
    character2->showInfo();
    std::cout << std::endl;
    character3->showInfo();
    std::cout << std::endl;
    character4->showInfo();
    std::cout << std::endl;

    character1->move();
    character2->move();
    character3->move();
    character4->move();

    std::cout << std::endl;

    character1->strike(*character2);
    std::cout << std::endl;
    character2->showInfo();
    std::cout << std::endl;

    character2->strike(*character3);
    std::cout << std::endl;
    character3->showInfo();
    std::cout << std::endl;

    character3->strike(*character1);
    std::cout << std::endl;
    character1->showInfo();

    delete character1;
    delete character2;
    delete character3;
    delete character4;

    return 0;
}

