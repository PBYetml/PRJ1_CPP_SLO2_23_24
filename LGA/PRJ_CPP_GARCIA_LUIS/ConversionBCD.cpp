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
#include <bitset>
#include <cmath>
#include <string>

								// pour les objets de type chaine de caractère 
#include <iostream>				// pour les méthode cin et cout

//-- librairie personnelle --// 
#include "ConversionBCD.h"


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
	if (choixCodage == BCD)
	{
		//-- création d'un tableau dynamique via pointeur --//
		m_ptTbDigitEntier = new char[m_nbrDigitMaxValEntier];

		//-- appel fonction : détermine le nb de digit du nombre entier --//
		ConversionBCD::CalculerNbrDigitEntier(valUser);

		//-- appel fonction : récuperation de chaque digit --//
		ConversionBCD::RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		ConversionBCD::ConversionBinaire();
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
	int valUserEntier;
	int result;

	valUserEntier = (int)valUser;


	//-- itération pour connaitre le nbr de digit sur une valeur entière
	do
	{
		result = (valUserEntier % 10);
		if (result != 0)
		{
			valUserEntier = valUserEntier / 10;
			ConversionBCD::m_nbrDigitMaxValEntier++;
		}

	} while (result != 0);
	//-- fin de boucle -> égal à 0


		//-- division de la valeur entière par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur entière

		//-- MAJ du Digit => incrément de 1 --//
		//-- MAJ du membre parents -> nbrDigitEntier 
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
	int index = 0;
	int valEnEntier = (int)valUser;

	//-- itération pour remplire le tableau de digit --//
	for (int i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//-- MAJ facteur de puissance de 10 
		//-- MAJ TAbleau -> digit 
		m_ptTbDigitEntier[index] = (valEnEntier / pow(10, i));
	}
		//-- MAJ valeur utilisateur 
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
void ConversionBCD::ConversionBinaire(void)
{
	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	m_ptTbBinaire = new std::string[m_nbrDigitMaxValEntier];
	std::string digitConvert;

	//-- déclaration de variable --//
	char digit = 0, digitToConvert = 0;
	bool flagEndCoonvert = false;

	//-- boucle d'itération pour pour chaque digit --// 
	do
	{
		digit = m_ptTbDigitEntier[digitToConvert];

		std::bitset<8> digit;
		digitToConvert++;

		if (digitToConvert == m_nbrDigitMaxValEntier)
		{
			flagEndCoonvert = true;
		}

	} while (flagEndCoonvert == false);

		//-- récupère la valeur du digit à convertir --// 


		//-- itération de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (récupère le reste) --//


			//-- MAJ de la valeur à convertir --// 


			//-- MAJ du tabelau string --// 

}

