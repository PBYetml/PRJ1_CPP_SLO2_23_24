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

#include <string>				// pour les objets de type chaine de caractère 
#include <iostream>				// pour les méthode cin et cout
#include <bitset>				// pour le tableau binaire

//-- librairie personnelle --// 
#include "ConversionBCD.h"

//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBCD 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur 
// Date modfification	: le 26.03.2024 
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
// Date modfification	: le 26.03.2024 
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
		CalculerNbrDigitEntier(valUser);

		//-- appel fonction : récuperation de chaque digit --//
		RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		ConversionBinaire();
	}
}


//----------------------------------------------------------------------------------//
// Nom de la méthode	: ~ConversionBCD 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur 
// Date modfification	: le 26.03.2024 
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
// Date modfification	: le 26.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::CalculerNbrDigitEntier(float valUser)
{
	//-- déclaration de variables --// 
	char countDigits = 0;	// Variable de comptage du nombre d'itération de la boucle
	int valUserEntier = (int) valUser;	// Valeur entière de valUser

	//-- itération pour connaitre le nbr de digit sur une valeur entière
	//-- fin de boucle -> égal à 0
	/*for (i = 10; i = 0; i--)*/
	while (valUserEntier > 0)
	{
		//-- division de la valeur entière par 10
		//-- et MAJ de la valeur entière
		valUserEntier = valUserEntier / 10;

		//-- MAJ du Digit => incrément de 1 --//
		countDigits++;

	} ;

	//-- MAJ du membre parents -> nbrDigitEntier 
	m_nbrDigitMaxValEntier = countDigits;
}


//----------------------------------------------------------------------------------//
// Nom de la méthode	: RecupererDigitEntier 
// Entrée				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: détermine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 26.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::RecupererDigitEntier(float valUser)
{
	//-- déclaration variable --// 
	char i = 0;	// Variable de comptage de la boucle
	int valUserEntier = (int)valUser;	// Valeur entière de valUser

	//-- itération pour remplire le tableau de digit --//
	for (i = m_nbrDigitMaxValEntier; i > 0; i--)
	{
		//-- MAJ TAbleau -> digit 
		m_ptTbDigitEntier[m_nbrDigitMaxValEntier - i] = valUserEntier / (10 ^ i); 
	}
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
	m_ptTbBinaire = new std::string[m_nbrDigitMaxValEntier];

	//-- déclaration de variable --//
	char i = 0;	// Variable de comptage de la boucle des digits
	char y = 0;	// Variable de comptage de la boucle de convertion
	char digit = 0;	// Variable de sauvegarde du digit
	std::bitset<1> tb_Bin[4];


	//-- boucle d'itération pour pour chaque digit --// 
	for (i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//-- récupère la valeur du digit à convertir --// 
		digit = m_ptTbDigitEntier[i];

		//-- itération de conversion binaire --// 	
		while (digit > 0)
		{
			//-- conversion binaire -> modulo 2 (récupère le reste) --//
			tb_Bin[y] = digit % 2;

			//-- MAJ de la valeur à convertir --// 
			digit = digit / 2;

			y++;
		}
		//-- MAJ du tabelau string --// 
		m_ptTbBinaire[i] = tb_Bin->to_string();
	}
}