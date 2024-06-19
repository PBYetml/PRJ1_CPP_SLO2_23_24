//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: user.cpp
// Date de cr�ation 	: 08.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques			: conversion string en float 
//						  https://cplusplus.com/reference/string/stof/           
//----------------------------------------------------------------------------------//

//-- librairie standart --// 
#include <iostream>		//-- utilisation des entr�es / sorties 
#include <string>		

//-- librairie personnelle --// 
#include "User.h"

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: user - ATTENTION -> constructeur
// Entr�e				: limitmax	-> entier	-> 16bits 
//						  limitmin	-> entier	-> 16bits 
// Sortie				: -
// in-out				: - 
// Description			: permet d'afficher diff�rents msg selon le choix de 
//						  l'utilsateur 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
user::user(short limitmax, short limitmin) : CST_VAL_LIMIT_MAX(limitmax), CST_VAL_LIMIT_MIN(limitmin)
{
	// ne fait rien juste � initialiser les cst li� � l'objet
}


//----------------------------------------------------------------------------------//
// Nom de la m�thode	: AfficherMsgUser
// Entr�e				: msg	-> enum�ration	-> e_MsgInfo (class User) 
// Sortie				: -
// in-out				: - 
// Description			: permet d'afficher diff�rents msg selon le choix de 
//						  l'utilsateur 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void user::AfficherMsgUser(user::e_MsgInfo msg)
{
	//-- d�claration variable --// 

	//-- condition d'affichage --// 
	//-> switch case 
	switch (msg)
	{
		//-- msg 1 : 
	case user::e_MsgInfo::message1:
		std::cout << "Inserez un nombre (ex: 3.00)  : ";
		break;
	case user::e_MsgInfo::message2:
		std::cout << "!! Erreur !! -> valeur hors limite" << std::endl;
		break;
	case user::e_MsgInfo::message3:
		std::cout << "!! Erreur !! -> valeur enti�re " << std::endl;
		break;
	default:
		break;
	}
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: GetNumberValue
// Entr�e				: -
// Sortie				: valUser_m -> reel -> attribut priv� 
// in-out				: - 
// Description			: permet d'obtenir un attribut specifique de la class USER
// Date modfification	: le 19.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
float user::GetNumberValue()
{
	return valUser_m;
}







//----------------------------------------------------------------------------------//
// Nom de la m�thode	: SetNumberValue
// Entr�e				: -
// Sortie				: -
// in-out				: - 
// Description			: r�cup�re une valeur num�rique (entier ou r�el) 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
float user::SetNumberValue()
{
	//-- d�claration variables --// 
	float valConvReel;

	//-- d�claration d'objet --//
	std::string valUser;

	//-- r�cup�ration info clavier -> string --// 
	std::cin >> valUser;

	//-- conversion string en float --// 
	valConvReel = std::stof(valUser);

	//-- retour de la valeur de l'utilisateur --// 
	return valConvReel;
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ValiderValUser
// Entr�e				: valATester	-> reel		-> 4bytes
// Sortie				: checkValeur	-> entier	-> vrai / faux 
// in-out				: - 
// Description			: 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
bool user::ValiderValUser(float valATester)
{
	//-- d�claration de variable --//
	bool checkValeur = false;

	float difference;

	//-- test si valATester dans les limites --// 
	if ((valATester < CST_VAL_LIMIT_MAX) && (valATester >= CST_VAL_LIMIT_MIN))
	{
		//-- calcul pour savoir si il y a une diff�rence entre valeur r�elle et enti�re 
		difference = valATester - (int)valATester;

		//-- test si valeur est enti�re 
		if (difference == (float)0.0)
		{
			checkValeur = true;
			valUser_m = valATester;
		}
		else
		{
			//-- message user : non r�el 
			this->AfficherMsgUser(e_MsgInfo::message3);
			checkValeur = false;
		}
	}
	else
	{
		//-- message user : hors l�mit 
		this->AfficherMsgUser(e_MsgInfo::message2);
		checkValeur = false;
	}

	return checkValeur;
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: AfficherValConvertie
// Entr�e				: objAConvertir ->	ConversionNumerique	-> objet 
// Sortie				: 
// in-out				: - 
// Description			: 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void user::AfficherValConvertie(ConversionNumerique* objAConvertir)
{
	//-- d�lcaration variable --// 
	char iteration = 0;
	char iterationDigit = '0';
	char digit;

	//-- d�claration objet --// 
	std::string* valeurAfficher;

	//-- r�cup�ration chaine de caract�re � afficher --// 
	valeurAfficher = objAConvertir->GetValeurConvertie();

	//-- msg user --// 
	std::cout << " valeur BCD : ";

	//-- affichage de la valeur binaire dans le bon sens --//
	//-- iteration 
	for (iteration = 0; iteration < objAConvertir->GetNbrDigitEntier(); iteration++)
	{
		//-- traitement pour chaque chaine de caract�re --// 
		//-- afficher 4 digit --// 
		//-- lecture nbr digit disponible --// 
		digit = valeurAfficher[iteration].length();

		//-- pr�paration de l'affichage pour afficher les z�ro 
		std::cout.width(5 - digit);
		std::cout.fill('0');

		//-- iteration permettant de lire le "LSB" en premier 
		for (digit; digit > 0; digit--)
			std::cout << valeurAfficher[iteration][digit - 1];

		//-- affichage d'une espace 
		std::cout << " ";
	}

	//-- retour � la ligne
	std::cout << std::endl;

}
