#include <string>
#include <cstdio> // pour le remove
#include "stdafx.h"
#include "UsineAGaz.h"

using namespace std;

int main()
{
    string nsource, ndestination;
    string nsource_temp;
    string a_rechercher, a_remplacer;
    int nb_remplace;
    bool recommence;

    cout << "Entrez le nom du fichier source: ";
    getline(cin,nsource);

    if (! fichierExiste(nsource))
    {
        cout << "Le fichier source n'existe pas !";
        cout << "Je quitte !";
        return 1;
    }

    cout << "Entrez le nom du fichier de destination: ";
    getline(cin,ndestination);

    // On crée un fichier source temporaire
    nsource_temp = ndestination;
    nsource_temp.insert(nsource_temp.length(), ".tmp");

    // On copie la source dans le fichier temporaire
    copieSimple(nsource, nsource_temp);

    do
    {
        cout << "Entrez la chaîne à rechercher: ";
        getline(cin,a_rechercher);

        cout << "Entrez la chaîne de remplacement: ";
        getline(cin,a_remplacer);

        nb_remplace = copieRemplace(nsource_temp, ndestination, a_rechercher, a_remplacer);

        cout << "Nombre de remplacements: " << nb_remplace << "\n";

        recommence = demandeOuiNon("Voulez-vous effectuer un autre traitement ? (O/N)");
        if (recommence)
        {
            // On copie le resultat dans la source temporaire
            copieSimple(ndestination, nsource_temp);
        }
    } while (recommence);

    // on a fini, il ne reste qu'a retirer la source temporaire
    remove(nsource_temp.data());

	return 0;
}
