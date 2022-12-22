
#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

#include <iostream>


class HealthPoints{

public:
    enum InvalidArgument {fail};

    HealthPoints(int maxHP = 100);
    HealthPoints(HealthPoints&) = default;
    ~HealthPoints() = default;

    HealthPoints& operator+=(const int&);
    HealthPoints& operator+=(const HealthPoints&) = delete;
    HealthPoints& operator-=(const int&);

    HealthPoints& operator=(int);
    HealthPoints& operator=(const HealthPoints&) = default;
    bool operator==(HealthPoints&) const;
    bool operator>(HealthPoints&) const;
    bool operator<(HealthPoints&) const;
    bool operator>=(HealthPoints&) const;
    bool operator<=(HealthPoints&) const;

private:
    int m_currentHP;
    int m_maxHP;
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
    friend HealthPoints& operator+( HealthPoints&, const int&);
    friend HealthPoints& operator+(const int&, HealthPoints&);
    friend HealthPoints& operator-(HealthPoints&, const int&);
    friend HealthPoints& operator-(const int&, HealthPoints&);
};

HealthPoints& HealthPoints::operator+=(const int& value)
{
    m_currentHP += value;
    if (m_currentHP > m_maxHP){
        m_currentHP = m_maxHP;
        return *this;
    }
    return *this;
};

HealthPoints& HealthPoints::operator-=(const int& value)
{
    m_currentHP -= value;
    if (m_currentHP < 0){
        m_currentHP = 0;
        return *this;
    }
    return *this;
};

HealthPoints& operator+( HealthPoints& health, const int& value)
{
    health.m_currentHP += value;
    if (health.m_currentHP > health.m_maxHP){
        health.m_currentHP = health.m_maxHP;
    }
};
HealthPoints& operator+(const int& value, HealthPoints& health)
{
    health.m_currentHP += value;
    if (health.m_currentHP > health.m_maxHP){
        health.m_currentHP = health.m_maxHP;
    }
};
HealthPoints& operator-(HealthPoints& health, const int& value)
{
    health.m_currentHP -= value;
    if (health.m_currentHP < 0){
        health.m_currentHP = 0;
    }
};
HealthPoints& operator-(const int& value, HealthPoints& health)
{
    health.m_currentHP -= value;
    if (health.m_currentHP < 0){
        health.m_currentHP = 0;
    }
};



#endif //EX3_HEALTHPOINTS_H
