//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionNum.h
// Date de création 	: 11.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			:            
//----------------------------------------------------------------------------------//
#ifndef CONV_NUM
#define CONV_NUM

//-- librairie standart --//
#include <string>

class ConversionNumerique
{
	//-- attribut --// 
	//-> visibilité 
	public :
		enum e_codageBinaire : char { BINAIRE, BCD, AIKEN };

	protected :
		char m_nbrDigitMaxValEntier; 
		char *m_ptTbDigitEntier; 
		std::string* m_ptTbBinaire;

	//-- prototype -> constructeur --//
	//-> visibilité 
	public : 
		ConversionNumerique(); 
		ConversionNumerique(e_codageBinaire choixCodage, float valUser); 


	//-- prototype -> destructeur --//
	//-> visibilité 
	public : 
		virtual ~ConversionNumerique();



	//-- prototype -> méthode --//
	//-> visibilité 
	public : 
		std::string* GetValeurConvertie(); 
		char GetNbrDigitEntier(); 

	protected :
		virtual void CalculerNbrDigitEntier(float valUser); 
		virtual void RecupererDigitEntier(float valUser); 
};


#endif // !CONV_NUM

