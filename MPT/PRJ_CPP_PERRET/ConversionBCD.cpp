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

ConversionBCD::ConversionBCD()
{
	if (choixCodage == BCD)
	{
		int* m_ptTbDigitEntier[] = { 0 };
		int* m_nbrDigitMaxValEntier[] = { 0 };

		CalculerNbrDigitEntier(valUser);
		RecupererDigitEntier(valUser);
		ConversionBinaire(valUser);
	}
	std::cout << "Constructeur de Rectangle" << std::endl;
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

void ConversionBDC()
{
	int tbdynamique[100] = { 0 };
	//-- test le choixCodage correspond à l'énumération BCD 
	if (choixCodage = BCD)
	{
		

	}
}
		//-- création d'un tableau dynamique via pointeur --// 
	
	
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


	//-- déclaration de variables --// 
	void ConversionNumerique(float valUser)
	{
		while (valUser != 0)
		{

		}

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
void RecupererDigitEntier(float valUser)
{
	int i;
	int taille = 0; 

	while (valUser != 0)
	{
		if (isdigit(valUser))
		{
			std::cout << "";
		}
	}
}

//-- déclaration variable --// 

	 
	//-- itération pour remplire le tableau de digit --//

	 
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

void ConversionBinaire(int valAConv, char(&ptTbDigitEntier)[100])
{
	char binaireInverse[100] = { 0 } // binaireInverse: 00000 0000
	int index = 0;

		// commentaires: example pour valAConv = 6
		while (valAConv != 0)
		{
			binaireInverse[index] = valAConv % 2;  //octal modulo 8

			valAConv = valAConv >> 1;  // divison par deux
			//valAConv = valAConv / 2; // version alternative  //octal division par 8

			index++;
		}

	std::string binaire = ""; // Initialisez une chaîne de caractères pour stocker le résultat binaire

			
