/*
 Programme : Jeu de l'equipage
 But : Coder l'algorithme du jeu de l'equipage
 Date de derniere modification : 20 octobre 2023
 Auteurs : E. Desessard & E. Hamid
 Remarques : Code conforme aux specifications internes donnees en cours
*/


#include <iostream>

#include "game-tools.h"


using namespace std;



int main()
{

	//VARIABLES

		//Participants

			string nomJoueur; // nom du joueur
			unsigned int scoreJoueur = 0; // score du joueur au long de la partie
			string equipement = "NON_EQUIPE"; // equipement des participants a la partie
			const string NOM_MACHINE = "machine"; // nom de la machine
			unsigned int scoreMachine = 0; // score de la machine au long de la partie

		//Des

			unsigned int valeurBateau; // nombre de points que rapporte l'obtention du bateau
			unsigned int valeurCapitaine; // nombre de points que rapporte l'obtention du capitaine
			unsigned int valeurEquipage; // nombre de points que rapporte l'obtention de l'equipage

			unsigned short int deUn; // valeur du premier de
			unsigned short int deDeux; // valeur du deuxieme de
			unsigned short int deTrois; // valeur du troisieme de
			unsigned short int deQuatre; // valeur du quatrieme de
			unsigned short int deCinq; // valeur du cinquieme de

		//Manches

			unsigned int nombreManches; // nombre de manches dans la partie
			unsigned int numeroManche; // numero de la manche en cours

		//Lancers

			unsigned int scoreLancer = 0; // score du lancer effectue
			const unsigned short int NOMBRE_LANCERS = 3; // nombre de lancers par manche
			unsigned short int numeroLancer = 1; // numero du lancer en cours

		//FinPartie

			string nomVainqueur; // nom du vainqueur de la partie
			string nomPerdant; // nom du perdant de la partie
			unsigned int scoreVainqueur; // score du vainqueur de la partie
			unsigned int scorePerdant; // score du perdant de la partie
			unsigned int scoreEgalite; // score des deux participants en cas d'egalite

			bool etatEgalite=false; // Etat d'egalite de la partie

		//Autres

			char choixParametrerPartie; // choix du joueur pour parametrer la partie
			char choixContinuerPartie = 'o'; // choix du joueur pour continuer la partie
			char choixContinuerLancers = 'o'; // choix du joueur pour continuer les lancers


	// TRAITEMENTS
	 
		// >> initialiserPartie >> nomJoueur, valeurBateau, valeurCapitaine, valeurEquipage, nombreManches
			
			// >> demanderNomJoueur >> nomJoueur
			cout << "Entrez votre nom de joueur : ";
			cin >> nomJoueur;

			// >> proposerParametrerPartie >> choixParametrerPartie
			cout << "Souhaitez-vous parametrer la partie (o/n) ? : ";
			cin >> choixParametrerPartie;

			// choixParametrerPartie >> parametrerPartie >> valeurBateau, valeurCapitaine, valeurEquipage, nombreManches
			switch (choixParametrerPartie)
			{
				
			case 'o' : // l'utilisateur souhaite parametrer la partie
		
				// >> demanderValeurBateau >> valeurBateau
				cout << "Entrez la valeur du bateau : ";
				cin >> valeurBateau;

				// >> demanderValeurCapitaine >> valeurCapitaine
				cout << "Entrez la valeur du capitaine : ";
				cin >> valeurCapitaine;

				// >> demanderValeurEquipage >> valeurEquipage
				cout << "Entrez la valeur de l'equipage : ";
				cin >> valeurEquipage;
			
				// >> demanderNombreManches >> nombreManches
				cout << "Combien de manches souhaitez-vous jouer ? ";
				cin >> nombreManches;

				pause(2);

				break;

			case 'n' : // l'utilisateur ne souhaite pas parametrer la partie

				// affectation des valeurs par defaut
				valeurBateau = 600;
				valeurCapitaine = 500;
				valeurEquipage = 400;
				nombreManches = 5;

				cout << "Les valeurs par defaut ont donc ete affectees : " << endl;
				cout << "Valeur du bateau : " << valeurBateau << endl;
				cout << "Valeur du capitaine : " << valeurCapitaine << endl;
				cout << "Valeur de l'equipage : " << valeurEquipage << endl;
				cout << "Nombre de manches : " << nombreManches << endl;

				pause(4);

				break;

			default :

				cout << "choixParametrerPartie est " << choixParametrerPartie << " au lieu de o/n" << endl;

				// en cas d'erreur de saisie, affectation des valeurs par defaut
				valeurBateau = 600;
				valeurCapitaine = 500;
				valeurEquipage = 400;
				nombreManches = 5;

				cout << "Les valeurs par defaut ont donc ete affectees : " << endl;
				cout << "Valeur du bateau : " << valeurBateau << endl;
				cout << "Valeur du capitaine : " << valeurCapitaine << endl;
				cout << "Valeur de l'equipage : " << valeurEquipage << endl;
				cout << "Nombre de manches : " << nombreManches << endl;

				pause(4);

				break;

			}

		effacer();

		// nomJoueur, valeurBateau, valeurCapitaine, valeurEquipage, nombreLancers >> jouerPartie >> scoreJoueur, scoreMachine

		cout << "Debut de la partie :\n" << endl;

		pause(1);

			// boucle pour jouer le nombre de manches defini
			for (numeroManche = 1; numeroManche <= nombreManches; numeroManche ++)
			{

				// nomJoueur, valeurBateau, valeurCapitaine, valeurEquipage, numeroManche, choixContinuerPartie, choixContinuerLancers,
				// NOMBRE_LANCERS, numeroLancer, equipement, nombreManches, NOM_MACHINE >> jouerMancheJoueur >> scoreJoueur
				
					// scoreJoueur, nomJoueur, scoreMachine, NOM_MACHINE >> afficherBilanPartiel >> (ecran)
					cout << "Bilan partiel avant la nouvelle manche : " << endl;
					cout << "Score " << nomJoueur << " : " << scoreJoueur << endl;
					cout << "Score " << NOM_MACHINE << " : " << scoreMachine << "\n" << endl;

					pause(1);

					// numeroManche, nomJoueur>> introduireNouvelleManche >> (ecran)
					cout << "Manche #" << numeroManche << ", " << nomJoueur << endl;

					// boucle pour jouer les 5 lancers
					while (true)
					{
						// vérifie si le joueur souhaite continuer les lancers
						if (choixContinuerLancers == 'n')
						{

							break;

						}

						// numeroLancer, equipement, scoreJoueur, nomJoueur >> jouerLancerJoueur >> scoreJoueur

							// numeroLancer >> introduireNouveauLancer >> (ecran)
							cout << "Lancer #" << numeroLancer << " : " << endl;

							// >> lancerDes >> deUn, deDeux, deTrois, deQuatre, deCinq
							deUn = static_cast<unsigned short int>(random(1, 6));
							deDeux = static_cast<unsigned short int>(random(1, 6));
							deTrois = static_cast<unsigned short int>(random(1, 6));
							deQuatre = static_cast<unsigned short int>(random(1, 6));
							deCinq = static_cast<unsigned short int>(random(1, 6));

							// deUn, deDeux, deTrois, deQuatre, deCinq >> afficherResultatLancer >> (ecran)
							cout << "Contenu du lancer : ";

							pause(1);
							
							cout << deUn;

							pause(1);

							cout << " " << deDeux;

							pause(1);

							cout << " " << deTrois;

							pause(1);

							cout << " " << deQuatre;

							pause(1);

							cout << " " << deCinq << endl;

							pause(1);

							// deUn, deDeux, deTrois, deQuatre, deCinq, equipement, scoreJoueur >> etablirBilanLancerJoueur >> scoreLancer, scoreJoueur, equipement

								// deUn, deDeux, deTrois, deQuatre, deCinq, equipement, scoreJoueur >> calculerEquipementJoueur >> equipement
								if (equipement == "NON_EQUIPE") {

									if (deUn == 6 || deDeux == 6 || deTrois == 6 || deQuatre == 6 || deCinq == 6) {

										equipement = "BATEAU"; // ajout du bateau à l'équipement

										scoreLancer += valeurBateau; // ajout de la valeur du bateau au score du lancer

										if (deUn == 5 || deDeux == 5 || deTrois == 5 || deQuatre == 5 || deCinq == 5) {

											equipement = "BATEAU_CAPITAINE"; // ajout du capitaine à l'équipement

											scoreLancer += valeurCapitaine; // ajout de la valeur du capitaine au score du lancer

											if (deUn == 4 || deDeux == 4 || deTrois == 4 || deQuatre == 4 || deCinq == 4) {

												equipement = "BATEAU_CAPITAINE_EQUIPAGE"; // ajout de l'équipage à l'équipement

												scoreLancer += valeurEquipage; // ajout de la valeur de l'équipage au score du lancer

											}

										}

									}

								}

								else {

									if (equipement == "BATEAU") {

										if (deUn == 5 || deDeux == 5 || deTrois == 5 || deQuatre == 5 || deCinq == 5) {

											equipement = "BATEAU_CAPITAINE"; // ajout du capitaine à l'équipement

											scoreJoueur += valeurCapitaine; // ajout de la valeur du capitaine au score du joueur

											if (deUn == 4 || deDeux == 4 || deTrois == 4 || deQuatre == 4 || deCinq == 4) {

												equipement = "BATEAU_CAPITAINE_EQUIPAGE"; // ajout de l'équipage à l'équipement

												scoreJoueur += valeurEquipage; // ajout de la valeur de l'équipage au score du joueur

											}

										}

									}

									else {

										if (equipement == "BATEAU_CAPITAINE") {

											if (deUn == 4 || deDeux == 4 || deTrois == 4 || deQuatre == 4 || deCinq == 4) {

												equipement = "BATEAU_CAPITAINE_EQUIPAGE";

												scoreJoueur += valeurEquipage;

											}

										}

									}

								}

								// >> calculerScoreLancer >> scoreLancer
								if (equipement == "BATEAU_CAPITAINE_EQUIPAGE") {

									scoreLancer += (deUn + deDeux + deTrois + deQuatre + deCinq); // ajout de la somme des dés au score du lancer

								}
								
								// scoreJoueur, scoreLancer >> calculerScoreJoueur >> scoreJoueur
								scoreJoueur += scoreLancer; // ajout du score du lancer du joueur à son score

							// scoreLancer, scoreJoueur, equipement >> afficherBilanLancerJoueur >> (ecran)
							cout << "Bilan du lancer : " << endl;
							cout << "\t-Equipement : " << equipement << endl;
							cout << "\t-Score du lancer : " << scoreLancer << endl;
							cout << "\t-Nouveau score pour " << nomJoueur << " : " << scoreJoueur << endl;

							// réinitialisation du score du lancer
							scoreLancer = 0;

							// vérifie si 3 lancers ont été effectués
							if (numeroLancer >= NOMBRE_LANCERS)
							{

								break;

							}

							numeroLancer = static_cast<unsigned short int>(numeroLancer+1); // incrément du numéro de lancer

						pause(1);

						// >> proposerContinuerLancer >> choixContinuerLancers
						cout << "Souhaitez-vous continuer les lancers (o/n) ? : ";
						cin >> choixContinuerLancers;

						cout << endl;

					}

					// reinitialisation de la variable equipement à la fin du tour du joueur
					equipement = "NON_EQUIPE";

					// reinitialisation de la variable numeroLancer à la fin du tour du joueur 
					numeroLancer = static_cast<unsigned short int>(1);

					// >> proposerContinuerPartie >> choixContinuerPartie
					cout << "Souhaitez-vous continuer la partie (o/n) ? : ";
					cin >> choixContinuerPartie;

				pause(1);
				effacer();

				// choixContinuerPartie >> verifierContinuerPartie >>
				if (choixContinuerPartie == 'n')
				{

					break;

				}

				// nomJoueur, valeurBateau, valeurCapitaine, valeurEquipage, numeroManche, NOMBRE_LANCERS, numeroLancer, equipement,
				// nombreManches, NOM_MACHINE >> jouerMancheMachine >> scoreMachine

					// scoreJoueur, nomJoueur, scoreMachine, NOM_MACHINE >> afficherBilanPartiel >> (ecran)
					cout << "Bilan partiel avant la nouvelle manche : " << endl;
					cout << "Score " << nomJoueur << " : " << scoreJoueur << endl;
					cout << "Score " << NOM_MACHINE << " : " << scoreMachine << "\n" << endl;

					pause(1);

					// numeroManche, NOM_MACHINE>> introduireNouvelleManche >> (ecran)
					cout << "Manche #" << numeroManche << ", " << NOM_MACHINE << endl;

					// boucle pour jouer les 5 lancers
					while (true)
					{

						// numeroLancer, equipement, scoreMachine, NOM_MACHINE >> jouerLancerMachine >> scoreMachine

							// numeroLancer >> introduireNouveauLancer >> (ecran)
							cout << "Lancer #" << numeroLancer << " : " << endl;

							// >> lancerDes >> deUn, deDeux, deTrois, deQuatre, deCinq
							deUn = static_cast<unsigned short int>(random(1, 6));
							deDeux = static_cast<unsigned short int>(random(1, 6));
							deTrois = static_cast<unsigned short int>(random(1, 6));
							deQuatre = static_cast<unsigned short int>(random(1, 6));
							deCinq = static_cast<unsigned short int>(random(1, 6));

							// deUn, deDeux, deTrois, deQuatre, deCinq >> afficherResultatLancer >> (ecran)
							cout << "Contenu du lancer : ";

							pause(1);

							cout << deUn;

							pause(1);

							cout << " " << deDeux;

							pause(1);

							cout << " " << deTrois;

							pause(1);

							cout << " " << deQuatre;

							pause(1);

							cout << " " << deCinq << endl;

							pause(1);

							// deUn, deDeux, deTrois, deQuatre, deCinq, equipement, scoreMachine >> etablirBilanLancerMachine >> scoreLancer, scoreMachine, equipement

								// deUn, deDeux, deTrois, deQuatre, deCinq, equipement, scoreMachine >> calculerEquipementMachine >> equipement
							if (equipement == "NON_EQUIPE") {

								if (deUn == 6 || deDeux == 6 || deTrois == 6 || deQuatre == 6 || deCinq == 6) {

									equipement = "BATEAU"; // ajout du bateau à l'équipement

									scoreLancer += valeurBateau; // ajout de la valeur du bateau au score du lancer

									if (deUn == 5 || deDeux == 5 || deTrois == 5 || deQuatre == 5 || deCinq == 5) {

										equipement = "BATEAU_CAPITAINE"; // ajout du capitaine à l'équipement

										scoreLancer += valeurCapitaine; // ajout de la valeur du capitaine au score du lancer

										if (deUn == 4 || deDeux == 4 || deTrois == 4 || deQuatre == 4 || deCinq == 4) {

											equipement = "BATEAU_CAPITAINE_EQUIPAGE"; // ajout de l'équipage à l'équipement

											scoreLancer += valeurEquipage; // ajout de la valeur de l'équipage au score du lancer

										}

									}

								}

							}

							else {

								if (equipement == "BATEAU") {

									if (deUn == 5 || deDeux == 5 || deTrois == 5 || deQuatre == 5 || deCinq == 5) {

										equipement = "BATEAU_CAPITAINE"; // ajout du capitaine à l'équipement

										scoreMachine += valeurCapitaine; // ajout de la valeur du capitaine au score de la machine

										if (deUn == 4 || deDeux == 4 || deTrois == 4 || deQuatre == 4 || deCinq == 4) {

											equipement = "BATEAU_CAPITAINE_EQUIPAGE"; // ajout de l'équipage à l'équipement

											scoreMachine += valeurEquipage; // ajout de la valeur de l'équipage au score de la machine

										}

									}

								}

								else {

									if (equipement == "BATEAU_CAPITAINE") {

										if (deUn == 4 || deDeux == 4 || deTrois == 4 || deQuatre == 4 || deCinq == 4) {

											equipement = "BATEAU_CAPITAINE_EQUIPAGE";

											scoreMachine += valeurEquipage;

										}

									}

								}

						}

						// >> calculerScoreLancer >> scoreLancer
						if (equipement == "BATEAU_CAPITAINE_EQUIPAGE") {

							scoreLancer += (deUn + deDeux + deTrois + deQuatre + deCinq); // ajout de la somme des dés au score du lancer

						}

						// scoreMachine, scoreLancer >> calculerScoreMachine >> scoreMachine
						scoreMachine += scoreLancer; // ajout du score du lancer du machine à son score

						// scoreLancer, scoreJoueur, equipement >> afficherBilanLancerJoueur >> (ecran)
						cout << "Bilan du lancer : " << endl;
						cout << "\t-Equipement : " << equipement << endl;
						cout << "\t-Score du lancer : " << scoreLancer << endl;
						cout << "\t-Nouveau score pour " << NOM_MACHINE << " : " << scoreMachine << endl;

						pause(1);

						// réinitialisation du score du lancer
						scoreLancer = 0;

						// vérifie si 3 lancers ont été effectués
						if (numeroLancer >= NOMBRE_LANCERS)
						{

							break;

						}

						numeroLancer = static_cast<unsigned short int>(numeroLancer+1); // incrément du numéro de lancer

						cout << endl;

					}

					// reinitialisation de la variable equipement à la fin du tour de la machine
					equipement = "NON_EQUIPE";

					// reinitialisation de la variable numeroLancer à la fin du tour de la machine
					numeroLancer = static_cast<unsigned short int>(1);

				pause(1);

				// >> proposerContinuerPartie >> choixContinuerPartie
				cout << "Souhaitez-vous continuer la partie (o/n) ? : ";
				cin >> choixContinuerPartie;

			pause(2);
			effacer();

				// choixContinuerPartie >> verifierContinuerPartie >>
				if (choixContinuerPartie == 'n')
				{

					break;

				}
				else {

					choixContinuerLancers = 'o';

				}

			}

		// scoreJoueur, scoreMachine, nomJoueur >> finaliserPartie >> 

			// scoreJoueur, scoreMachine, nomJoueur >> determinerVainqueurPartie >> etatEgalite,
			// nomVainqueur, scoreVainqueur, nomPerdant, scorePerdant, [scoreEgalite]
			if (choixContinuerPartie == 'n')
			{

				nomVainqueur = NOM_MACHINE;
				scoreVainqueur = scoreMachine;

				nomPerdant = nomJoueur;
				scorePerdant = scoreJoueur;

			}
			else {

				if (scoreJoueur > scoreMachine)
				{

					nomVainqueur = nomJoueur;
					scoreVainqueur = scoreJoueur;

					nomPerdant = NOM_MACHINE;
					scorePerdant = scoreMachine;

				}
				else if (scoreMachine > scoreJoueur)
				{

					nomVainqueur = NOM_MACHINE;
					scoreVainqueur = scoreMachine;

					nomPerdant = nomJoueur;
					scorePerdant = scoreJoueur;

				}
				else {

					scoreEgalite = scoreJoueur;

					etatEgalite = true;

				}

			}

			// nomVainqueur, scoreVainqueur, nomPerdant, scorePerdant, [scoreEgalite] >> afficherVainqueur >> (ecran)
			cout << "Resultats de la partie :\n" << endl;

			pause(2);
			
			if (choixContinuerPartie == 'n')
			{

				cout << nomVainqueur << " a gagne la partie par abandon de " << nomPerdant << endl;

			}
			else {

				if (etatEgalite == true)
				{

					cout << "Les deux joueurs sont a egalite a " << scoreEgalite << " points" << endl;

				}
				else {

					if (scoreVainqueur == scoreJoueur)
					{

						cout << "Bravo " << nomVainqueur << ", votre score : " << scoreVainqueur << " > au score de " << nomPerdant << " : " << scorePerdant << endl;

					}
					else {

						cout << "Dommage " << nomPerdant << ", votre score : " << scorePerdant << " < au score de " << nomVainqueur << " : " << scoreVainqueur << endl;

					}

				}

			}

			pause(5);
			
	return 0;
   
}
