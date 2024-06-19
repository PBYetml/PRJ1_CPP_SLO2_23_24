//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: ConversionNum.cpp
// Date de cr�ation 	: 21.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
// Modifications		: M�lissa Perret
// 
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques			:        
//----------------------------------------------------------------------------------//

//-- librairie standart --// 

								// pour les objets de type chaine de caract�re 
#include <iostream>				// pour les m�thode cin et cout
#include <string>				// pour la m�thode conversion binaire

//-- librairie personnelle --// 
#include "ConversionBCD.h"
#include "ConversionNum.h"

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionBCD 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surcharg� - il faut d�finir le constructeur 
//						  par d�faut + ajouter le lien de au constructeur parent !!!
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD() : ConversionNumerique() //Constructeur par d�faut appelant le constructeur de la class parent
{
}


//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionBCD 
// Entr�e				: choixCodage	-> entier	-> enum�ration : e_codageBinaire
//						  valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				:  
// Description			: constructeur surcharg� 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD(e_codageBinaire choixCodage, float valUser)
{
	if (choixCodage == BCD)
	{
		CalculerNbrDigitEntier(valUser);

		//-- cr�ation d'un tableau dynamique via pointeur --// 
		m_ptTbDigitEntier = new char[m_nbrDigitMaxValEntier];

		RecupererDigitEntier(valUser);
		ConversionBinaire();
	}
}

//-- appel fonction : d�termine le nb de digit du nombre entier --//


//-- appel fonction : r�cuperation de chaque digit --//


//-- appel fonction : conversion binaire de chaque digit entier --// 



//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ~ConversionBCD 
// Entr�e				: 
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
// Nom de la m�thode	: CalculerNbrDigitEntier 
// Entr�e				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: d�termine le nb de digit d'un nombre entier 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::CalculerNbrDigitEntier(float valUser)  //Impl�mentation de la fonction CalculerNbrDigitEntier de la classe ConversionBCD
{
	//-- d�claration de variables --// 
	char compteurBoucle = 0;
	int valEntiere = (int)valUser;


	while (valEntiere != 0)
	{
		valEntiere /= 10;   //valEntiere = valEntiere/10;
		compteurBoucle++;
	}

	m_nbrDigitMaxValEntier = compteurBoucle; //m_nbrDigitMaxValEntier contient le nombre de chiffre que l'utilisateur rentre
}



//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re
//-- fin de boucle -> �gal � 0

		//-- division de la valeur enti�re par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur enti�re

		//-- MAJ du Digit => incr�ment de 1 --//
		//-- MAJ du membre parents -> nbrDigitEntier 





//----------------------------------------------------------------------------------//
// Nom de la m�thode	: RecupererDigitEntier 
// Entr�e				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: d�termine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::RecupererDigitEntier(float valUser)
{
	//-- d�claration variable --// 
	int diviseur;
	int chiffre;
	int indexChiffre;

	//-- it�ration pour remplire le tableau de digit --//
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
// Nom de la m�thode	: ConversionBinaire
// Entr�e				: 
// Sortie				: 
// in-out				: 
// Description			: convertir un valeur d�cimale selon les attributs de la 
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


//-- d�claration de variable --//

//-- boucle d'it�ration pour pour chaque digit --// 

//-- r�cup�re la valeur du digit � convertir --// 


//-- it�ration de conversion binaire --// 	

//-- conversion binaire -> modulo 2 (r�cup�re le reste) --//


//-- MAJ de la valeur � convertir --// 


//-- MAJ du tabelau string --// 

