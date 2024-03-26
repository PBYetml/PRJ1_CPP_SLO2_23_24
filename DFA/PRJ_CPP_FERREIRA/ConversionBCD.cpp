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
ConversionBCD::ConversionBCD(ConversionNumerique::e_codageBinaire choixCodage, float valUser)
{
	//-- test le choixCodage correspond à l'énumération BCD 
	if (choixCodage < ConversionNumerique::e_codageBinaire::AIKEN)
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
	int nbrDigitScan = 0;
	int powerScan = 1;
	int inputEntier = valUser;

	//-- itération pour connaitre le nbr de digit sur une valeur entière
	//-- fin de boucle -> égal à 0
	while ((inputEntier / powerScan) > 0)
	{
		//-- division de la valeur entière par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur entière
		powerScan *= 10;

		//-- MAJ du Digit => incrément de 1 --//
		nbrDigitScan++;
	}

	//-- MAJ du membre parents -> nbrDigitEntier
	m_nbrDigitMaxValEntier = nbrDigitScan;
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
	int digitScan = 0;
	int inputEntier = valUser;
	char getDigit = 0;

	//-- itération pour remplire le tableau de digit --//
	while ((inputEntier > 0) && (m_nbrDigitMaxValEntier > digitScan))
	{
		//-- MAJ facteur de puissance de 10 --//
		getDigit = inputEntier % 10;

		//-- MAJ TAbleau -> digit 
		m_ptTbDigitEntier[m_nbrDigitMaxValEntier-digitScan-1] = getDigit;

		//-- MAJ valeur utilisateur
		inputEntier /= 10;
		digitScan++;
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
void ConversionBCD::ConversionBinaire(void)
{
	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	char *m_ptTbBin = new char[m_nbrDigitMaxValEntier];

	//-- déclaration de variable --//
	char getDigit = 0;
	char getDin = 0;
	int BinScan = 0;

	//-- boucle d'itération pour pour chaque digit --// 
	for (int digitScan=0; digitScan < m_nbrDigitMaxValEntier; digitScan++)
	{
		//-- récupère la valeur du digit à convertir --// 
		getDigit = m_ptTbDigitEntier[digitScan];

		//-- itération de conversion binaire --//
		while (getDigit > 0)
		{
			//-- conversion binaire -> modulo 2 (récupère le reste) --//
			if ((getDigit % 10) == 0)
				//-- MAJ du tabelau string --//
				m_ptTbBin[BinScan] = '1';
			else
				//-- MAJ du tabelau string --//
				m_ptTbBin[BinScan] = '0';
			//-- MAJ de la valeur à convertir --//
			BinScan++;
			getDigit /= 10;
		}
	}
	m_ptTbBinaire = new std::string(m_ptTbBin);
}		