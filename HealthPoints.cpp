//
// Created by Tamer Khalifa on 13/12/2022.
//
#include "HealthPoints.h"

HealthPoints::HealthPoints(int max)
{
    try {
        if (max > 0) {
            m_maxHP = m_currentHP = max;
        }

        else {
            throw HealthPoints::InvalidArgument::fail ;
        }
    }
    catch (HealthPoints::InvalidArgument fail ){}
}



HealthPoints& HealthPoints::operator=(const int value) {
    if(value <= m_maxHP && value >= 0){
        m_currentHP = value;
    }

    return *this;
}

bool HealthPoints::operator==(HealthPoints& hp) const {
    return (hp.m_currentHP == m_currentHP);
}

bool HealthPoints::operator>=(HealthPoints& hp) const {
    return (m_currentHP >= hp.m_currentHP);
}

bool HealthPoints::operator>(HealthPoints& hp) const {
    return (m_currentHP > hp.m_currentHP);
}

bool HealthPoints::operator<(HealthPoints& hp) const {
    return (m_currentHP < hp.m_currentHP);
}

bool HealthPoints::operator<=(HealthPoints& hp) const {
    return (m_currentHP <= hp.m_currentHP);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp) {
    os << hp.m_currentHP << "(" << hp.m_maxHP << ")";
    return os;
}