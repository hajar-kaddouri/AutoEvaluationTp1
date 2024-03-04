#include "validationFormat.h"
#include <sstream>
#include <vector>

namespace util {

    // Vérifier la cardinalité 
    bool validePointCardinal(const std::string& p_cardinalite) {
        // Les points cardinaux valides sont N, S, E, O, ou une chaîne vide.
        const std::string pointsValides[] = {"N", "S", "E", "O", ""};
        for (const std::string& point : pointsValides) {
            if (p_cardinalite == point) return true;
        }
        return false; 
    }

    // Valider ligne dans le CSV comme étant une borne de stationnement.
    bool valideLigneCVSBorneStationnement(const std::string& p_ligne) {
        std::istringstream ss(p_ligne);
        std::string token;
        std::vector<std::string> champs;

        // Sépare la ligne CSV en champs en utilisant ',' comme délimiteur.
        while (std::getline(ss, token, ',')) {
            champs.push_back(token);
        }

        // Vérifie la ligne a 7 champs.
        if (champs.size() != 7) return false;

        // seulement validePointCardinal est vérifié, Le champ point cardinal peut être vide
        if (!validePointCardinal(champs[2])) return false;

        // Conversion en double longitude et latitude -- pour vérification.
        
        double longitude, latitude;
        std::istringstream(champs[5]) >> longitude;
        std::istringstream(champs[6]) >> latitude;

        // Vérifie que la longitude est -71 et la latitude est 46.
        if (longitude != -71 || latitude != 46) return false;
        // La ligne est valide si toutes les vérifications ci-dessus sont passées.
        return true; 
    }

    // Valide le contenu d'un fichier CSV représentant des bornes de stationnement.
    bool valideFichierBornesStationnement(std::istream& p_fluxBornesStationnement) {
        std::string ligne;
        std::getline(p_fluxBornesStationnement, ligne); // pour Ignore l'en-tête.

        // Parcourt chaque ligne du fichier pour validation.
        while (std::getline(p_fluxBornesStationnement, ligne)) {
            if (!ligne.empty() && !valideLigneCVSBorneStationnement(ligne)) {
                return false;
            }
        }

        return true; // si Toutes les lignes sont valides.
    }

}
