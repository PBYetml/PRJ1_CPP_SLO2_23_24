//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionNum.cpp
// Date de création 	: 21.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
// Modifications		: Mélissa Perret
// 
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			:        
//----------------------------------------------------------------------------------//

//-- librairie standart --// 

								// pour les objets de type chaine de caractère 
#include <iostream>				// pour les méthode cin et cout
#include <string>				// pour la méthode conversion binaire

//-- librairie personnelle --// 
#include "ConversionBCD.h"
#include "ConversionNum.h"

//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBCD 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surchargé - il faut définir le constructeur 
//						  par défaut + ajouter le lien de au constructeur parent !!!
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD() : ConversionNumerique() //Constructeur par défaut appelant le constructeur de la class parent
{
}


//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBCD 
// Entrée				: choixCodage	-> entier	-> enumération : e_codageBinaire
//						  valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				:  
// Description			: constructeur surchargé 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD(e_codageBinaire choixCodage, float valUser)
{
	if (choixCodage == BCD)
	{
		CalculerNbrDigitEntier(valUser);

		//-- création d'un tableau dynamique via pointeur --// 
		m_ptTbDigitEntier = new char[m_nbrDigitMaxValEntier];

		RecupererDigitEntier(valUser);
		ConversionBinaire();
	}
}

//-- appel fonction : détermine le nb de digit du nombre entier --//


//-- appel fonction : récuperation de chaque digit --//


//-- appel fonction : conversion binaire de chaque digit entier --// 



//----------------------------------------------------------------------------------//
// Nom de la méthode	: ~ConversionBCD 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::~ConversionBCD()
{

}


//----------------------------------------------------------------------------------//
// Nom de la méthode	: CalculerNbrDigitEntier 
// Entrée				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: détermine le nb de digit d'un nombre entier 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::CalculerNbrDigitEntier(float valUser)  //Implémentation de la fonction CalculerNbrDigitEntier de la classe ConversionBCD
{
	//-- déclaration de variables --// 
	char compteurBoucle = 0;
	int valEntiere = (int)valUser;


	while (valEntiere != 0)
	{
		valEntiere /= 10;   //valEntiere = valEntiere/10;
		compteurBoucle++;
	}

	m_nbrDigitMaxValEntier = compteurBoucle; //m_nbrDigitMaxValEntier contient le nombre de chiffre que l'utilisateur rentre
}



//-- itération pour connaitre le nbr de digit sur une valeur entière
//-- fin de boucle -> égal à 0

		//-- division de la valeur entière par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur entière

		//-- MAJ du Digit => incrément de 1 --//
		//-- MAJ du membre parents -> nbrDigitEntier 





//----------------------------------------------------------------------------------//
// Nom de la méthode	: RecupererDigitEntier 
// Entrée				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: détermine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::RecupererDigitEntier(float valUser)
{
	//-- déclaration variable --// 
	int diviseur;
	int chiffre;
	int indexChiffre;

	//-- itération pour remplire le tableau de digit --//
	for (indexChiffre = 0; indexChiffre < m_nbrDigitMaxValEntier; indexChiffre++)
	{
		diviseur = pow(10, (m_nbrDigitMaxValEntier - (indexChiffre + 1)));
		chiffre = valUser / diviseur;
		m_ptTbDigitEntier[indexChiffre] = chiffre;
		valUser = valUser - (chiffre * diviseur);
	}
}


//-- MAJ facteur de puissance de 10 --// 


//-- MAJ TAbleau -> digit 


//-- MAJ valeur utilisateur 


//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBinaire
// Entrée				: 
// Sortie				: 
// in-out				: 
// Description			: convertir un valeur décimale selon les attributs de la 
//						  la classe parent 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::ConversionBinaire()
{
	const int caractereParChiffre = 4;
	//125  0001 0010 0101
	//14 = (3*4)+2

	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	m_ptTbBinaire = new std::string[m_nbrDigitMaxValEntier];

	for (int i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		int chiffre = m_ptTbDigitEntier[i];

		while (chiffre != 0)
		{
			int bit = chiffre % 2;
			m_ptTbBinaire[i] = m_ptTbBinaire[i] + std::to_string(bit);
			chiffre = chiffre / 2;
		}

	}

}


//-- déclaration de variable --//

//-- boucle d'itération pour pour chaque digit --// 

//-- récupère la valeur du digit à convertir --// 


//-- itération de conversion binaire --// 	

//-- conversion binaire -> modulo 2 (récupère le reste) --//


//-- MAJ de la valeur à convertir --// 


//-- MAJ du tabelau string --// 

