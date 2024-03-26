//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionBCD.h
// Date de création 	: 11.03.2024
// Date de modification : 25.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			: si héritage <=> attention la visibilité de la class parent 
//						  doit aussi figurer !!!          
//----------------------------------------------------------------------------------//
#ifndef CONV_BCD
#define CONV_BCD

//-- librairie standart --//

#include <iostream>

//-- librairie personnelle --// 
#include "ConversionNum.h"


class ConversionBCD 
{
		

		//-- attribut --// 
		//-> visibilité 
		//--> public
		public: 

			ConversionNumerique::e_codageBinaire choixCodage;		//choixCodage de type e_codageBinaire
			new tabDyn[m_ptTbDigitEntier];
			
			//new tbDyn[m_nbrDigitMMaxValEntier];		//Pas au bon endroit

		//--> protected 
		//--> private 
		private:

			float valUser;		//valUser de type float


		//-- prototype -> constructeur --//
		//-> visibilité 
		//--> public
		public:

			ConversionBCD(); //Constructeur gérite de ConversionNumerique
		//--> protected 
		//--> private 

		

		

		



		//-- prototype -> destructeur --//
		//-> visibilité 
		//--> public
		 public:
			 ~ConversionBCD();

		//--> protected 
		//--> private 



		//-- prototype -> méthode --//
		//-> visibilité 
		//--> public 
		 public:
			 void CalculerNbrDigitEntier(float valUser);	//Declaration methode CalculerNbrDigitEntier paramètre valUser
			 void RecupererNbDigitEntier(float valUser);	//Declaration methode RecupererNbDigitEntier paramètre valUser
			 void ConversionBinaire(void);
			 ConversionBCD(float valUser, ConversionNumerique::e_codageBinaire choixCodage);
			 
		//--> protected
		//--> private
		private:

			







};

#endif // !CONV_NUM


