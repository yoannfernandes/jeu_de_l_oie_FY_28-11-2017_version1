
                                        {Algorithme: Jeu de l'oie

BUT:
ENTREE:
SORTIE:

CONST:
  arriver<-66:ENTIER
  crâne<-58: ENTIER

VAR:
  place,lancer_dés:entier


DEBUT:
 
  REPETER                                                               //Boucle pour fin de partie/arriver case 66
	 ECRIRE 'Veuillez lancer les dés'            
     LIRE lancer_dés                                                    //On recupere les valeurs des dés

 	 TANTQUE ((lancer_dés<2) OU (lancer_dés>12)                         //On verifie que les valeurs sont possible
           ECRIRE 'votre saisie n'est pas valide, veuillez recommence'
           LIRE lancer_des
     JUSQU'A ((lancer_dés<2) OU (lancer_dés>12)

	 FINTANTQUE

     place<- place+lancer_dés                                           //On place le joueur sur sa case

     ECRIRE"vous êtes sur la case: ",place

     SI (place>arriver)                                                 //Le SI permet de gerer les jet de dés superieur a 66, c'est le recule
         place<-arriver-(place-arriver)
         ECRIRE place

     SI (place=crâne)							                        //Le SI permet de gerer la case crâne 	
   	     place<-0
   	     ECRIRE"Pas de chance, vous êtes tomber sur la case crâne, retour à la case départ"
   	     ECRIRE place

     SI (place MOD 9=0) ET (place<>63) ET (place<>58)                                                //Le SI permet de gerer les cases "oie"
         ECRIRE"Bravo, vous êtes sur une case oie, votre déplacement est doublé"place<-place+lancer_dés
         place<-place+lancer_dés
         ECRIRE place	 	

  JUSQU'A place=arriver
 ECRIRE"Vous avez gagné, bien joué"
FIN}

program jeux_de_l_oie;

uses crt;

CONST
  arriver=66;
  crane=58;

VAR
  place,lancer_des:integer;



Begin
 clrscr;

 Repeat                                                                             //Boucle pour fin de partie/arriver case 66
 writeln('Veuillez lancer les des');                                                //On recupere les valeurs des dés
 readln (lancer_des);
 	begin
   		while ((lancer_des<2) OR (lancer_des>12)) DO                                //On verifie que les valeurs sont possible
      		Begin
    	    	writeln('votre saisie n est pas valide, veuillez recommencer');
    	    	readln (lancer_des);
       		end;	

   	 place:= place+lancer_des;                                                      //On place le joueur sur sa case

     writeln('Vous etes sur la case:',place);

  	 If (place>arriver) THEN                                                        //Le If permet de gerer les jet de dés superieur a 66, c'est le recule
   			begin
   				place:= arriver-(place-arriver);
   				writeln(place);
   			end;

  	 If (place=crane) THEN                                                          //Le If permet de gerer la case crâne
   			begin
        		place:= 0;
        		writeln('Pas de chance, vous etes tomber sur la case crane, retour a la case depart');
        		writeln(place);
       		end;	

   	 If ((place MOD 9=0) AND (place<>63) AND (place<>58))THEN
   			begin
       			writeln('Bravo, vous etes sur une case oie, votre deplacement est double');
        		place:= place+lancer_des;
        		writeln(place);
        	end;
    end;    	
 until place=arriver;

 writeln('Vous avez gagner, bien jouer');
 readln;
END.



