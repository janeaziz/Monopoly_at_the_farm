#include <sstream>
#include <iostream>
#include "vue.h"

using namespace std;

void charger_images(SDL_Renderer* renderer, SDL_Texture* images[]) {
    // Tableau contenant le nom de fichier pour chaque type de case
    const char* images_filenames[11] = {
        "data/CasePropriete.png", 
        "data/CaseRessources.png", 
        "data/CaseEnigme.png", 
        "data/CaseArgent.png",
        "data/CaseDepart.png", // On ajoute une image pour la case départ
        "data/de.png",
        "data/photocentre.png",
        "data/pageaccueil.png",
        "data/boutonstart.png",
        "data/Joueur1.png",
        "data/Joueur2.png"

    };

    for (int i = 0; i < 26; i++) {
        // Charger l'image correspondante au type de case de la case i
        if (i == 0) {
            // Case départ
            images[i] = IMG_LoadTexture(renderer, images_filenames[4]);
        } else if (i == 2 || i == 3 ||i == 4 || i == 6 ||i == 7 || i == 11 ||i == 12 ||
         i == 13 ||i == 17 || i == 18) {
            // Cases de type CasePropriete
            images[i] = IMG_LoadTexture(renderer, images_filenames[0]);
        } else if (i == 8 || i== 15) {
            // Case de type CaseEnigme
            images[i] = IMG_LoadTexture(renderer, images_filenames[2]);
        } else if (i == 1 || i== 10 || i == 16 || i== 19){
            // Case de type CaseArgent
            images[i] = IMG_LoadTexture(renderer, images_filenames[3]);
        } else if (i == 5 || i== 9 || i == 14){
            //Case de type Ressources
            images[i] = IMG_LoadTexture(renderer, images_filenames[1]);
        } else if (i ==  20){
            //le de
            images[i] = IMG_LoadTexture(renderer, images_filenames[5]);
        } else if (i ==  21){
            //photo du centre du plateau
            images[i] = IMG_LoadTexture(renderer, images_filenames[6]);
        } else if (i ==  22){
            //photo de la page d'accueil
            images[i] = IMG_LoadTexture(renderer, images_filenames[7]);
        } else if (i ==  23){
            //Bouton Start
            images[i] = IMG_LoadTexture(renderer, images_filenames[8]);
        } else if (i == 24){
            images[i] = IMG_LoadTexture(renderer, images_filenames[9]);
        } else if (i == 25){
            images[i] = IMG_LoadTexture(renderer, images_filenames[10]);
        }


        if(images[i]){
            cout<< "l'image " <<i << "n'a pas ete charge"<<endl;
        }
        
    }

    
}


void dessiner_plateau(SDL_Renderer* renderer, SDL_Texture* images[]) {
    // Dessin du plateau en utilisant les images des cases
    
    SDL_Rect Rect;
 //j.tour_suivant();
    const int case_width=130;
    const int case_height=130;


    for (int i= 0; i< 21; i++) {

        if (i==20) {  // pour le de
            Rect.x = 6* case_width + 20;
            Rect.y = 0;
        }

        else if (i==6 || i == 7 || i == 8 || i == 9){
           Rect.x = 5 * case_width; 
           if (i==6) Rect.y= case_height;
           if (i==7) Rect.y= 2*case_height;
           if (i==8) Rect.y= 3*case_height;
           if (i==9) Rect.y= 4*case_height;
        }
        else if(i==16 || i == 17 || i == 18 || i == 19){
            Rect.x = 0;
            if (i==16) Rect.y= 4*case_height;
            if (i==17) Rect.y= 3*case_height;
            if (i==18) Rect.y= 2*case_height;
            if (i==19) Rect.y= case_height;
        }
        else { 
            
            

            if(i<16 && i>9){
                if(i==15) Rect.x= 0;
                if(i==14) Rect.x= 1*case_width;
                if(i==13) Rect.x= 2*case_width;
                if(i==12) Rect.x= 3*case_width;
                if(i==11) Rect.x= 4*case_width;
                if(i==10) Rect.x= 5*case_width; 
                Rect.y = 5 * case_height;
            }

            else { 
                Rect.x = i%6 * case_width;
                Rect.y = 0;
            }    
        }
        Rect.w = case_width;
        Rect.h = case_height;
        SDL_RenderCopyEx(renderer, images[i], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
        
        Rect.x=case_width;
        Rect.y=case_height;
        Rect.w=4*case_width;
        Rect.h=4*case_height;
        SDL_RenderCopyEx(renderer, images[21], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
    }
    
    
    
}


void afficher_joueur(SDL_Renderer* renderer,SDL_Texture* images[],Joueur p1, Joueur p2){
    SDL_Rect Rect;

    const int case_width=130;
    const int case_height=130;
    Rect.w = 50;
    Rect.h = 50;

    if (p1.getPosition()==6 || p1.getPosition() == 7 || p1.getPosition() == 8 || p1.getPosition() == 9){
           Rect.x = 5 * case_width; 
           if (p1.getPosition()==6) Rect.y= case_height;
           if (p1.getPosition()==7) Rect.y= 2*case_height;
           if (p1.getPosition()==8) Rect.y= 3*case_height;
           if (p1.getPosition()==9) Rect.y= 4*case_height;
        }
        else if(p1.getPosition()==16 || p1.getPosition() == 17 || p1.getPosition() == 18 || p1.getPosition() == 19){
            Rect.x = 0;
            if (p1.getPosition()==16) Rect.y= 4*case_height;
            if (p1.getPosition()==17) Rect.y= 3*case_height;
            if (p1.getPosition()==18) Rect.y= 2*case_height;
            if (p1.getPosition()==19) Rect.y= case_height;
        }
            else if(p1.getPosition()<16 && p1.getPosition()>9){ 
            
            

            
                if(p1.getPosition()==15) Rect.x= 0;
                if(p1.getPosition()==14) Rect.x= 1*case_width;
                if(p1.getPosition()==13) Rect.x= 2*case_width;
                if(p1.getPosition()==12) Rect.x= 3*case_width;
                if(p1.getPosition()==11) Rect.x= 4*case_width;
                if(p1.getPosition()==10) Rect.x= 5*case_width; 
                Rect.y = 5 * case_height;
            }

                else if(p1.getPosition()<6 && p1.getPosition()>=0){ 
                    Rect.x = p1.getPosition() %6 * case_width;
                    Rect.y = 0;
                }
    SDL_RenderCopyEx(renderer, images[24], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);

    const int height_j2=70;
    const int width_j2=70;

    if (p2.getPosition()==6 || p2.getPosition() == 7 || p2.getPosition() == 8 || p2.getPosition() == 9){  // pour le Joueur 2
           Rect.x = 5 * case_width; 
           if (p2.getPosition()==6) Rect.y= case_height+height_j2;
           if (p2.getPosition()==7) Rect.y= 2*case_height+height_j2;
           if (p2.getPosition()==8) Rect.y= 3*case_height+height_j2;
           if (p2.getPosition()==9) Rect.y= 4*case_height+height_j2;
        }
        else if(p2.getPosition()==16 || p2.getPosition() == 17 || p2.getPosition() == 18 || p2.getPosition() == 19){
            Rect.x = 0;
            if (p2.getPosition()==16) Rect.y= 4*case_height+height_j2;
            if (p2.getPosition()==17) Rect.y= 3*case_height+height_j2;
            if (p2.getPosition()==18) Rect.y= 2*case_height+height_j2;
            if (p2.getPosition()==19) Rect.y= case_height+height_j2;
        }
            else if(p2.getPosition()<16 && p2.getPosition()>9){ 
            
            

            
                if(p2.getPosition()==15) Rect.x= 0;
                if(p2.getPosition()==14) Rect.x= 1*case_width + width_j2;
                if(p2.getPosition()==13) Rect.x= 2*case_width + width_j2;
                if(p2.getPosition()==12) Rect.x= 3*case_width + width_j2;
                if(p2.getPosition()==11) Rect.x= 4*case_width + width_j2;
                if(p2.getPosition()==10) Rect.x= 5*case_width + width_j2; 
                Rect.y = 5 * case_height+width_j2;
            }

                else if(p2.getPosition()<6 && p2.getPosition()>=0){ 
                    Rect.x = p2.getPosition() %6 * case_width + width_j2;
                    Rect.y = 0;
                }            

    SDL_RenderCopyEx(renderer, images[25], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
   
                
}
    
/*void afficher_texte(SDL_Renderer* renderer, int x, int y)
{    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    int i=5;
    std::string texte = "Joueur " + std::to_string(i) + " /n argent:";
    SDL_Color couleur = { 255, 255, 255, 255 };
    TTF_Font* font = TTF_OpenFont("data/DejaVuSansCondensed.ttf", 20);
    if (!font) {
        std::cerr << "Erreur lors de l'ouverture de la police : " << TTF_GetError() << std::endl;
        return;
    }

    std::stringstream ss(texte);
    std::string ligne;
    int ligne_y = y;
    while (std::getline(ss, ligne, '\n')) {
        SDL_Surface* surface_texte = TTF_RenderText_Solid(font, ligne.c_str(), couleur);
        SDL_Texture* texture_texte = SDL_CreateTextureFromSurface(renderer, surface_texte);

        SDL_Rect rect_texte = { x, ligne_y, surface_texte->w, surface_texte->h };
        SDL_RenderCopy(renderer, texture_texte, nullptr, &rect_texte);

        SDL_FreeSurface(surface_texte);
        SDL_DestroyTexture(texture_texte);

        ligne_y += surface_texte->h;
    }

    TTF_CloseFont(font);
}
*/

void afficher_info(SDL_Renderer * renderer,Joueur j,int x, int y,SDL_Color c){
    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    TTF_Font* font=TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if(font==NULL){
        std::cerr<<"Erreur lors du chargement de la police "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    unsigned int id= j.getid();
    unsigned int money=j.getArgent();
    int soleil=j.getSoleil();
    int eau=j.getEau();
    int arbres=j.get_nbarbre();
    int jardins=j.get_nbjardin();

    std::string message[7];
    message[0] ="Joueur " + std::to_string(id);
    message[1] ="argent: " + std::to_string(money);
    message[2] ="eau: " + std::to_string(eau);
    message[3] ="soleil: " + std::to_string(soleil);
    message[4] ="nb arbres: " + std::to_string(arbres);
    message[5] ="nb jardins: " + std::to_string(jardins);

    //SDL_Color couleur={255,0,0};
    for(int i=0;i<6;i++){
    SDL_Surface* surface=TTF_RenderText_Blended(font,message[i].c_str(),c);


    if(surface==NULL){
        std::cerr<<"Erreur lors de la creation de la surface "<<i<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);


    }

    SDL_Texture* texture= SDL_CreateTextureFromSurface(renderer,surface);
    if(texture==NULL){
        std::cerr<<"Erreur lors de la creation de la texture"<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Rect posfont={x,y,surface->w,surface->h};
    SDL_RenderCopy(renderer,texture,NULL,&posfont);
    y+=20;
    

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    }
    TTF_CloseFont(font);
    TTF_Quit();

    
 }


void afficher_val_de(SDL_Renderer * renderer,unsigned int val_de,int x, int y,SDL_Color c){
    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    TTF_Font* font=TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if(font==NULL){
        std::cerr<<"Erreur lors du chargement de la police "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    std::string message ="La valeur du de est: " + std::to_string(val_de);

    SDL_Surface* surface=TTF_RenderText_Blended(font,message.c_str(),c);


    if(surface==NULL){
        std::cerr<<"Erreur lors de la creation de la surface "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);


    }

    SDL_Texture* texture= SDL_CreateTextureFromSurface(renderer,surface);
    if(texture==NULL){
        std::cerr<<"Erreur lors de la creation de la texture"<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Rect posfont={x,y,surface->w,surface->h};
    SDL_RenderCopy(renderer,texture,NULL,&posfont);
    
    

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    
    TTF_CloseFont(font);
    TTF_Quit();

    
}

void charger_questions(SDL_Renderer* renderer,unsigned int indice,SDL_Color c){
    
    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    TTF_Font* font=TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if(font==NULL){
        std::cerr<<"Erreur lors du chargement de la police "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    
    std::string questions[21];
        
    questions[0]="Voulez-vous acheter ce terrain?";
    questions[1]="Voulez-vous planter un arbre?";// Cliquez sur Y pour oui et N pour non.";
    questions[2]="Voulez-vous planter un jardin?";
    questions[3]="Vous avez perdu 200 euros!";
    questions[4]="Vous avez gagne 200 euros!";
    questions[5]="Vous avez perdu 2 unites d'eau et de soleil!";
    questions[6]="Vous avez gagne 2 unites d'eau et de soleil!";
    questions[7]="Vous avez gagne 1 unitee d'eau et de soleil et votre adversaire en a perdue.";
    questions[8]="Vous avez gagne 2 unitees d'eau et de soleil et votre adversaire en a perdues.";
    questions[9]="Vous avez gagne 3 unitees d'eau et de soleil et votre adversaire en a perdues.";
    questions[10]="Pas de changements.";
    questions[11]="Vous avez perdu 1 unitee d'eau et de soleil et votre adversaire en a gagnee.";
    questions[12]="Vous avez perdu 2 unitees d'eau et de soleil et votre adversaire en a gagnees.";
    questions[13]="Vous avez perdu 3 unitees d'eau et de soleil et votre adversaire en a gagnees.";
    questions[14]="Vous avez bien achete le terrain.";
    questions[15]="Vous avez bien achete l'arbre";
    questions[16]="Vous avez bien achete le jardin";
    questions[17]="Vous avez paye les taxes de passage";
    questions[18]="Vous n'avez pas achete le terrain.";
    questions[19]="Vous n'avez pas achete l'arbre";
    questions[20]="Vous n'avez pas achete le jardin";


   
    SDL_Surface* surface=TTF_RenderText_Blended(font,questions[indice].c_str(),c);
    


    if(surface==NULL){
        std::cerr<<"Erreur lors de la creation de la surface "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);

    
    }

    SDL_Texture* texture= SDL_CreateTextureFromSurface(renderer,surface);
    if(texture==NULL){
        std::cerr<<"Erreur lors de la creation de la texture"<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Rect posfont={100,820,surface->w,surface->h};
    
   
    SDL_RenderCopy(renderer,texture,NULL,&posfont);
    

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    
    TTF_CloseFont(font);
    TTF_Quit();


}

void appel_questions(SDL_Renderer* renderer,bool bouton_y_n, int question){

    SDL_Color rouge={255,0,0};
    SDL_Color bleu={0,0,255};
    SDL_Color vert={0,255,0};
    SDL_Color blanc={255,255,255};
    if(bouton_y_n == false && question==1 ){
        charger_questions(renderer,1,blanc);
        //sleep(10);
        cout<<"je suis dans charger question"<<endl;
    } 

    if(bouton_y_n == false && question==2 ){
        charger_questions(renderer,0,blanc);
                     //sleep(10);
                    //cout<<"je suis dans charger question"<<endl;
    }

    if(question==3){
        charger_questions(renderer,3,rouge);
    }
    
    if(question==4){
        charger_questions(renderer,4,vert);
    }

    if(question==5){
        charger_questions(renderer,5,rouge);
    }
    
    if(question==6){
        charger_questions(renderer,6,vert);
    }

    if(question==7){
        charger_questions(renderer,7,vert);
    }

    if(question==8){
        charger_questions(renderer,8,vert);
    }

    if(question==9){
        charger_questions(renderer,9,vert);
    }

    if(question==10){
        charger_questions(renderer,10,blanc);
    }

    if(question==11){
        charger_questions(renderer,11,rouge);
    }

    if(question==12){
        charger_questions(renderer,12,rouge);
    }

    if(question==13){
        charger_questions(renderer,13,rouge);
    }

    if(question==14){
        charger_questions(renderer,14,vert);
    }

    if(question==15){
        charger_questions(renderer,15,vert);
    }

    if(question==16){
        charger_questions(renderer,16,vert);
    }

    if(question==17){
        charger_questions(renderer,17,rouge);
    }

    if(question==18){
        charger_questions(renderer,18,rouge);
    }

    if(question==19){
        charger_questions(renderer,19,rouge);
    }

    if(question==20){
        charger_questions(renderer,20,rouge);
    }
}

