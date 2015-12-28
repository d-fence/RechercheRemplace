#include "stdafx.h"
#include <fstream>
#include "UsineAGaz.h"

using namespace std;

bool fichierExiste(string nom_fichier)
{
    fstream fichier;
    fichier.open(nom_fichier.data(), ios::in);
    if (fichier.fail())
    {
        fichier.close();
        return false;
    }
    fichier.close();
    return true;
}

void copieSimple(string nom_source, string nom_destination)
{
    fstream fsource, fdestination;
    string ligne;
    fsource.open(nom_source.data(), ios::in);
    fdestination.open(nom_destination.data(), ios::out);
    do
    {
        getline(fsource, ligne);
        fdestination << ligne << endl;
    }
    while (! fsource.eof());

    fsource.close();
    fdestination.close();

}

int copieRemplace(string nom_source, string nom_destination, string a_rechercher, string a_remplacer)
{
    string ligne;
    int nbr = 0;
    unsigned long pos;
    bool fini = false;
    fstream fsource, fdestination;
    fsource.open(nom_source.data(), ios::in);
    fdestination.open(nom_destination.data(), ios::out);

    do
    {
        getline(fsource, ligne);
        fini = false;
        do
        {
            pos = ligne.find(a_rechercher.data());
            if (pos != ligne.npos)
            {
                ligne.replace(pos, a_remplacer.length(), a_remplacer.data());
                nbr += 1;
            }
            else
            {
                fini = true; // Indique qu'il n'y a plus d'occurence
            }
        } while(! fini); // on remplace tant qu'une occurence existe
        fdestination << ligne << endl;
    }
    while (! fsource.eof());

    fsource.close();
    fdestination.close();
    return nbr;
}

bool demandeOuiNon(string question)
{
    char reponse;
    cout << question;
    cin >> reponse;
    cin.ignore();
    if ((reponse == 79) || (reponse == 111)) return true;
    return false;
}

