//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionNum.cpp
// Date de création 	: 21.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			:        
//----------------------------------------------------------------------------------//

//-- librairie standart --// 

								// pour les objets de type chaine de caractère 
#include <iostream>				// pour les méthode cin et cout
#include "ConversionNum.h"
#include "ConversionBCD.h"

//-- librairie personnelle --// 


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

ConversionBCD::ConversionBCD()
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
	

	//-- test le choixCodage correspond à l'énumération BCD 
	if (choixCodage == 1)
	{
		//-- création d'un tableau dynamique via pointeur --// 
		tabDynamique[0] = ConversionNumerique::m_ptTbDigitEntier;
		*tabDynamique[1] = ConversionNumerique::m_nbrDigitMaxValEntier;

		//-- appel fonction : détermine le nb de digit du nombre entier --//
		ConversionBCD::CalculerNbrDigitEntier(valUser);

		//-- appel fonction : récuperation de chaque digit --//
		ConversionBCD::RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 

		ConversionBCD::ConversionBinaire();
	}
	else
	{

	}

}


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
void ConversionBCD::CalculerNbrDigitEntier(float valUser)
{


	//-- déclaration de variables --// 
	char nombreDigit = 0;
	char valDigit[32];
	char indexDigit = 0;

	//-- itération pour connaitre le nbr de digit sur une valeur entière
	for (indexDigit = 0; indexDigit < valUser; indexDigit++)
	{
		if (valUser != 0)
		{
			valDigit[indexDigit] = valUser;
			//valUser = valUser >> 1;
			nombreDigit++;
		}
	}
	//-- fin de boucle -> égal à 0


		//-- division de la valeur entière par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur entière


		//-- MAJ du Digit => incrément de 1 --//



	//-- MAJ du membre parents -> nbrDigitEntier 
	m_nbrDigitMaxValEntier = nombreDigit;
}



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
	int valDigit = 0;
	char tabValDigit[32];
	char indexValDigit;
	//-- itération pour remplire le tableau de digit --//
	
		//-- MAJ facteur de puissance de 10 --// 


		//-- MAJ TAbleau -> digit 
	

		//-- MAJ valeur utilisateur 
	*tabDynamique[1] = valDigit;
}



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
	
	//-- Creation du tableau dynamique de string en fct des digit entier --// 


	//-- déclaration de variable --//
	char indexConversionBin;

	//-- boucle d'itération pour pour chaque digit --// 

		//-- récupère la valeur du digit à convertir --// 


		//-- itération de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (récupère le reste) --//


			//-- MAJ de la valeur à convertir --// 


			//-- MAJ du tabelau string --// 

}