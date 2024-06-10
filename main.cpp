#include <iostream>
#include <string>

// Weapon Ŭ���� ����
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
        std::cout << "���� �̸�: " << name << "    ���� ���ݷ�: " << damage << std::endl;
    }
};

// Character �߻� Ŭ���� ����
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
        std::cout << name << "���� �̵��Ͽ����ϴ�." << std::endl;
    }

    virtual void showInfo() const {
        std::cout << "ĳ���� �̸�: " << name << "    ����: " << level << std::endl;
        std::cout << "��: " << strength << "             ��ø: " << agility << "    ����: " << intelligence << std::endl;
        std::cout << "���ݷ�: " << attack << "           ����: " << defense << "   ü��: " << health << "    ���ŷ�: " << mana << std::endl;
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

// Warrior Ŭ���� ����
class Warrior : public Character {
public:
    Warrior(const std::string& _name, Weapon* _weapon) : Character(_name, 1, 100, 50, 20, 5, 3, 80, 20, _weapon) {}

    void showInfo() const override {
        Character::showInfo();
    }

    void strike(Character& target) override {
        int totalAttack = attack + weapon->getDamage();
        std::cout << getName() << "���� " << target.getName() << "���� " << weapon->getName() << " Į�� �񷶽��ϴ�. ";
        target.takeDamage(totalAttack);
        std::cout << target.getName() << "���� ü���� " << target.health << " ���ҽ��ϴ�." << std::endl;
    }
};

// Archer Ŭ���� ����
class Archer : public Character {
public:
    Archer(const std::string& _name, Weapon* _weapon) : Character(_name, 1, 50, 100, 20, 5, 3, 50, 50, _weapon) {}

    void showInfo() const override {
        Character::showInfo();
    }

    void strike(Character& target) override {
        int totalAttack = attack + weapon->getDamage();
        std::cout << getName() << "���� " << target.getName() << "�Կ��� " << weapon->getName() << " ȭ���� �����ϴ�. ";
        target.takeDamage(totalAttack);
        std::cout << target.getName() << "���� ü���� " << target.health << " ���ҽ��ϴ�." << std::endl;
    }
};

// Sorcerer Ŭ���� ����
class Sorcerer : public Character {
public:
    Sorcerer(const std::string& _name, Weapon* _weapon) : Character(_name, 1, 20, 50, 100, 5, 3, 20, 80, _weapon) {}

    void showInfo() const override {
        Character::showInfo();
    }

    void strike(Character& target) override {
        int totalAttack = attack + weapon->getDamage();
        std::cout << getName() << "���� " << target.getName() << "�Կ��� " << weapon->getName() << " ������ �ɾ����ϴ�. ";
        target.takeDamage(totalAttack);
        std::cout << target.getName() << "���� ü���� " << target.health << " ���ҽ��ϴ�." << std::endl;
    }
};

int main() {
    Weapon mightySword("������", 3);
    Weapon mysticalBow("�ź��� Ȱ", 2);
    Weapon skyStaff("�ϴ��� ������", 2);
    Weapon ironSword("��ö��", 1);

    Character* character1 = new Warrior("����1", &mightySword);
    Character* character2 = new Archer("�ü�1", &mysticalBow);
    Character* character3 = new Sorcerer("������1", &skyStaff);
    Character* character4 = new Warrior("����2", &ironSword);

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

