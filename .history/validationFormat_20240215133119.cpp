#include "validationFormat.h"
#include <sstream>
#include <vector>

namespace util {

    bool validePointCardinal(const std::string& p_cardinalite) {
        // Vérifiez si p_cardinalite est parmi les valeurs autorisées
        return p_cardinalite == "N" || p_cardinalite == "S" || 
               p_cardinalite == "E" || p_cardinalite == "O" || 
               p_cardinalite.empty();
    }

    bool valideLigneCVSBorneStationnement(const std::string& p_ligne) {
        std::istringstream stream(p_ligne);
        std::string token;
        std::vector<std::string> champs;

        // Découpez p_ligne en utilisant ',' comme séparateur
        while (getline(stream, token, ',')) {
            champs.push_back(token);
        }

        // Appliquez les validations spécifiques à chaque champ
        // Exemple de validation : champs[0] ne doit pas être vide, etc.

        // Assurez-vous que la longitude et la latitude correspondent aux valeurs attendues
        // Convertissez les champs en double au besoin et validez les valeurs

        return champs.size() == 7; // Assurez-vous que tous les champs requis sont présents et valides
    }

    bool valideFichierBornesStationnement(std::istream& p_fluxBornesStationnement) {
        std::string ligne;
        // Ignorez la première ligne (en-têtes)
        std::getline(p_fluxBornesStationnement, ligne);

        while (std::getline(p_fluxBornesStationnement, ligne)) {
            if (!ligne.empty() && !valideLigneCVSBorneStationnement(ligne)) {
                return false; // Retournez faux si une ligne est invalide
            }
        }

        return true; // Toutes les lignes sont valides
    }
}
