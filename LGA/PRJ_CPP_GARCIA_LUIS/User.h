//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: User.h
// Date de création 	: 08.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			:            
//----------------------------------------------------------------------------------//
#ifndef CLASS_USER
#define CLASS_USER 

#include "ConversionNum.h"

class user
{
	//-- attribut --// 
	//-> visibilité 
	public : 
		enum e_MsgInfo : int {message1, message2, message3, message4};		
		ConversionNumerique* pt_ObjetConversion;							//-- objet de conversion 
	
	protected :  
		float valUser_m;

	private : 
		const short CST_VAL_LIMIT_MAX; 
		const short CST_VAL_LIMIT_MIN; 


	//-- prototype -> constructeur 
	//-> visibilité 
	public : 
		user(short limitmax, short limitmin); 
	
	//-- prototype -> méthode --//
	//-> visibilité 
	public :
		void AfficherMsgUser(e_MsgInfo msg);							// affichage de différents msg à l'utilisateur 
		void AfficherValConvertie(ConversionNumerique *objAConvertir);	// affiche la valeur de conversion numérique selon les paramètres de l'utilisateur 
		float GetNumberValue();											// prend un valeur (attribut) pour la donner à l'extérieur 
		float SetNumberValue();											// récupère une valeur numérique (entier ou réel) de l'extérieur 
		bool ValiderValUser(float valATester);							// valide une valeur numérique (selon CDC)

};



#endif // !CLASS_USER
