/* 
 * File:   validationFormat.h
 * Author: etudiant
 *
 * Created on 12 février 2024, 13 h 11
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>
#include <istream>

namespace util {
    bool validePointCardinal(const std::string& p_cardinalite);
    bool valideLigneCVSBorneStationnement(const std::string& p_ligne);
    bool valideFichierBornesStationnement(std::istream& p_fluxBornesStationnement);
}

#endif // VALIDATIONFORMAT_H



