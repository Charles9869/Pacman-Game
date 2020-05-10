// Nom du ficher: Pacman.h //
// Charles Bertrand //
// Date de cr�ation: 14 D�cembre 2017 //
// Tous les prototypes de mes fonctions et proc�dures ainsi que les structures et les constantes pour le bon fonctionnement du jeu //

#ifndef PACMAN_H
#define PACMAN_H
#include "sdlclg.h"

// D�claration des constantes requises pour le Jeu //
const int Largeur = 19;
const int Hauteur = 21;
const int NbPixelsParCase = 24;
const int VitesseFantome = 10; // Bougent � tous les 10 tours //
const int TempsFruit = 100;

// Chaque lettre dans cette �num�ration repr�sente une case dans la carte //
enum Objet { V, M, P, PW, F, B};
enum OrientationImage { Right, Left, Up, Down }; // Va servir � orienter l'image de Pacman vers le bon c�t� 

// Structure Position contenant les Positions et AnciennePositions //
struct Position
{
	int x;
	int y;
	int X; // Ancienne Position X//
	int Y; // Ancienne Position Y //
};

// Structure pour les images //
struct ImageJeu
{
	ImageId ImageShadow, ImageSpeedy, ImageBashful, ImagePokey;
	ImageId ImageMur, ImageReady, ImagePeur, ImagePower, ImageGagne, ImagePerdu, ImagePoint, ImageFeu;
	ImageId ImageCerise, ImageOrange, ImageFraise, ImagePomme;
	ImageId ImageWhite, ImagePoint200;
};

// Strcuture pour les 4 images de Pacman //
struct ImageDirection
{
	int Droite, Gauche, Haut, Bas;
};

// Structure pour le type de fruit //
enum TypeFruit
{
	Fraise, Cerise, Orange, Pomme
};

// But: Gerer l'apparition des fruits //
// Prototype: void GererFruit(int& CompteurFruit, Objet Tableau[][Largeur], int Hauteur, Position Pacman, ImageJeu Jeu, TypeFruit& Fruit, int& FruitRandom) //
// Intrants: CompteurFruit, Tableau, Hauteur, Position de Pacman, ImageJeu du Jeu, Type de Fruit, FruitRandom //
// Extrants: Aucun //
// Type: Proc�dure //
void GererFruit(int& CompteurFruit, Objet Tableau[][Largeur], int Hauteur, Position& Pacman, ImageJeu Jeu, TypeFruit& Fruit, int& FruitRandom);

// But: Aafiche Pacman dans la bonne direction //
// Prototype: void AfficherPacmanDirection(OrientationImage& Direction, Position Pacman, ImageDirection ImagePacman) //
// Intrants: Orientation de Pacman, Pacman, structure ImageDirection de Pacman //
// Extrants: Aucun //
// Type: Proc�dure //
void AfficherPacmanDirection(OrientationImage& Direction, Position Pacman, ImageDirection ImagePacman);

// But: Permet de faire bouger Pacman selon des conditions //
// Prototypes: void MouvementPacman(Position& Pacman, Objet Tableau[][Largeur], int Hauteur, int& Touche, OrientationImage& Direction) //
// Intrants: Pacman, Tableau, Hauteur, Touche, Orientation de Pacman //
// Extrants: Aucun //
// Type: Proc�dure //
void MouvementPacman(Position& Pacman, Objet Tableau[][Largeur], int Hauteur, int& Touche, OrientationImage& Direction);

// But: Affiche la carte du jeu //
// Prototype: void AfficherCarte(Objet Tableau[][Largeur], int Hauteur, ImageJeu Jeu, int& Score) //
// Intrants: Tableau, Hauteur, ImageJeu qui contient tous les images, Score, Type de Fruit //
// Extrants: Aucun //
// Type: Proc�dure //
void AfficherCarte(Objet Tableau[][Largeur], int Hauteur, ImageJeu Jeu, int& Score, TypeFruit& Fruit);

// But: Permet de faire bouger les fant�me en haut //
// Prototype: void MouvementHaut(Position& Fantome) //
// Intrants: Position Fantome //
// Extrants: Aucun //
// Type: Proc�dure //
void MouvementHaut(Position& Fantome);

// But: Permet de faire bouger les fant�me bas //
// Prototype: void MouvementBas(Position& Fantome) //
// Intrants: Position Fantome //
// Extrants: Aucun //
// Type: Proc�dure //
void MouvementBas(Position& Fantome);

// But: Permet de faire bouger les fant�me � droite //
// Prototype: void MouvementDroite(Position& Fantome) //
// Intrants: Position Fantome //
// Extrants: Aucun //
// Type: Proc�dure //
void MouvementDroite(Position& Fantome);

// But: Permet de faire bouger les fant�me � gauche //
// Prototype: void MouvementGauche(Position& Fantome) //
// Intrants: Position Fantome //
// Extrants: Aucun //
// Type: Proc�dure //
void MouvementGauche(Position& Fantome);

// But: Selon la touche appuy�, il appelle la fonction qui fait d�placer le Pacman //
// Prototype: void GererKeyEvent(int& KeyEvent, Objet Tableau[][Largeur], int Hauteur, bool& Fermer, Position& Pacman, OrientationImage& Direction) //
// Intrants: KeyEvent, Tableau d'Objet, Hauteur, Fermer, la Position de Pacman, Structure Direction //
// Extrants: Aucun //
// Type: Proc�dure //
void GererKeyEvent(int& KeyEvent, Objet Tableau[][Largeur], int Hauteur, bool& Fermer, Position& Pacman, OrientationImage& Direction);

// But: Proc�dure qui permet d'enlever les points lorsque Pacman passe dessus et les manges //
// Prototype: void PacmanMangerObjet(int &Score, Objet Tableau[][Largeur], int Hauteur, Position Pacman, int& CompteurFruit, int& NombrePoint) //
// Intrants: Score, Tableau d'Objet, Hauteur, Position de Pacman, CompteurFruit, NombrePoint //
// Extrants: Aucun //
// Type: Aucun //
void PacmanMangerObjet(int &Score, Objet Tableau[][Largeur], int Hauteur, Position Pacman, int& CompteurFruit, int& NombrePoint);

// But: Permet d'afficher le Pacman et les fant�mes avant que la partie commence //
// Prototype: void AvantPartie(ImageJeu Jeu, Position Pacman, Position Pokey, Position Speedy, Position Shadow, Position Bashful, ImageDirection ImagePacman) //
// Intrants: Structure Jeu, Position Pacman, Pokey, Speedy, Shadow, Bashful, Direction de l'image de Pacman //
// Extrants: Aucun //
// Type: Proc�dure //
void AvantPartie(ImageJeu Jeu, Position Pacman, Position Pokey, Position Speedy, Position Shadow, Position Bashful, ImageDirection ImagePacman);

// But: Permet de d�marrer le Compteur et faire d�placer les fant�me soit en Chasseur ou en Random //
// Prototype: void DemarrerCompteur(int& Compteur, int& NombreRandom, Objet Tableau[][Largeur], int Hauteur, Position& Pacman, Position& Pokey, Position& Shadow, Position& Bashful, Position& Speedy, int& Fuite) //
// Intrants: Compteur, NombreRandom, Tableau, Hauteur, Position Pacman, Pokey, Shadow, Bashful, Speedy, Fuite //
// Extrants: Aucun //
// Type: Proc�dure //
void DemarrerCompteur(int& Compteur, int& NombreRandom, Objet Tableau[][Largeur], int Hauteur, Position& Pacman, Position& Pokey, Position& Shadow, Position& Bashful, Position& Speedy, int& Fuite);

// But: Permet de v�rifier si Pacman est mang� //
// Prototype: void VerifierPacmanMange(bool& PacmanMort, Position Pacman, Position& Pokey, Position& Shadow, Position& Bashful, Position& Speedy) //
// Intrants: PacmanMort, Position de Pacman, Pokey, Shadow, Bashful, Speedy //
// Extrants: Aucun //
// Type: Proc�dure //
void VerifierPacmanMange(int Fuite, bool& PacmanMort, Position Pacman, Position& Pokey, Position& Shadow, Position& Bashful, Position& Speedy);

// But: Permet de v�rifier si gagne ou perdu //
// Prototype: void VerifierGagne(bool Fermer, int Score, ImageJeu Jeu) //
// Intrants: Fermer, Score, structure ImageJeu contenant toutes les images, NombrePoint //
// Extrants: Aucun //
// Type: Proc�dure //
void VerifierGagne(bool Fermer, int Score, ImageJeu Jeu, int NombrePoint);

// But: Affiche Pacman lorsqu'il gagne la partie //
// Prototype: void AfficherPacmanGagne(Position Pacman, ImageJeu Jeu, OrientationImage Direction, ImageDirection ImagePacman) //
// Intrants: Position Pacman, structure ImageJeu, Direction qui permet d'afficher Pacman du bon c�t�, structure contenant les quatres images de Pacman //
// Extrants: Aucun //
// Type: Proc�dure //
void AfficherPacmanGagne(Position Pacman, ImageJeu Jeu, OrientationImage Direction, ImageDirection ImagePacman);

// But: Mouvement de Pokey et Bashful //
// Prototype: void FantomeNonChasseur(Position& Fantome, Objet Tableau[][Largeur], int Hauteur, int& NombreRandom) //
// Intrants: Position Fantome, Tableau, Hauteur, NombreRandom //
// Extrants: Aucun //
// Type: Proc�dure //
void FantomeNonChasseur(Position& Fantome, Objet Tableau[][Largeur], int Hauteur, int& NombreRandom);

// But: Mouvement de Shadow et Speedy //
// Prototype: void FantomeChasseur(Position& Fantome, Position Pacman, Objet Tableau[][Largeur], int Hauteur, int& NombreRandom) //
// Intrants: Position Fantome, Pacman, Tableau, Hauteur, NombreRandom //
// Extrants: Aucun //
// Type: Proc�dure //
void FantomeChasseur(Position& Fantome, Position Pacman, Objet Tableau[][Largeur], int Hauteur, int& NombreRandom);

// BUt: Permet de faire bouger les fant�mes en mode fuite //
// Prototype: void FantomeFuite(int NombreRandom, Position& Fantome, Position Pacman, Objet Tableau[][Largeur], int Hauteur) //
// Intrants: NombreRandom, Position Fantome, Pacman, Tableau, Hauteur //
// Extrants: Aucun //
// Type: Proc�dure //
void FantomeFuite(int NombreRandom, Position& Fantome, Position Pacman, Objet Tableau[][Largeur], int Hauteur);

// But: D�marre le mode fuite //
// Prototype: void DemarrerFuite(Objet Tableau[][Largeur], int Hauteur, Position& Pacman, int& Fuite) //
// Intrants: Tableau, Hauteur, Position Pacman, Fuite //
// Extrants: Aucun //
// Type: Proc�dure //
void DemarrerFuite(Objet Tableau[][Largeur], int Hauteur, Position& Pacman, int& Fuite);

// But: Affiche les Fant�mes � la fin de la partie //
// Prototype: void AfficherFinPartie(ImageJeu Jeu, Position Pokey, Position Speedy, Position Bashful, Position Shadow) //
// Intrants: Structure ImageJeu, Position Pokey, Speedy, Bashful, Shadow //
// Extrants: Aucun // 
// Type: Proc�dure //
void AfficherFinPartie(ImageJeu Jeu, Position Pokey, Position Speedy, Position Bashful, Position Shadow);

// But: Affiche les fant�mes en mode normal ou en mode fuite //
// Prototype: void AfficherFantome(int Fuite, ImageJeu Jeu, Position Speedy, Position Pokey, Position Bashful, Position Shadow, Objet Tableau[][Largeur], int Hauteur) //
// Intrants: Fuite, ImageJeu, Position Speedy, Pokey, Bashful, Shadow, Tableau, Hauteur //
// Extrants: Aucun //
// Type: Proc�dure //
void AfficherFantome(int Fuite, ImageJeu Jeu, Position Speedy, Position Pokey, Position Bashful, Position Shadow, Objet Tableau[][Largeur], int Hauteur);

// But: Affiche le score final � la fin de la partie //
// Prototype: void AfficherResultat(int NombrePoint) //
// Intrants: NombrePoint //
// Extrants: Aucun //
// Type: Proc�dure //
void AfficherResultat(int NombrePoint);
#endif