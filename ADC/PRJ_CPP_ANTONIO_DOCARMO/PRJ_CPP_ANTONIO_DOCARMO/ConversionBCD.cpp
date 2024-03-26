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

#include <string>								// pour les objets de type chaine de caractère 
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
	//Ne fait rien
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
int ConversionBCD(float valUser, ConversionNumerique::e_codageBinaire choixCodage)
{

	//-- test le choixCodage correspond à l'énumération BCD 
	if (choixCodage == ConversionNumerique:e_codageBinaire : BCD)
	{
		//-- création d'un tableau dynamique via pointeur --// 
		new tabDyn[m_ptTbDigitEntier];

		//-- appel fonction : détermine le nb de digit du nombre entier --//
		ConversionBCD.CalculerNbrDigitEntier(valUser);

		//-- appel fonction : récuperation de chaque digit --//
		ConversionBCD.RecupererDigitEntier(valUser);

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
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::~ConversionBCD()
{
	//Ne fait rien
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
	int nbDeDigit = 0;
	int index;
	

	//-- itération pour connaitre le nbr de digit sur une valeur entière
	for (index = 10; index > 0; index++)
	{
		//-- division de la valeur entière par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		valUser = valUser / (10^index);

		//-- et MAJ de la valeur entière


		//-- MAJ du Digit => incrément de 1 --//

		nbDeDigit++;

	}
	//-- fin de boucle -> égal à 0


		



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
void ConversionBCD::RecupererNbDigitEntier(float valUser)
{
	//-- déclaration variable --// 


	//-- itération pour remplire le tableau de digit --//


		//-- MAJ facteur de puissance de 10 --// 


		//-- MAJ TAbleau -> digit 


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
	new m_ptTbDigitEntier[];
	new m_ptTbBinaire[];
	const short VAL_MAX = 10; //valeur choisie au bol pour l'exemple
	int index;

	//-- déclaration de variable --//


	//-- boucle d'itération pour pour chaque digit --//
	for (index = 0; index < VAL_MAX; index++)
	{
		//-- récupère la valeur du digit à convertir --// 
		

		//-- itération de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (récupère le reste) --//
			

			//-- MAJ de la valeur à convertir --// 
			

			//-- MAJ du tabelau string --// 
	}
}