#include "Plateau.h"
#include "vue.h"
#include "controleur.h"
#include <iostream>
//#include <unistd.h>

using namespace std;
 
int main(){
const int case_width=130;
const int case_height=130;
Jeu j;
SDL_Window*window = NULL; 
SDL_Renderer * renderer = NULL;  
SDL_Texture* images[26];
bool quit;
SDL_Event event;
SDL_Rect rect_de;
rect_de.x=6*case_width +20;
rect_de.y=0;
rect_de.h=case_height;
rect_de.w=case_width;
unsigned int valde;
SDL_Color rouge={255,0,0};
SDL_Color bleu={0,0,255};
SDL_Color vert={0,255,0};
SDL_Color blanc={255,255,255};
int indice_tabpropriete0=0;
int indice_tabpropriete1=0;
bool tour_prochain=true;
bool propriete_achete=false;
 

window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1100,900,SDL_WINDOW_SHOWN);
renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

charger_images(renderer,images);


if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

while (!quit){
    int jouertour;
    bool bouton_y_n=false;
    bool bouton_y=false;
    dessiner_plateau(renderer,images);
    afficher_joueur (renderer,images,j.getJoueurs(0), j.getJoueurs(1));
    afficher_info(renderer, j.getJoueurs(0),800, 150,rouge);
    afficher_info(renderer, j.getJoueurs(1),800, 300,bleu);

      
    
    //charger_questions(renderer,1,blanc);
           
    afficher_val_de( renderer,valde,800, 465, blanc);
    
    valde=0;    

    while (SDL_PollEvent(&event)){
        if (event.type==SDL_QUIT){
            quit=true;
        }   
        if (event.type == SDL_MOUSEBUTTONDOWN && tour_prochain==true){
            valde=clic(event,j,rect_de);
            tour_prochain=false;                 
        }

        if (event.type==SDL_KEYDOWN){
           
            SDL_Keycode keyCode = event.key.keysym.sym;
            if (keyCode == SDLK_y ){
                   bouton_y_n=true;              
                   bouton_y=true;
                   cout<< "on a appuye sur y"<<endl;            
                                }
                else if(keyCode == SDLK_n){
                    bouton_y_n=true;              
                    bouton_y=false; 
                    cout<< "on a appuye sur n"<<endl;
                }
               
               
            

        
       
        }
    }

    if(valde>0){
                cout<<"le joueur act dans la boucle valde est: "<<j.getJoueurActuel()<<endl;
                j.bouge(valde);
                valde=0;
               // afficher_joueur (renderer,images,j.getJoueurs(0), j.getJoueurs(1));
                
                
               jouertour=j.joue_tour(renderer,blanc,event,propriete_achete);           
               cout<<"JAFFICHEEEE"<<endl;
               int pos_pion=j.getJoueurs(j.getJoueurActuel()).getPosition();    
               if(pos_pion==8||pos_pion==15||pos_pion==1||pos_pion==10||pos_pion==16||pos_pion==19||pos_pion==5||pos_pion==9||pos_pion==14||pos_pion==0)     
                    {
                        tour_prochain=j.tour_suivant();
                         
                     }

    }
               int joueur_act=j.getJoueurActuel();
               int pos_actuelle=j.getJoueurs(joueur_act).getPosition();
               if(pos_actuelle==2||pos_actuelle==3||pos_actuelle==4||pos_actuelle==6||pos_actuelle==7||pos_actuelle==11||pos_actuelle==12||pos_actuelle==13||pos_actuelle==17||pos_actuelle==18){
                if(bouton_y_n == false && jouertour==1 ){
                    charger_questions(renderer,1,blanc);
                    //sleep(10);
                    //cout<<"je suis dans charger question"<<endl;
                } 

                if(bouton_y_n == false && jouertour==2 ){
                     charger_questions(renderer,0,blanc);
                     //sleep(10);
                    //cout<<"je suis dans charger question"<<endl;
                 }

                if(bouton_y_n == true && bouton_y ==true){
                    
                    if(joueur_act==0){
                        propriete_achete=true;
                        j.joue_tour(renderer,blanc,event,propriete_achete);
                        //elle ajoute la casepropriete dans le tableau de proprietes du joueur
                       // CasePropriete* caseProp= dynamic_cast<CasePropriete*>(j.getPlateau().getCase(pos_actuelle));
                       //j.getPlateau().getCase(pos_actuelle).set_proprio(joueur_act);
                      // cout<<"le proprio de ce terrain estg"<<j.getPlateau().getCase(pos_actuelle).get_proprio()<<endl;
                       // caseProp.set_proprio(joueur_act);
                        //j.getPlateau().getCase(pos_actuelle).set_proprio(joueur_act);
                        cout<< "le tour prochain est "<<tour_prochain<<endl;
                        cout<< "la case propriete de joueur 0 qu'il vient acheter est : "<<endl;//j.getJoueurs(j.getJoueurActuel()).get_tab_propriete(indice_tabpropriete0).get_loyer()<<endl;
                        indice_tabpropriete0++;
                        cout<< "le joueur actuel est "<<j.getJoueurActuel()<<endl;
                        tour_prochain=j.tour_suivant();
                        cout<< "le joueur actuel (apres tour_suivant est "<<j.getJoueurActuel()<<endl;
                        bouton_y_n=false;              
                        bouton_y=false; 
        
                        
                    }

                    if(joueur_act==1){
                        propriete_achete=true;
                        j.joue_tour(renderer,blanc,event,propriete_achete);
                        //elle ajoute la casepropriete dans le tableau de proprietes du joueur
                        //j.getJoueurs(joueur_act).set_tab_propriete(indice_tabpropriete1,j.getJoueurs(joueur_act).get_tab_propriete(indice_tabpropriete1));
                        cout<< "la case propriete de joueur 1 qu'il vient acheter est : "<<endl;//j.getJoueurs(j.getJoueurActuel()).get_tab_propriete(indice_tabpropriete1).get_loyer()<<endl;
                        cout<< "le tour prochain est "<<tour_prochain<<endl;
                        indice_tabpropriete1++;
                        cout<< "le joueur actuel est "<<j.getJoueurActuel()<<endl;
                        tour_prochain=j.tour_suivant();
                        cout<< "le joueur actuel (apres tour_suivant) est "<<j.getJoueurActuel()<<endl;
                        bouton_y_n=false;              
                        bouton_y=false;
                    }
                 }
                 if(bouton_y_n == true && bouton_y ==false){
                    tour_prochain=j.tour_suivant();
                    bouton_y_n=false;              
                    bouton_y=false;

                 }  
                }

                
           
   /* if(bouton_y_n == false && jouertour==1 ){
        charger_questions(renderer,1,blanc);
        //sleep(10);
        cout<<"je suis dans charger question"<<endl;
    } 

    if(bouton_y_n == false && jouertour==2 ){
        charger_questions(renderer,0,blanc);
                     //sleep(10);
                    //cout<<"je suis dans charger question"<<endl;
    }*/

    appel_questions(renderer,bouton_y_n,jouertour);
    
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

          
         
  } 
    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}