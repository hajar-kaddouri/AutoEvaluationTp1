#include "validationFormat.h"
#include <iostream>
#include <sstream>

int main() {
    // Test de la fonction validePointCardinal
    std::cout << "Test validePointCardinal:\n";
    std::cout << "N est valide ? " << (util::validePointCardinal("N") ? "Oui" : "Non") << std::endl;
    std::cout << "X est valide ? " << (util::validePointCardinal("X") ? "Oui" : "Non") << std::endl;
    std::cout << "(Vide) est valide ? " << (util::validePointCardinal("") ? "Oui" : "Non") << "\n\n";

    // Test de la fonction valideLigneCVSBorneStationnement
    std::cout << "Test valideLigneCVSBorneStationnement:\n";
    std::string ligneValide = "123,4567,N,890,Nom rue,-71.123,46.123";
    std::string ligneInvalide = "123,4567,N,890,Nom rue,-70.123,45.123"; // longitude et latitude incorrectes
    std::cout << "Ligne valide ? " << (util::valideLigneCVSBorneStationnement(ligneValide) ? "Oui" : "Non") << std::endl;
    std::cout << "Ligne invalide ? " << (util::valideLigneCVSBorneStationnement(ligneInvalide) ? "Oui" : "Non") << "\n\n";

    // Test de la fonction valideFichierBornesStationnement
    std::cout << "Test valideFichierBornesStationnement:\n";
    std::string dataFichier = 
        "ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE\n"
        "123,4567,N,890,Nom rue,-71.123,46.123\n"
        "124,4568,S,891,Autre rue,-71.124,46.124\n\n";
    std::istringstream fluxFichier(dataFichier); // Simule un fichier avec std::istringstream
    std::cout << "Fichier valide ? " << (util::valideFichierBornesStationnement(fluxFichier) ? "Oui" : "Non") << std::endl;

    return 0;
}